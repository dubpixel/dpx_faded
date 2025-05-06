// Last update: 2021-09-29 20:00:00+00:00
//FADER_X DPX FORK
//todo:
/* 
  -migrate setting of static IP to some alternate file or include - 
  --otherwise, to set static IP even after re-setting to factory 'static' reset -  line 152 reset.ino is where that can be changed for now
 -add some check for DPX_motherboard version

++changelog 1.3.2
  ** fixed issue with DHCP not reporting actual DHCP address
  ++ added workaround for the fact i mis pinned out the DHCP button
  ++ added some debug prints to help with debugging

  **need to start writing some documentation. 
    -IP mode can be set while running. push and hold the button for 5 seconds and the information will echo to the serial monitor.
    -default static IP is 192.168.1.130
*/
#include <QNEthernet.h>
#include <EEPROM.h>
#include "Net.h"
#include "Fader.h"
#include "MIDI.h"
#include "QLab.h"
#include "Eos.h"
#include "X32.h"
#include "DiGiCo.h"
#include <Bounce2.h>
using namespace qindesign::network;

#define MAJOR 1
#define SUBVERSION 3
#define PATCH 2
#define DHCP_BUTTON 41 //dpx_faded_4 0.5.5. mistakenly used 41 instead of 40 , set this to 40 for normal operation
#define STATIC_BUTTON 33 //this button works fine on both versions

EthernetServer globalWebServer{80};
EthernetUDP globalUDP;
Bounce button1 = Bounce();
Bounce button2 = Bounce();

Net net;
Midi midi;
QLab qlab;
Eos eos;
X32 x32;
DiGiCo digico;

Fader fader1(A9, 0);
Fader fader2(A8, 1);
Fader fader3(A7, 2);
Fader fader4(A6, 3);
Fader fader5(A5, 4);
Fader fader6(A4, 5);
Fader fader7(A3, 6);
Fader fader8(A2, 7);

byte globalMode = 1;
boolean globalRotated = false;
int globalFaderTargets[255];
byte globalFaderChannels[32];
byte globalPage = 0;
byte globalTouchSensitivity = 128;
unsigned short globalMessageWaitMillis = 33;
int globalMotorMinSpeed = 150;
int globalMotorSpeedScale = 8;
unsigned short globalMotorFrequency = 250;
byte globalMotherboardRevision;
boolean globalNewSettingsFlag = true;
long globalLastBoot = 0;
boolean globalFirstBoot = true;
byte globalMIDIPageControl = 1;
byte globalMIDIPageChannel = 1;
byte globalOSCPageControl = 1;
long lastButton1Press = 0;
long lastButton2Press = 0;
long lastSerialLog = -10000;
char sessionToken[4];
byte versionMajor;
byte versionMinor;
byte versionSub;

char serialBuf[16];
byte serialIndex = 0;

Encoder encoders[8];

#define OP_Midi 1
#define OP_Midi_NoMotor 2
#define OP_QLab 3
#define OP_Eos 6
#define OP_DiGiCo 7
#define OP_X32 8
#define OP_XAIR 9
#define OP_Dance 10

void setup() {
  Serial.begin(115200);
  if(EEPROM.read(21)>=3){
    Serial8.begin(31250);
  }
  
  delay(100);
  Serial.println("Powered On");

  if(EEPROM.read(0)!='F' || EEPROM.read(8)!=MAJOR || EEPROM.read(9)!=SUBVERSION){
    Serial.println("Factory Reset");
    factoryReset();
  }
  EEPROM.write(10, PATCH);

  pinMode(STATIC_BUTTON, INPUT_PULLUP);
  button1.attach(STATIC_BUTTON);
  button1.interval(1);

  if(EEPROM.read(21)>=3){
    pinMode(DHCP_BUTTON, INPUT_PULLUP);
    button2.attach(DHCP_BUTTON);
    button2.interval(50);
   // Serial.println("read21>=3");;
  
  }else{
    pinMode(41, INPUT_PULLUP);
    button2.attach(25);
    button2.interval(50);
   // Serial.println("else");
  }
  
  analogReadResolution(11);

  for(byte i=0; i<8; i++){
    encoders[i].channel = i+1;
    encoders[i].realIndex = i;
  }

  usbMIDI.setHandleProgramChange(midiPCHandle);
}
int lastLoop = 0;
void loop() {
  if(globalNewSettingsFlag){
    globalNewSettingsFlag = false;
    newSettings();
  }

  net.loop();

  if(globalMode==OP_Midi){
    midi.loop();
     
  }else if(globalMode==OP_QLab){
    qlab.loop();
    
  }else if(globalMode==OP_Eos){
    eos.loop();

  }else if(globalMode==OP_X32 || globalMode==OP_XAIR){
    x32.loop();

  }else if(globalMode==OP_DiGiCo){
    digico.loop();
    
  }else if(globalMode>=OP_Dance){
    danceLoop();
    
  }

  lastLoop = millis();

  fader1.loop();
  fader2.loop();
  fader3.loop();
  fader4.loop();
  fader5.loop();
  fader6.loop();
  fader7.loop();
  fader8.loop();

  if(millis()-lastLoop>4){
    Serial.print("Code hung for ");
    Serial.print(millis()-lastLoop);
    Serial.println("ms");
  }

  button1.update();
  button2.update();

  if(button1.fell()){
    lastButton1Press = millis();
  }
  if(button2.fell()){
    lastButton2Press = millis();
  }
  if(button1.rose()){
    if(millis()-lastButton1Press>5000){
      resetNetStatic();
      lastButton1Press+=20000;
      globalNewSettingsFlag = true;
      Serial.println("Reset Static");
    }
  }
  if(button2.rose()){
    Serial.println("Button 2 Pressed");
    if(millis()-lastButton2Press>5000){
      resetNetDHCP();
      lastButton2Press+=20000;
      globalNewSettingsFlag = true;
      Serial.println("Reset DHCP");
    }
  }

  if(millis() - lastSerialLog > 10000){
    lastSerialLog = millis();
    serialHeartbeat();
  }


  if(globalMotherboardRevision>=3){
    while (Serial8.available() > 0) {
      char incomingByte = Serial8.read();
  
      if(incomingByte == 0x0A){
        if(serialBuf[0]=='K'){
          String str = String(serialBuf);
          byte i = String(serialBuf[1]).toInt();
          int val1 = str.substring(str.indexOf("@")+1, str.indexOf(",")).toInt();
          int val2 = str.substring(str.indexOf(",")+1).toInt();
          knobEvent(i, val2, val1);
        }
        for(byte i=0; i<serialIndex; i++){
          serialBuf[i] = 0;
        }
        serialIndex = 0;
      }else{
        serialBuf[serialIndex] = incomingByte;
        serialIndex++;
      }
    }
  }

  if(globalMIDIPageControl){
    usbMIDI.read(globalMIDIPageChannel);
  }

  digitalWrite(LED_BUILTIN, button1.read() && button2.read());


}

void touchEvent(Fader* fader){
  byte channel = fader->getChannel();

  if(globalMode==OP_Midi || globalMode==OP_Midi_NoMotor){
    midi.touchEvent(channel, fader);
    
  }else if(globalMode==OP_QLab){
    qlab.touchEvent(channel, fader);
    
  }else if(globalMode==OP_Eos){
    eos.touchEvent(channel, fader);
    
  }else if(globalMode==OP_X32 || globalMode==OP_XAIR){
    x32.touchEvent(channel, fader);
    
  }else if(globalMode==OP_DiGiCo){
    digico.touchEvent(channel, fader);
    
  }
}

void motorEvent(Fader* fader){
  byte channel = fader->getChannel();

  if(globalMode==OP_Midi){
    midi.motorEvent(channel, fader);
    
  }else if(globalMode==OP_QLab){
    qlab.motorEvent(channel, fader);
    
  }else if(globalMode==OP_Eos){
    eos.motorEvent(channel, fader);
  }
}

void knobEvent(byte index, int direction, int value){
  encoders[index-1].direction = direction;
  encoders[index-1].value = value;
  
  if(globalMode==OP_Midi || globalMode==OP_Midi_NoMotor){
    midi.knobEvent(encoders[index-1].channel, &encoders[index-1]);
    
  }else if(globalMode==OP_Eos){
    eos.knobEvent(encoders[index-1].channel, &encoders[index-1]);

  }
}


void proLabel(byte index, byte pos, String text){
  if(globalMotherboardRevision>=3){
    Serial8.write('L');
    Serial8.print(index);
    Serial8.write('/');
    Serial8.print(pos);
    Serial8.write('@');
    Serial8.println(text);
  }
}

void midiPCHandle(byte channel, byte prog) {
  Serial.print("Page Change: ");
  Serial.println(prog);
  if(channel==globalMIDIPageChannel){
    if(prog==1 || prog==2 || prog==3 || prog==4){
      changePage(prog);
    }
  }
}


void channelUpdateAll(){
  fader1.updateChannel();
  fader2.updateChannel();
  fader3.updateChannel();
  fader4.updateChannel();
  fader5.updateChannel();
  fader6.updateChannel();
  fader7.updateChannel();
  fader8.updateChannel();
}

void pauseAllFaders(){
  fader1.pause();
  fader2.pause();
  fader3.pause();
  fader4.pause();
  fader5.pause();
  fader6.pause();
  fader7.pause();
  fader8.pause();
}

void unpauseAllFaders(){
  fader1.unpause();
  fader2.unpause();
  fader3.unpause();
  fader4.unpause();
  fader5.unpause();
  fader6.unpause();
  fader7.unpause();
  fader8.unpause();
}

void changePage(byte p){
  globalPage = p-1;
  if(globalMode==3){ qlab.changePage(); }
  channelUpdateAll();
}

void setFaderTarget(byte index, int value){
  if(index>0 && index<256){
    globalFaderTargets[index] = max(0, min(1023, value));
  }
}

void serialHeartbeat(){
//  Serial.print("FADER_X VERSION ");
//  Serial.print(versionMajor);
//  Serial.print(".");
//  Serial.print(versionMinor);
//  Serial.print(".");
//  Serial.println(versionSub);
//  
//  Serial.print("IP Address = ");
//  Serial.print(net.IP_Static[0]);
//  Serial.print(".");
//  Serial.print(net.IP_Static[1]);
//  Serial.print(".");
//  Serial.print(net.IP_Static[2]);
//  Serial.print(".");
//  Serial.println(net.IP_Static[3]);
//
//  Serial.print("Operation Mode = ");
//  Serial.println(globalMode);
//
//  Serial.print("Motherboard Revision = ");
//  Serial.println(globalMotherboardRevision);
}
