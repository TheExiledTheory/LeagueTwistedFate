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

#define W_ABILITY_HEX "#9E7260" 
//#define W_ability_RGB 158.112.38

#define R_ABILITY_HEX "#F48F10" 
//#define R_ability_RGB 244.143.116

#define R_ACTIVE_HEX "#83723E"
//#define R_ACTIVE_RGB 131.114.62

#define BLUE_CARD_HEX "#3539AC"
//define BLUE_CARD_RGB 53.57.172

#define GOLD_CARD_HEX "#7B5D04"
//define GOLD_CARD_RGB 123.93.4

#define RED_CARD_HEX "#730A12"
//define RED_CARD_RGB 115.10.18



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
		bool abilityAvaiablity(const char); // Checks ability option 
		bool cardSelector(const char); // Checks if the card is selected 
		std::string rgb2hex(int, int, int); // Changes RGB value to hex 
};
#endif
