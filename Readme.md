# Twisted Fate Card Selector v1

![Project Image](https://images6.alphacoders.com/658/thumb-1920-658023.jpg)

---

### Table of Contents
- [Overview](#Overview)
- [Usage](#Usage)
- [Notes](#Notes)
- [License](#license)

---

## Overview:


My ultimate goal for this project was to wait for input from users and in a non detectable way, determine what was on the screen and then execute very fast (millisecond second) key press. 

The primary outcome here was for me to get more practice using C++ but also to create a small game cheat that I could actually utilize without consequence. I have been wanting to get into game creation and also creating memory modifications for game hacks but anti-cheats make this a bit harder than I can handle at the moment. 

![Project Image](https://github.com/MicrosoftDocs/win32/raw/docs/desktop-src/inputdev/images/csinp-01.png)

#### Technologies used:
    Multithreading
    Win32 API 

[Back To The Top](#Twisted-Fate-Card-Selector-v1)

---

## Usage:


```
Setup:
    > Download C++ from https://nuwen.net/mingw.html and make sure it is installed to your path 
    > Open the download location and run the following 
Compile: 
    > g++ main.cpp LeagueProgramHeaderImplementation.cpp -lgdi32 -o twisted
    > twisted.exe
```
> W - Selects blue card

> R - Waits for repress to engage ultimate

> Space - Selects gold card 

> End - Terminates program 

> Enter - Pauses execution for chat functionality 



[Back To The Top](#Twisted-Fate-Card-Selector-v1)

---
## Notes: 

    Depending on your particular configuration you may have to obtain your own hex color values for each card/ability. 
    I did this by recording my screen while using each ability and then using the included python script to collect the RGB values.


    Be aware that lag will have an impact on this program as there is quite literally a larger disconnect between what is shown on your screen and the actual game server. 
    As long as your ping is below 70ms you should be fine. 


    The dependability of this script is not 100%, probably more like 80-90%
    So long as you do not spam any hotkey, you should be fine. 


    If you play on a resolution above 1080p - you can simply change the function to allow the alteration. 
    But keep in mind, you will definately have to alter the X/Y coordinates for the abilities on the screen and get their hex values! 

---

## License

MIT License
Copyright (c) [2021] 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

[Back To The Top](#Twisted-Fate-Card-Selector-v1)

---

Artwork credit: https://images6.alphacoders.com/658/thumb-1920-658023.jpg
