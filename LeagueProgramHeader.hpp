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
#include <future>
#include <iomanip> 

// Ability base hex values 
#define W_ABILITY_HEX "#9e7026" 	
#define R_ABILITY_HEX "#f48f10" 
#define R_ACTIVE_HEX "#83723e"		

// Card base hex values
#define BLUE_CARD_HEX "#3539ac"		
#define GOLD_CARD_HEX "#7b5d04"		
#define RED_CARD_HEX "#730a12"		

// Unavailable hex values 
#define W_CD_BLUE_HEX "#42392a"
#define W_CD_GREY_HEX "#0b4a76"

// Pixel coordinates 
#define W_ABILITY_X 881
#define W_ABILITY_Y 1002

#define R_ABILITY_X 955
#define R_ABILITY_Y 1004


// Define the class
class LeagueProgram {
	//private:
	public:
		static bool r_available; 			// Created to account for thread reference compiler error 
		bool available; 					// Ability availability
		bool key_pressed; 					// Ability key pressed

		// Function definitions 
		LeagueProgram(); 					// Explicit Constructor
		void screenSize(); 					// Check for 1920x1080 resolution
		bool abilityAvaiablity(const char); // Checks R ability availability
		bool cardSelector(const char); 		// Selects card based on pixel color 
		std::string rgb2hex(int, int, int); // Changes RGB value to hex 
		void clickButton(WORD); 			// Simulates key press
		void operator () (); 				// Overload the () operator
};
#endif
