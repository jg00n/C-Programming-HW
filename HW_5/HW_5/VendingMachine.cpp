/*
*	Jonathan Goon
*   2/28/21
*
*	Write a program that simulates a soft drink machine. The program should use a structure that stores the following data:
*
*   Drink Name
*   Drink Cost
*   Number of Drinks in Machine
*
*	The program should create an array of five (5) structures. The elements should be initialized with the following data:
*
*	Each time the program runs, it should enter a loop that performs the following steps:
*		1. A list of drinks is displayed on the screen, enumerated in the order they are shown.
*		2. The user should be allowed to either quit the program or pick a drink by entering the number associated to each drink.
*		3. If the user selects a drink that has sold out, a message should be displayed.
*		4. If the drink is still available, one drink of that type is subtracted.
*		5. The loop then repeats
*
*	When the user chooses to quit the program, it should display the total amount of money the machine earned.
*
*   Honor Code: "I have neither given nor received unauthorized aid in completing this work,
*   nor have I presented someone else's work as my own."
* 
*	Modified 3/27/21 to support binary file operations.
*/
#include "VMachDep.h"
#include "FileOps.h"

int main() {
	int counter[3] = { 0 };
	const int SIZE = 5;
	//Please enable debug if you wish to see all output.
	bool trigger = false, enabledebug = true;
	std::cout << std::fixed << std::setprecision(2);

	drinkMachine drink[SIZE];
	ifInput(drink);

	while (!trigger) {

		//Prompt user to select drink.
		//Also displays drink options.
		//Toggle 3rd parameter (T/F) to see entire contents of output.
		trigger = drinkSelector(drink, SIZE, enabledebug);

		bool uponexit = false;
		while (!uponexit) {
			std::cout << "Are you sure you wish to quit? (y/n): ";
			char input;
			std::cin >> input;
			switch (tolower(input)) {
			case 'y': {uponexit = true; trigger = true ; break; }
			case 'n': {uponexit = true; trigger = false; break; }

			default:
				std::cout << "Invalid input! Try again.\n";
			}

			cinCleanup();
		}
	}
	drinkSummary(drink, SIZE);
	//Updates contents of file before closing.
	ofOutput(drink);
	system("pause");
	return 0;
}