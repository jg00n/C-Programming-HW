#pragma once

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
* Modified 3/27/21 to support binary file operations.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

//Avoiding "using namespace std" as it's a bad practice.

enum Type {
	Soda,
	Juice,
	Water
};
struct drinkMachine {
	//Originally string, converted to character array for structure - binary file operations.
	char		id[20];
	Type		type;
	double		cost;
	int			quantity;
	// Below variables are used for recording data.
	double		sales		= 0;
	int			unitsold	= 0;
};

void displayContents(drinkMachine*, size_t, bool);
void displaySummary (drinkMachine*, size_t);
bool drinkSelector	(drinkMachine*, size_t, bool);
std::string drinkType(int);
void cinCleanup();

void displayContents(drinkMachine *contents, size_t arraylength, bool viewall = false) {
	//Display drinks and costs.
	std::cout <<'\n' <<std::left << std::setw(11) << "Selection" << std::setw(15) 
		<< "Drinks" << std::setw(12) << "Type" << std::setw(8) << "Cost";
	if (viewall) {
		//Display Inventory and sales (Occurs at the end of sequence, "customer" will not see inventory like most drink vending machines).
		std::cout << std::setw(13) << "Inventory" << std::setw(10) << "Sales" << std::setw(10) <<"Units Sold";
		
	}
		std::cout << "\n\n";
	for (size_t i = 0; i < arraylength; i++) {
		std::string text;
		//enum returns array index.
		
		//Display the drink.
		std::cout << i + 1 << std::setw(10) << ':' <<std::setw(15) << contents[i].id << std::setw(10) 
			<< drinkType(contents[i].type) << " $" << std::setw(11) << contents[i].cost ;
		//Display sales of the drink.
		if (viewall) {
			std::cout << std::setw(10) << contents[i].quantity << '$' <<std::setw(14) 
				<< contents[i].sales << std::setw(10) << contents[i].unitsold;
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}
bool drinkSelector(drinkMachine *contents, size_t arraylength, bool debugger = false) {
	while (true) {
		if (!debugger)system("CLS");
		//Displays contents in loop.
		displayContents(contents, arraylength);

		//Input declaration, resets input to NULL to prevent contamination.
		char input = NULL;
		bool inval[2] = { false };

		//Prompt user of selection
		std::cout << "Please enter a number to select a drink, or press 'q' to quit: ";
		std::cin >> input;

		if (std::cin.fail()) std::fill_n(inval,2,true);
		else {
			if (std::isalpha(input)) {
				switch (std::tolower(input)) {
					case 'q': 
						return true; break;
					default: 
						std::fill_n(inval, 2, true);
				}
			}
			else if (std::isdigit(input)) {
					int val = (input - '0');
					--val;
					if (0 <= val && val < (int)arraylength) {
						if (contents[val].quantity <= 0) {
							std::cout << "Sorry, we are out of " << contents[val].id << ',';
							inval[1] = true;
						}
						else {
							std::cout << "A " << contents[val].id << " was dispensed.\n";
							contents[val].quantity--;
							contents[val].unitsold++;
							contents[val].sales = contents[val].sales + contents[val].cost;
						}
					}
					else {
						std::cout << "Drink not found! ";
						inval[1] = true;
					}
			}
			else {
				//Symbols and of the like.
				std::fill_n(inval, 2, true);
			}
			if (inval[0]) std::cout << "Invalid Input!";
			if (inval[1])std::cout << " try again!\n";
		}
		//Pause contents for readability.
		if(!debugger)system("pause");
		cinCleanup();
	}

		
}

std::string drinkType(int id) {
	//enum returns array index.
	switch (id) {
	case 0:	return "Soda"; break;
	case 1:	return "Juice"; break;
	case 2:	return "Water"; break;
	default:return "N/A";
	}
}
void drinkSummary(drinkMachine *contents, size_t arraylength) {
	double totals = 0;
	int types[3] = {0};
	//Produces the results of the sales.
	std::cout << "\nVending Machine Summary:\n\n";
	displayContents(contents, arraylength, true);

	std::cout << "Total Sales: $";
	for (size_t i = 0; i < arraylength; i++) {
		totals = totals + contents[i].sales;
		//Adds drink type sold by # of units.
		switch (contents[i].type) {
		case 0: types[0] = types[0] + contents[i].unitsold; break;
		case 1: types[1] = types[1] + contents[i].unitsold; break;
		case 2: types[2] = types[2] + contents[i].unitsold; break;
		}
	}
	std::cout << totals << '\n';
	for (int i = 0; i < sizeof(types)/sizeof(types[0]); i++) {
		std::cout << std::setw(6) <<drinkType(i) << "sold : " << types[i]<< '\n';
	}

}
void cinCleanup() {
	std::cin.clear();
	std::cin.ignore(256, '\n');
}