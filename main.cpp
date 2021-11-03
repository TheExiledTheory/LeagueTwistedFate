// Main file for functional logic "main.cpp"
// Compile - g++ main.cpp LeagueProgramHeaderImplementation.cpp -lgdi32 
// Run - .\a.exe


/*
Try to make the program as fast as possible!
TF cards switch about every 1.55sec
There is currently a known bug - when using clickButton() this (UNDER CERTAIN INSTANCES) cause the screen to cut out for some reason. 
I am almost positive that the implementation of sendInput() is causing Windows to enter power saver/sleep screen UNLESS THE MOUSE IS MOVING 

*/

// Include header file
#include "LeagueProgramHeader.hpp" 		
// Set namespace
using namespace std;
// Instanciate static class member 
bool LeagueProgram::r_available = false; 

// Altered cardSelector() directly taregeted at combatting a display bug
void untoggle(WORD vkey) {

	// Setup virtual keyboard input structure
	INPUT input[2] = { 0 };

	// Set the input structure to type keyboard
	input[0].type = input[1].type = INPUT_KEYBOARD;
	input[0].ki.wVk = input[1].ki.wVk = VkKeyScanA(vkey);
	
	// Set the key flag and send event 
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(2, input, sizeof(INPUT));
}

int main (void) {

	// Setup object 
	//LeagueProgram *league = new LeagueProgram;	// Using free store -> heap allocation 
	LeagueProgram object1;						// Using local vars -> stack allocation 
	object1.available = false; 
	object1.key_pressed = false;
	WORD vkey;

	// Check screen resolution 
	cout << "Attempting to get screen dimensions." << endl;
	object1.screenSize();


	loop: // JUMP LABEL 
	// Make sure that ENTER is not toggled 
	if (GetKeyState(VK_RETURN)) { 
		cout << "Enter status: 1 - toggled!" << endl;
		
		sleep(1);

		vkey = VK_RETURN;
		untoggle(vkey); 

		sleep(1);

		// Make sure that it is untoggled 
		if (GetKeyState(VK_RETURN) != 0) {
			goto loop; 
		}
		cout << "Enter status: " << (GetKeyState(VK_RETURN)) ? (cout << " - un-toggled\n") : (cout << " - toggled\n") << endl;
	} 


	cout << "Beginning in 3 seconds." << endl;
	sleep(3);
	cout << "READY AND WAITING!" << endl;
	cout << "======================================" << endl;  
	
	// Run until END key pressed
	while (!(GetKeyState(35) & 0x8000)) {

		// Request Win32 for keystates every loop 
		int w_pressed = (GetKeyState(87) & 0x8000); 
		int ctrl_pressed  = (GetKeyState(VK_CONTROL) & 0x8000);
		int space_pressed = (GetKeyState(VK_SPACE) & 0x8000);
		int r_pressed = (GetKeyState(82) & 0x8000);
		int enter_pressed = (GetKeyState(VK_RETURN));
/*

		// Detects W press (not including upgrades)
		if (w_pressed != 0 && ctrl_pressed == 0) {

			cout << "W press detected!\nChecking for availability!\n...\n...\n\n";

			// Start a timer to check for function duration  
			auto start_timer = std::chrono::high_resolution_clock::now();
			
			// Check if W first to avoid going into cardSelector() just to return 


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
			
			// Check if W first to avoid going into cardSelector() just to return

			// Click w
			WORD vkey = 0x57;
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

			// Lambda function for halting thread  
			auto waiter = [](int enter_pressed) {	// capture list[=][&]    [capture clause] (parameters) -> return-type {body}

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

			// Create a seperate thread to check if available
			std::thread thread_obj((LeagueProgram()));	// Used a thread in this instance to see if faster :-/ 
			thread_obj.join();
			
			cout << "R is available?  " << boolalpha << LeagueProgram::r_available << endl;

			// The ability is active! 
			if (LeagueProgram::r_available == true) {

				//sleep(1); // This is essential as if not here, the program will completely skip over the r repress check 

				// 	Start a time for max of 10 seconds
				auto start_timer = std::chrono::high_resolution_clock::now(); 
				std::chrono::duration<double> difference;
				cout << "Timer started!" << endl;
				
				do {
					// Detect a change in key state status 
					r_pressed = (GetKeyState(82) & 0x8000);

					// If r was repressed
					if (r_pressed != 0) {
						
						// Make sure that W is available to click 
						object1.available = object1.abilityAvaiablity('w');
						
						// Verify that W is available
						if (object1.available = true) {
							cout << "W is available!" << endl; 

							// Send W to start rotation 
							vkey = 0x57;
							object1.clickButton(vkey); 
							cout << "W clicked!" << endl; 

							// Match gold card 
							object1.cardSelector('g');
							cout << "Gold selected!" << endl;
						} else {
							cout << "W is not available! " << endl;

							// Create lambda thread to constantly check for w availability // 
							// ??????????????????????????????????????????????????????????? //
							// Create lambda thread to constantly check for w availability // 
						}
						sleep(1);
						break;
					}
					
					// Update countdown 
					auto stop_timer = std::chrono::high_resolution_clock::now(); 
					difference = chrono::duration_cast<chrono::duration<double>>(stop_timer - start_timer);
					
					cout << "R - timer: " << setprecision(2) << fixed << showpoint << difference.count() << "/10.0 seconds!" << endl; 

				} while (difference.count() < 10.0); // Could create a detatched thread here to constantly update color value // Replace this with checking ability availability! 

			} else {
				cout << "Ultimate not activated :(" << endl; 
			}
		}

		// Reset all flags 
		object1.available = false;
		object1.key_pressed = false; 
		LeagueProgram::r_available = false;
	}

	// Free allocated memory 
	//delete league; 

	return 0;
}

/*
		Debug for testing key input 
		if (r_pressed == 0) {
			cout << "Inactive! " << r_pressed << endl;
		} else if (r_pressed == 1) {
			cout << "Active! " << r_pressed << endl;
		} else {
			cout << "Unknown! " << r_pressed << endl;
		}
		sleep(1); 

*/




