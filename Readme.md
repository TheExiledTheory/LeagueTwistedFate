
- REQUIREMENTS: 
	- Must have 1920x1080
	- Must have mingw-17.1.exe https://nuwen.net/mingw.html
	- Must have ingame hud set to 0
	- Can use python script to get info on pixels and color 
		python 3.10 
		pip3 install pillow mouseinfo
	- You will most likely have to obtain your own hex values for script 
	-AutoHotkey with the path to the script set in the program 

About - I wanted to write a mini game hack that could give me an advantage without being detected. I have been planning on making memory analysis programs and hacks for various games such as RUST but getting around an anti-cheat engine is more difficult that you would imagine. 



Synopsis 

My ultimate goal for this project was to wait for input from users and in a non detectable way determine what was on the screen and then execute very fast (nano or micro sec) key press


I started this project by defining my design for the program and what I wanted the requirements to be and in what order. After I had that down I got working on the initial program detecting key strokes and self analysing timing. I then began getting the required data and testing using actual example cases from the game. Through further thought I would see sleight optimizations in approach such as pre-defining values and reducing functions calls for timing and using optimization such as multithreading and sleeping after succesful calls to prevent wasting memory. I was going to implement a way to detect the pixel and color under the cursor but it was a lot easier to use the pre-written python library for this and it was most beneficial. From there I gathered pixel coordinates from buttons along with their respective hex colors when active and not active and defined them. Once I had this down I was able to write the primary meat of the functions which was obtaining the pixel and checking colors! I also made sure though my process to note down any possible bugs I came across in advance so that I could handle them down the road. I am not exactly sure how but through my testing, the LeagueOfLegends game seems to block SendInput() and Keybd_even() system calls from my C++ program so instead I use AutoHotKey to send the key. I am not sure how but the game seems to be able to tell the difference between keyboard interrupts and virtual input calls. Once again I am not sure how AutoHotKey circuments this but after testing, it seems to work flawlessly 

Through out writing this program i came across several things that i did not know and had to learn such as use of Device Context function how win32 api handles key detection and what that looks like and also converting int values to a single hex value with it shifting and bitwise or 


Steps - 
I wrote down the functionality I wanted
I determined the fasted way to complete that functionality
I tested test out several different possible work throughs and setup my initial program
From there I slowly implemented one feature at a time testing along the way 

Running - 
g++ main.cpp LeagueProgramHeaderImplementation.cpp -lgdi32
a.exe




YOU WILL HAVE TO OBTAIN YOUR OWN HEX COLOR VALUES FOR ABILITEIS AS THESE DIFFERE FOR EVERY DIFFERENT SETUP 
THE WAY I DID THIS WAS BY RECORDING MY SCREEN AND CAPTURING THE COLORS AT THE PIXELS X/Y FOR EACH ABILITY 

LAG WILL HAVE AN INPACT ON THIS AS THERE IS A LITERAL DISCONNECT BETWEEN WHAT IS SHOWN ON SCREEN AND THE ACTUAL GAME ON THE SERVER. KEEP PING <80 