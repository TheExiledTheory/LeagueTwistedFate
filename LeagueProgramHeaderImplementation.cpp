// Header file implementation "LeagueProgramHeaderImplementation.cpp"

// Include header file 
#include "LeagueProgramHeader.hpp"	
// Set namespace
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

			cout << "CANNOT CONTINUE! ";
			cout << width << "x" << height << endl;
			cout << "MUST BE 1920x1080!" << endl;
			exit(0); 
		}
		cout << width << " x " << height << " is valid!" << endl;
		
  	} catch (const exception &e) {
		cout << e.what() << endl;
  	}
}


// Command funciton for thread callable object 
// Overloading operator () to call class method 
void LeagueProgram::operator () () {
	// Check if R is activated 
	r_available = abilityAvaiablity('r'); 
}


// This () was initially going to be used just to check w is clickable but I decided to implement that into the cardSelector()
// This () is reserved just for checking if R is active 
bool LeagueProgram::abilityAvaiablity(const char card) {
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

	// Check if R is available or "active"
	if (card == 'r') {
		
		// Get the current color of pixel 
		color = GetPixel(dc, R_ABILITY_X, R_ABILITY_Y); 

		// Make sure color valid 
		if (color == CLR_INVALID) {
			ReleaseDC(NULL, dc);
			return false; 
		}

		// Set the colors for RGB
		R = GetRValue(color);
		G = GetGValue(color);
		B = GetBValue(color);

		// Convert to hex
		hex_color = rgb2hex(R, G, B); 

		// Compare current to expected
		if (hex_color == R_ACTIVE_HEX) {
			ReleaseDC(NULL, dc); 
			return true;
		} 
	}

	// Check if W is available to click 
	if (card == 'w') {
		
		// Get the current color of pixel 
		color = GetPixel(dc, W_ABILITY_X, W_ABILITY_Y); 

		// Make sure color valid 
		if (color == CLR_INVALID) {
			ReleaseDC(NULL, dc);
			return false; 
		}

		// Set the colors for RGB
		R = GetRValue(color);
		G = GetGValue(color);
		B = GetBValue(color);

		// Convert to hex
		hex_color = rgb2hex(R, G, B); 

		// Compare current to expected
		if (hex_color == W_ABILITY_HEX || hex_color == BLUE_CARD_HEX || hex_color == GOLD_CARD_HEX || hex_color == RED_CARD_HEX) {
			ReleaseDC(NULL, dc); 
			return true;
		} 
	}
ReleaseDC(NULL, dc);
return false; 
}

// Reclicks W once a pixel color is matched to a known card
bool LeagueProgram::cardSelector(const char card)  {
	
	int R;
	int G;
	int B;
	HDC dc; 
	int int_card = -1;
	COLORREF color;
	string hex_color; 
	WORD vkey;

	// Char to int for switch 
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
		ReleaseDC(NULL, dc);
		return false; 
	}

	// Set the colors for RGB
	R = GetRValue(color);
	G = GetGValue(color);
	B = GetBValue(color);

	// Convert to hex
	hex_color = rgb2hex(R, G, B); 

	// Initial check to make sure the ability is available 
	if (hex_color != W_ABILITY_HEX && hex_color != BLUE_CARD_HEX && hex_color != GOLD_CARD_HEX && hex_color != RED_CARD_HEX) {
		cout << "The w ability is not avaialble! - no action taken!" << endl; 

		// Create lambda thread to constantly check for card availability // This check can be removed since we check before coming into this function 

		ReleaseDC(NULL, dc);
		return false; 
	}

	// 	Start a timer to avoid infinite loop 
	auto start_timer = std::chrono::high_resolution_clock::now(); 
	std::chrono::duration<double> difference;
	cout << "Timer started!" << endl;

	// While the card is chooseable 
	while ((hex_color != W_CD_BLUE_HEX || hex_color != W_CD_GREY_HEX) && difference.count() < 7.0) {
		cout << "The w ability is available! " << endl;
		cout << "Current card hex color: [" << hex_color << "]" << endl; 
		// Get the current color of pixel 
		color = GetPixel(dc, W_ABILITY_X, W_ABILITY_Y); 

		// Set the colors for RGB
		R = GetRValue(color);
		G = GetGValue(color);
		B = GetBValue(color);

		// Check color for card match 
		switch (int_card) {

			case 1: // Blue card presence check 

				// Evalaute pixel color 
				hex_color = rgb2hex(R, G, B); 
				cout << "Checking for blue card!" << endl; 
				cout << "Current card hex color: [" << hex_color << "] blue card expected hex: [" << BLUE_CARD_HEX << "]" << endl; 
				// Make sure the current card is Blue 
				if (hex_color == BLUE_CARD_HEX) {
					//cout << "Current card hex color: [" << hex_color << "] blue card expected hex: [" << BLUE_CARD_HEX << "]" << endl; 
					
					// Press the W key 
					vkey = 0x57; 
					clickButton(vkey); 
					cout << "BLUE chosen! - W pressed!" << endl; 

					//clickButton(vkey);
					ReleaseDC(NULL, dc);
					return true;

				} else {
					cout << "Blue card not matched - w not pressed!" << endl;
					break;
				}
			case 2: // Red card presence check 

				// Evalaute pixel color 
				hex_color = rgb2hex(R, G, B); 
				cout << "Checking for red card!" << endl; 
				cout << "Current card hex color: [" << hex_color << "] red card expected hex: [" << RED_CARD_HEX << "]" << endl; 

				// Make sure the current card is Blue 
				if (hex_color == RED_CARD_HEX ) {
					
					// Press the W key 
					vkey = 0x57; 
					clickButton(vkey); 
					cout << "RED chosen! - W pressed!" << endl; 

					//clickButton(vkey);
					ReleaseDC(NULL, dc);
					return true;
					
				} else {
					cout << "Red card not matched - w not pressed!" << endl;
					break;
				}
			case 3: // Gold card presence check

				// Evalaute pixel color 
				hex_color = rgb2hex(R, G, B); 
				cout << "Checking for gold card!" << endl; 
				cout << "Current card hex color: [" << hex_color << "] gold card expected hex: [" << GOLD_CARD_HEX << "]" << endl; 

				// Make sure the current card is Blue 
				if (hex_color == GOLD_CARD_HEX ) {
					
					// Press the W key 
					vkey = 0x57; 
					clickButton(vkey); 

					cout << "GOLD chosen! - W pressed!" << endl; 

					//clickButton(vkey);
					ReleaseDC(NULL, dc);
					return true;
					
				} else {
					cout << "Gold card not matched - w not pressed!" << endl;
					break;
				}

			default: 
				cout << "Card not matched to a candidate - did you specify b/r/g ?" << endl;
				break; 
		}

		// Update countdown 
		auto stop_timer = std::chrono::high_resolution_clock::now(); 
		difference = chrono::duration_cast<chrono::duration<double>>(stop_timer - start_timer);
		//cout << "Timer: " << setprecision(2) << fixed << showpoint << difference.count() << "/7.0 seconds!" << endl; 
					
	}
	
	cout << "End of cardSelector() reached ... this is not good :-(" << endl; 
	ReleaseDC(NULL, dc);
	return false; 
} 

// Convert RGB to String 
std::string LeagueProgram::rgb2hex(int r, int g, int b) {
	
	// Create a string and ss 
	stringstream ss;
	std::string s;

	// Pipe hex format delim
	ss << "#"; 

	// Bitshift each and bitwise or colors 
	ss << std::hex << (r << 16 | g << 8 | b); 

	s = ss.str(); 

	// Convert each character lowercase 
	for(auto& c : s) {
	   c = tolower(c);
	}
	return s; 
}	


//w = 0x57
//r = 0x52
// Function source https://stackoverflow.com/questions/22419038/how-to-use-sendinput-function-c/22419083#22419083
// Virtual key codes https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
void LeagueProgram::clickButton(WORD vkey) {

	// Setup virtual keyboard input structure
	//INPUT input = {};
	INPUT input; 
	input.type = INPUT_KEYBOARD;

	// Hardware scan code for virtual key
	input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;

	// Set the virtual key and indicate press 
	input.ki.wVk = vkey; 
	input.ki.dwFlags = 0; 

	// Simulate press of button 
	// Once for press down 
	sleep(.2);
	SendInput(2, &input, sizeof(INPUT));		// I tested for days and couldnt get this functionality to work until I changed from 1 to 2 
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	sleep(.2);
	// Again for release
	SendInput(2, &input, sizeof(INPUT));
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	sleep(.2); 

}

/*
UINT SendInput(
  [in] UINT    cInputs, - # of sturctures in input array 	=> I was under the impression there was only 1 
  [in] LPINPUT pInputs, - The input array itself 
  [in] int     cbSize, - size of each structure 
);
*/
