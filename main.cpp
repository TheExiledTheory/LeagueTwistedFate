// Main file for functional logic "main.cpp"
// Run - g++ main.cpp LeagueProgramHeaderImplementation.cpp -lgdi32 -std=c++14 -pthread
// Run - a.exe


/*
Try to make the program as fast as possible

TF cards switch about every 1.55 seconds so as long as the script executes within that time frame there shouldnt be a problem 

There is currently a known bug - when using clickButton() this (UNDER CERTAIN INSTANCES) cause the screen to cut out for some reason. 
I am not sure the exact reason behind this but there are several possible solutions online but to I tested to no avail 

*/

#include "LeagueProgramHeader.hpp" // Include header file

using namespace std;

int main (void) {

	// Setup object 
	LeagueProgram object1;
	object1.available = false; 
	object1.key_pressed = false;
	WORD vkey;

	// Check screen resolution 
	cout << "Attempting to get screen dimensions." << endl;
	object1.screenSize();

/*
There is a bug with the following code - When 
There are several things you can try but I am unsure which would work at the moment 
ZeroMemory(&input,sizeof(input));



	// Make sure that Enter key is not toggled before starting 
	loop: // JUMP LABEL 

	// Make sure that ENTER is not toggled 
	if (GetKeyState(VK_RETURN) == 1 || GetKeyState(VK_RETURN) < 0) { 
		vkey = 0x0D; 
		sleep(1); 
		object1.clickButton(vkey); 
		sleep(1); 

		// Make sure that it is untoggled 
		if (GetKeyState(VK_RETURN) != 0) {
			goto loop; 
		}
	} 
*/

	cout << "Beginning in 3 seconds." << endl;
	sleep(3);

	cout << "READY AND WAITING!" << endl;
	cout << "======================================" << endl; 

	// Pressing end key will terminate 
	while (!(GetKeyState(35) & 0x8000)) {

		// Request Win32 for keystates 
		int w_pressed = (GetKeyState(87) & 0x8000); 
		int ctrl_pressed  = (GetKeyState(VK_CONTROL) & 0x8000);
		int space_pressed = (GetKeyState(VK_SPACE) & 0x8000);
		int r_pressed = (GetKeyState(82) & 0x8000);
		int enter_pressed = (GetKeyState(VK_RETURN));

/*
		if (enter_pressed < 0 || enter_pressed == 1) {
			cout << "Active enter ! " << enter_pressed << endl;
		} else {
			cout << "Inactive enter ! " << enter_pressed << endl;
		}
		sleep(1); 
*/

/*
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

			// Determine execution time taken for calls 
			auto stop_timer = std::chrono::high_resolution_clock::now(); 
			auto timer = std::chrono::duration_cast<std::chrono::milliseconds>(stop_timer - start_timer); 
			cout << "Execution time: " << timer.count() << " milliseconds" << endl; 
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

			// Determine execution time taken for calls 
			auto stop_timer = std::chrono::high_resolution_clock::now(); 
			auto timer = std::chrono::duration_cast<std::chrono::milliseconds>(stop_timer - start_timer); 
			cout << "Execution time: " << timer.count() << " milliseconds" << endl; 
		}

		// Check if enter is active or pressed down 			
		if (enter_pressed < 0 || enter_pressed == 1) {
			cout << "Chat functionality engaged!" << endl; 

			// Lambda function for thread 
			auto waiter = [](int enter_pressed) {	// No need for capture list[=][&]    [capture clause] (parameters) -> return-type {body}

				do {
					// Get an accurate status 
					enter_pressed = GetKeyState(VK_RETURN);
					sleep(1); 
					cout << "Waiting...\n\n"; 
				} while (enter_pressed != 0); 
			}; 

			// Create a new thread 
			thread thread_obj(waiter, enter_pressed); 
			thread_obj.join(); 

			cout << "Chat functionality disabled!" << endl;
		} 
*/
		// Detects r press (not including upgrades)
		if (r_pressed != 0 && ctrl_pressed == 0) {
			
			// Create a thread to check if available 
			//thread thread_obj = thread(LeagueProgram::abilityAvaiablity, object1.available); 
			//thread_obj.join(); 

			// The ability is active! 
			if (object1.available == true) {
				// Reset key state  
				r_pressed = 0;

				// 	Start a time for max of 10 seconds
				auto start_timer = std::chrono::high_resolution_clock::now(); 
				std::chrono::duration<double> difference;
				do {
					// Check change to keystate 
					r_pressed = (GetKeyState(82) & 0x8000);

					// If r was repressed
					if (r_pressed != 0) {
						// Select gold 
						object1.cardSelector('g');
						break;
					}

					// Update countdown 
					auto stop_timer = std::chrono::high_resolution_clock::now(); 
					difference = std::chrono::duration_cast<std::chrono::duration<double>>(stop_timer - start_timer);


				} while (difference.count() < 10.0); // NO LONGER THAN 10 SEC

			} else {
				cout << "Ultimate not active - nothing to do!" << endl; 
			}
		}

		object1.available = false;
		object1.key_pressed = false; 
	}
	return 0;
}







