// Header file definitions "HeaderProgramHeader.hpp"

// Directive to prevent redefinition - #pragma
#ifndef LeagueProgramHeader
#define LeagueProgramHeader

// All included libraries
#include <iostream>
#include <string>
#include <Windows.h>
#include <wingdi.h> 
#include <conio.h>
#include <winuser.h>
#include <cstdlib>
#include <chrono>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <winable.h>
#include <thread> 

#define W_ABILITY_HEX "#9e7026" 	

#define R_ABILITY_HEX "#f48f10" 
#define R_ACTIVE_HEX "#83723ew"		

#define BLUE_CARD_HEX "#3539ac"		
#define GOLD_CARD_HEX "#7b5d04"		
#define RED_CARD_HEX "#730a12"		


// Pixel coordinates 
#define W_ABILITY_X 881
#define W_ABILITY_Y 1002

#define R_ABILITY_X 955
#define R_ABILITY_Y 1004


// Define the class
class LeagueProgram {
	//private:
	public:

		bool available; 
		bool key_pressed; 

		LeagueProgram(); // Constructor
		void screenSize(); // Check for 1920x1080 resolution
		void abilityAvaiablity(bool *); // Checks ability option 
		bool cardSelector(const char); // Selects card 
		std::string rgb2hex(int, int, int); // Changes RGB value to hex 
		void clickButton(WORD); // Simulates key press 
};
#endif






