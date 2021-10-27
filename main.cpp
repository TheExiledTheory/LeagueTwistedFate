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
	clock_t start;
	double duration;

	cout << "Attempting to get screen dimensions." << endl;

	// Check screen size
	object1.screenSize();

	cout << "Beginning in 3 seconds." << endl;

	// Wait a moment
	sleep(3);

	cout << "READY!" << endl;

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



		sleep(.88); 

		int w_pressed = (GetKeyState(87) & 0x8000); 

/*
		if (w_pressed) {
			cout << "pressed " << w_pressed << endl;
		} else {
			cout << "not pressed " << w_pressed << endl;
		}
*/

		// Detect W press
		//if (GetKeyState(87) & 0x8000) {//& 0x8000) {
		if (w_pressed != 0) {

			cout << "W press detected! \n Checking for availability! \n";

			// Determine how fast functio runs 
			auto start_timer = std::chrono::high_resolution_clock::now();
			
			// Check W availability
			//object1.available = object1.abilityAvaiablity('w');

			// Call card selector(blue)
			//if (object1.available == true) {

				// Detect blue card and press w  
		
////////////////////////////////////////////////////////////////////////////

			object1.key_pressed = object1.cardSelector('b');
			if (object1.key_pressed == true) {
				cout << "SUCCESS" << endl; 
			} 


////////////////////////////////////////////////////////////////////////////

				//cout << "key_pressed: " << object1.key_pressed << endl; 

				//object1.available = false; 
				//object1.key_pressed = false; 

			//} else {
			//	cout << "\n\n";
				/*REMOVE ME COPY TO LOWER*/sleep(1); /*REMOVE ME COPY TO LOWER*/
			//	continue;

			//}

			// Determine execution time taken for calls 
			auto stop_timer = std::chrono::high_resolution_clock::now(); 
			auto timer = std::chrono::duration_cast<std::chrono::milliseconds>(stop_timer - start_timer); 
			cout << "Execution time from button detect to finish: " << timer.count() << " miliseconds" << endl; 
			
			// Upon successful execution = may want to sleep to avoid recalling functions 
			//sleep(5);
		}

/*
		// Detect space press
		if (GetKeyState(32) & 0x8000) {

			// Check W availability
			object1.available = object1.abilityAvaiablity('w');
				
			// Call card selector(blue)
			if (object1.available) {

				// Detect blue card and press w  
				object1.key_pressed = object1.cardSelector('g');
				object1.available = false; 
				object1.key_pressed = false; 
				
			} else {
				continue; 
			}

		}
		// Detect R press
		if (GetKeyState(82) & 0x8000) {

			// Check R availability
			object1.available = object1.abilityAvaiablity('g');
			if (object1.available) {

				object1.available = false; 

				// Check W availability
				object1.available = object1.abilityAvaiablity('w');
				if (object1.available) {
					
					// Check for R repress on come up !!! 

					// Select gold card 
					object1.key_pressed = object1.cardSelector('g');
					object1.available = false; 
					object1.key_pressed = false; 

				} else {
					continue; 
				}
			} else {
				continue; 
			}
		}

		// Detect enter press (static state)
		if (GetKeyState(13)) {					


			// Setup timer
			start = clock();

			cout << "Chat function started! - Pause!" << endl;

			// Wait for re-press
			while (GetKeyState(13)) {

				// Calculate duration
				duration = clock() - start / (double) CLOCKS_PER_SEC;
				cout << "Halted for: " << duration << endl;

				try { // Pause thread
					sleep(1);
				} catch (const exception &e) {
					cout << e.what() << endl;
				}
			}

			cout << "Chat function ended! - Resume!" << endl;
		}
*/
		// Check for alt+tab
		//if (GetKeyState() && GetKeyState()) {
		//	exit(); 
		//}
	

	}

	return 0;
}







