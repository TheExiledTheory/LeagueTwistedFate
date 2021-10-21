// Header file implementation "LeagueProgramHeaderImplementation.cpp"

#include "LeagueProgramHeader.hpp"	// Include header file

using namespace std;

// Constructor
LeagueProgram::LeagueProgram(){};

// Check resolution for 1920x1080
void LeagueProgram::screenSize() {

	try {

		// Get screen dimentions
		int height = GetSystemMetrics(SM_CYSCREEN);
		int width = GetSystemMetrics(SM_CXSCREEN);

		// Verify the height and width are proper
		if (height != 1080 && width != 1920) {

			cout << "CANNOT CONTINUE!" << endl;
			cout << width << "x" << height << endl;
			cout << "MUST BE 1920x1080!" << endl;
		}

		cout << width << "x" << height << " is valid!" << endl;

  	} catch (const exception &e) {
		cout << e.what() << endl;
  	}
}

/*
// Checks if W/R is avaialable to press 
bool LeagueProgram::abilityAvaiablity(const char ability) {
	
	int R;
	int G;
	int B;
	HDC dc;
	COLORREF color;
	string hex_color; 

	// Get device context
	dc = GetDC(NULL);

	// Verify device context
	if (dc == NULL) {
		return false;
	}

	// Check for the ability 
	if (ability == 'w') {
		
		// Get the current color of pixel 
		color = GetPixel(dc, W_ABILITY_X, W_ABILITY_Y); 

		// Make sure color valid 
		if (color == CLR_INVALID) {
			return false; 
		}

		// Set the colors for RGB
		R = GetRValue(color);
		G = GetGValue(color);
		B = GetBValue(color);

		// Convert to hex 
		hex_color = rgb2hex(R, G, B); 

		cout << "Current pixel hex value: [" << hex_color << "]" << endl; 
		cout << "Expected pixel hex value: [" << W_ABILITY_HEX << "]" << endl;
		cout << "W Available/Active: [";
		(hex_color == W_ABILITY_HEX || hex_color == BLUE_CARD_HEX || hex_color == GOLD_CARD_HEX) ? (cout << "yes]" << endl) : (cout << "no]" << endl);
		
		// Release device context 
		ReleaseDC(NULL, dc);

		// Compare current to expected hex values - the card in game will be one of these if ready state 
		if (hex_color == W_ABILITY_HEX || hex_color == BLUE_CARD_HEX || hex_color == GOLD_CARD_HEX) {
			return true;
		} else {
			return false; 
		}
	} 
	
	// Check for the ability
	if (ability == 'r') {

		// Get the current color of pixel 
		color = GetPixel(dc, R_ABILITY_X, R_ABILITY_Y); 

		// Make sure color valid 
		if (color == CLR_INVALID) {
			return false; 
		}

		// Set the colors for RGB
		R = GetRValue(color);
		G = GetGValue(color);
		B = GetBValue(color);

		// Convert to hex
		hex_color = rgb2hex(R, G, B); 

		cout << "Current pixel hex value: [" << hex_color << "]" << endl; 
		cout << "Expected pixel hex value: [" << R_ABILITY_HEX << "]" << endl;
		cout << "R Available/Active: [";
		(hex_color == R_ABILITY_HEX || hex_color == R_ACTIVE_HEX) ? (cout << "yes]" << endl) : (cout << "no]" << endl);
		
		// Release device context 
		ReleaseDC(NULL, dc);

		// Compare current to expected
		if (hex_color == R_ABILITY_HEX || hex_color == R_ACTIVE_HEX) {
			return true;
		} else {
			return false; 
		}
	} 
	return false; 
}
*/
// Clicks W if a pixel color matches card 
bool LeagueProgram::cardSelector(const char card)  {

	int R;
	int G;
	int B;
	HDC dc; 
	int int_card = -1;
	COLORREF color;
	string hex_color; 

	// Char to into for switch 
	if (card == 'b') {	
		int_card = 1; 
	} else if (card == 'r') {
		int_card = 2; 
	} else if (card == 'g') {
		int_card = 3;
	}

	// Get device context
	dc = GetDC(NULL);

	// Verify device context
	if (dc == NULL) {
		return false;
	}

	// Get the current color of pixel 
	color = GetPixel(dc, W_ABILITY_X, W_ABILITY_Y); 

	// Make sure color valid 
	if (color == CLR_INVALID) {
		return false; 
	}

	// Set the colors for RGB
	R = GetRValue(color);
	G = GetGValue(color);
	B = GetBValue(color);

	// Convert to hex
	hex_color = rgb2hex(R, G, B); 

	if (hex_color != W_ABILITY_HEX && hex_color != BLUE_CARD_HEX && hex_color != GOLD_CARD_HEX && hex_color != RED_CARD_HEX) {
		cout << "W not ready! - no action taken" << endl; 
		return false; 
	}

	// While the card is chooseable 
	while (hex_color == W_ABILITY_HEX || hex_color == BLUE_CARD_HEX || hex_color == GOLD_CARD_HEX) {
		
		// Get the current color of pixel 
		color = GetPixel(dc, W_ABILITY_X, W_ABILITY_Y); 

		// Set the colors for RGB
		R = GetRValue(color);
		G = GetGValue(color);
		B = GetBValue(color);

		// Convert to hex
		hex_color = rgb2hex(R, G, B); 

		// Check Wx pixel and Wy pixel for W 
		switch (int_card) {
			case 1: // Currently on blue card 
				if (hex_color == BLUE_CARD_HEX) {
					INPUT input;
					WORD vkey = VK_F12; // see link below
					input.type = INPUT_KEYBOARD;
					input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
					input.ki.time = 0;
					input.ki.dwExtraInfo = 0;
					input.ki.wVk = vkey;
					input.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
					SendInput(1, &input, sizeof(INPUT));

					input.ki.dwFlags = KEYEVENTF_KEYUP;
					SendInput(1, &input, sizeof(INPUT));
				}
				cout << "BLUE! - w pressed!" << endl; 
				return true;
				break;
			case 2: // Currently on red card
				if (hex_color == RED_CARD_HEX) {
					INPUT input;
					WORD vkey = VK_F12; // see link below
					input.type = INPUT_KEYBOARD;
					input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
					input.ki.time = 0;
					input.ki.dwExtraInfo = 0;
					input.ki.wVk = vkey;
					input.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
					SendInput(1, &input, sizeof(INPUT));

					input.ki.dwFlags = KEYEVENTF_KEYUP;
					SendInput(1, &input, sizeof(INPUT));
				}
				cout << "RED! - w pressed!" << endl; 
				return true; 
				break; 
			case 3: // Currently on gold card
				if (hex_color == GOLD_CARD_HEX) {
					INPUT input;
					WORD vkey = VK_F12; // see link below
					input.type = INPUT_KEYBOARD;
					input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
					input.ki.time = 0;
					input.ki.dwExtraInfo = 0;
					input.ki.wVk = vkey;
					input.ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
					SendInput(1, &input, sizeof(INPUT));

					input.ki.dwFlags = KEYEVENTF_KEYUP;
					SendInput(1, &input, sizeof(INPUT));
				}
				cout << "Gold! - w pressed!" << endl; 
				return true; 
				break; 
			default: 
				break; 
		}
	}
	cout << "Cannot selected a card :(" << endl; 
	return false; 
} 

// Convert RGB to String 
std::string LeagueProgram::rgb2hex(int r, int g, int b) {
	
	// Create a string 
	stringstream ss;
	// Pipe hex format delim
	ss << "#"; 
	// Bitshift each and bitwise or colors 
	ss << std::hex << (r << 16 | g << 8 | b); 
	
	return ss.str(); 
}	
