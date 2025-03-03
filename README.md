<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a id="readme-top"></a>
<!--  *** Thanks for checking out the Best-README-Template. If you have a suggestion that would make this better, please fork the repo and create a pull request or simply open an issue with the tag "enhancement". Don't forget to give the project a star! Thanks again! Now go create something AMAZING! :D -->



<!-- /// d   u   b   p   i   x   e   l  ---  f   o   r   k   ////--v0.5.0 -->
<!--this has additionally been modifed by @dubpixel for hardware use -->
<!--search dpx_faded.. search & replace is COMMAND OPTION F -->

<!--todo add small product image thats not in a details tag -->
<!--igure out how to get the details tag to properly render in jekyll for gihub pages.-->




<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
***
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/dubpixel/dpx_faded">
    <img src="images/logo.png" alt="Logo" height="120">
  </a>

<h1 align="center">dpx_faded</h1>
<h3 align="center"><i>because whats life without fader?</i></h3>
<br />
  <p align="center">
    ...a motorized fader breakout inspired by the FADER_4. Since there were only gerbers that didnt seem to match any faders available easily  - i re made a KiCAD project based on the 1.8 board revision. Included here for quick reference is a VScode migrated FADER_X firmware distro... soon to be migrated to its own _genuine_ fork.
        <br />
     »  
     <a href="https://github.com/dubpixel/dpx_faded/tree/main/"><strong>Project Here!</strong></a>
     »  
    <a href="https://github.com/dubpixel/dpx_faded/tree/main/hardware/src/dpx_faded/bom"><strong>BOM Here!</strong></a>
     » 
    <a href="https://dubpixel.github.io/dpx_faded/ibom/index.html"><strong>Interactive BOM Here!</strong></a>
     <br />
    <a href="https://github.com/dubpixel/dpx_faded/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    ·
    <a href="https://github.com/dubpixel/dpx_faded/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
    </p>
</div>
   <br />
<!-- TABLE OF CONTENTS -->
<details>
<summary><h3>Table of Content</h3></summary>
<ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>    
    <li><a href="#reflection">Reflection</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
</ol>
</details>
<br />
<!-- ABOUT THE PROJECT -->

<details>
<summary><h3>About The Project</h3></summary>
While the maker made the firmware open source, as well as the production gerber files - the cad files were not released in a malliable format, which doesnt allow further development of that hardware platform. (bummer). Since there is some community interest in the product, here we attempt to reverse engineer the FADE_4 as a proof of concept before continuing with development
</br>
author(s): // www.dubpixel.tv  - i@dubpixel.tv | other authors
</br>
<h3>Images</h3>

### FRONT
![FRONT][product-front]

### REAR 
![REAR][product-rear]

### FRONT Rendering
![FRONT][product-front-rendering]

### REAR Rendering
![REAR][product-rear-rendering]

### iBOM PCB Front
![iBOM Front][product-pcbFront]

### iBOM PCB Rear
![iBOM Front][product-pcbRear]

</details>


<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With 
 * [![KiCad][KiCad.org]][KiCad-url]
 * [![Fusion360][Fusion-360]][Autodesk-url]
 * [![FastLed][FastLed.io]][FastLed-url]

<!--
  
 * [![Fusion360][Fusion-360]][Autodesk-url]
 * [![Next][Next.js]][Next-url]
 * [![React][React.js]][React-url]
 * [![Vue][Vue.js]][Vue-url]
 * [![Angular][Angular.io]][Angular-url]
 * [![Svelte][Svelte.dev]][Svelte-url]
 * [![Laravel][Laravel.com]][Laravel-url]
 * [![Bootstrap][Bootstrap.com]][Bootstrap-url]
 * [![JQuery][JQuery.com]][JQuery-url]
 
-->
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started


### Prerequisites


### Installation

<!--
1. Download...
2. Enjoy.
3. Repeat as Needed! -->

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

<!-- Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_-->

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Reflection

* what did we learn? 
* what do we like/hate?
* what would/could we do differently?
<!-- 
* what did we learn? 
* what do we like/hate?
* what would/could we do differently? 
-->

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->

## Roadmap

- [x] Reverse Enineer FADE_4 from gerber and firmware.
- [ ] Re-Draw Front Panel
- [ ] Prove Existing FADE_4 Redesign 
    - [ ] with x32 faders
- [ ] Find source of touch faders from anyone but Apai
    - [ ] talking to lyric made me want to go be a dirt farmer
 - [ ] Add LED to front panel


See the [open issues](https://github.com/dubpixel/dpx_faded/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Top contributors:

<a href="https://github.com/dubpixel/dpx_faded/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=dubpixel/dpx_faded" alt="contrib.rocks image" />
</a>


<!-- LICENSE -->
## License

  Distributed under the UNLICENSE License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

  ### Joshua Fleitell - i@dubpixel.tv

  Project Link: [https://github.com/dubpixel/dpx_faded](https://github.com/dubpixel/dpx_faded)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [stagehacks](https://github.com/stagehacks/FADER_X) - fader X project

<!--
  * [ ]() - the best 
-->

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/dubpixel/dpx_faded.svg?style=for-the-badge
[contributors-url]: https://github.com/dubpixel/dpx_faded/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/gdubpixel/dpx_faded.svg?style=for-the-badge
[forks-url]: https://github.com/dubpixel/dpx_faded/network/members
[stars-shield]: https://img.shields.io/github/stars/dubpixel/dpx_faded.svg?style=for-the-badge
[stars-url]: https://github.com/dubpixel/dpx_faded/stargazers
[issues-shield]: https://img.shields.io/github/issues/dubpixel/dpx_faded.svg?style=for-the-badge
[issues-url]: https://github.com/dubpixel/dpx_faded/issues
[license-shield]: https://img.shields.io/github/license/dubpixel/dpx_faded.svg?style=for-the-badge
[license-url]: https://github.com/dubpixel/dpx_faded/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/jfleitell
[product-front]: images/front.png
[product-rear]: images/rear.png
[product-front-rendering]: images/front_render.png
[product-rear-rendering]: images/rear_render.png
[product-pcbFront]: images/pcb_front.png
[product-pcbRear]: images/pcb_rear.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
[KiCad.org]: https://img.shields.io/badge/KiCad-v8.0.6-blue
[KiCad-url]: https://kicad.org 
[Fusion-360]: https://img.shields.io/badge/Fusion360-v4.2.0-green
[Autodesk-url]: https://autodesk.com 
[FastLed.io]: https://img.shields.io/badge/FastLED-v3.9.9-red
[FastLed-url]: https://fastled.io 
