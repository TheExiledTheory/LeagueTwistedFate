// Main file for functional logic "main.cpp"
// Run - g++ main.cpp LeagueProgramHeaderImplementation.cpp -lgdi32
// Run - a.exe


//TO_DO -
	// Multithread for speed
	// Try to make program as fast as possible

#include "LeagueProgramHeader.hpp" // Include header file
//#pragma comment( lib, "gdi32" )
using namespace std;


int main (void) {

	// Setup object 
	LeagueProgram object1;
	object1.available = false; 
	object1.key_pressed = false;

	// Setup vars
	//clock_t start;
	WORD vkey;
	//double duration;

	cout << "Attempting to get screen dimensions." << endl;

	// Check screen size
	object1.screenSize();

	cout << "Beginning in 3 seconds." << endl;

	// Wait a moment
	sleep(3);

	cout << "READY!" << endl;
	cout << "======================================" << endl; 

	// While end key is not pressed
	while (!(GetKeyState(35) & 0x8000)) {

		// Store keystate variables here 
		// May want to sleep thread after successful execution 
		// Check if the key is pressed and the ability is available!  
		// Could set up a function to make an option dirty and use threading to check 
		// Have timers for each ability after use - multithread
		// POSSIBLE BUG - LEVELING UP AN ABILITY MAY CHANGE THE PIXEL COLOR AT XY  

		// MAKE SURE THAT TIME < 1.55 
		// MAKE SURE THAT CHECK IF CTRL is down also and dont run 
		// The THE AVAILABILITY NEEDS TO BE CHECKED AT BUTTON DETECT 
		//AND IT NEEDS TO CHECK FOR COLORS OTHER COLORS 

		// FIX ENTER BUTTON DETECTION


		//sleep(.88); 

		// Get key states 
		int w_pressed = (GetKeyState(87) & 0x8000); 
		int ctrl_pressed  = (GetKeyState(VK_CONTROL) & 0x8000);
		int space_pressed = (GetKeyState(VK_SPACE) & 0x8000);
		int r_pressed = (GetKeyState(82) & 0x8000);
		int enter_pressed = (GetKeyState(VK_RETURN));


		//if (enter_pressed) {
		//	cout << "pressed " << enter_pressed << endl;
		//} else {
		//	cout << "not pressed " << enter_pressed << endl;
		//}


		// Detects W press (not including upgrades)
		if (w_pressed != 0 && ctrl_pressed == 0) {

			cout << "W press detected!\nChecking for availability!\n...\n...\n\n";

			// Start a timer to check for function duration  
			auto start_timer = std::chrono::high_resolution_clock::now();
			
			// Run primary detection work
			object1.key_pressed = object1.cardSelector('b');
			
	
			if (object1.key_pressed == true) {
				cout << "FINISHED!\nRe-entering ready state!" << endl; 
			} 

			//sleep(1); 

			// Determine execution time taken for calls 
			auto stop_timer = std::chrono::high_resolution_clock::now(); 
			auto timer = std::chrono::duration_cast<std::chrono::milliseconds>(stop_timer - start_timer); 
			cout << "Execution time: " << timer.count() << " milliseconds" << endl; 
			//sleep(1); 
		}



		// Detects Space press (not including upgrades)
		if (space_pressed != 0 && ctrl_pressed == 0) {

			cout << "R press detected!\nChecking for availability!\n...\n...\n\n";

			// Start a timer to check for function duration  
			auto start_timer = std::chrono::high_resolution_clock::now();
			
			WORD vkey = 0x57;
			// Click w 
			object1.clickButton(vkey); 

			// Run primary detection work
			object1.key_pressed = object1.cardSelector('g');
			
			
			if (object1.key_pressed == true) {
				cout << "FINISHED!\nRe-entering ready state!" << endl; 
			} 

			//sleep(1); 

			// Determine execution time taken for calls 
			auto stop_timer = std::chrono::high_resolution_clock::now(); 
			auto timer = std::chrono::duration_cast<std::chrono::milliseconds>(stop_timer - start_timer); 
			cout << "Execution time: " << timer.count() << " milliseconds" << endl; 
			//sleep(1); 
		}



		// Detect enter press (static state)
		//while (enter_pressed != 0) {					

		//	enter_pressed = GetKeyState(VK_RETURN);
		//	cout << "Waiting for re-press..." << endl;

		//	sleep(1);
		//}


		// Detects r press (not including upgrades)
		//if (r_pressed != 0 && ctrl_pressed == 0) {

			// start a timer - 
			// while loop if r repressed = gold 
			// if r_pressed 
		//}


	//object1.available = false; 
	//object1.key_pressed = false; 

	}

	return 0;
}







