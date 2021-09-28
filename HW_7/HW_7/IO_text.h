#pragma once
/*======================================================================================================================
* 
*	Jonathan Goon
* 
*	This is a input/ output handler for iostream validation.
*	mainly with anything that uses cin / cout.
* 
*	Currently a WIP
*	version 0.1
*	3/21/2021
* 
*   Honor Code: "I have neither given nor received unauthorized aid in completing this work,
*   nor have I presented someone else's work as my own."
* 
=======================================================================================================================*/
#include <iostream>
#include <string>
class IO_text
{
private:
	std::string text;
	int		integer;
	double	decimal;
	char	character;
	
	bool debug = false, trigger = false;

	//Error Prompts
	const std::string P0_Error[3] = {
		"ERROR: Invalid input, ",
		"ERROR: Invalid input!\n",
		"ERROR: "
	};
	const std::string P1_Error[4] = {
		"The value you entered was: ",
		"Only numeric values can be accepted.\n",
		"Only text input can be accepted.\n"
		"Only a character can be accepted.\n"
	};
	const std::string P2_Error[3] = {
		"\nThat value is too low, ",
		"\nThat value is too high, ",
		""
	};
	const std::string P3_Error[3] = {
		" is the minimum.\n",
		" is the maximum.\n",
		""
	};
	const std::string E1_Error = "please try again!\n";

public:
	IO_text(){
		// default constructor.
		text = "";
		integer = 0;
		decimal = 0.0;
		character = ' ';
		trigger = false;
	
	}
	//Mutators
	//Input overloads (to store in the class)
	void Input() {
		std::cout << "No input detected.\n";
	}
	void Input(double x) {
		std::cout << "Numeric value detected.\n";
		integer = (int)round(x);
		decimal = x;
	}
	void Input(char x) {
		std::cout << "Character detected.\n";
		character = x;
	}
	void Input(std::string x) {
		std::cout << "String detected.\n";
		text = x;
	}
	//Prompt Overloads
	void Prompt(std::string message) {
		std::cout << message << "\n";
	}
	template <class Type>
	void Prompt(Type &input, const std::string message, bool longer) {
		//Prompt for input with no constraints aside from invalid types in some cases.
		//Longer is not an optional parameter to prevent confusion with the next overload.
		while (true) {
			std::cout << message;
			//If longer is false, assume that it's 1 word. Else, assume a sentence.
			if (!longer) {
				if (std::cin >> input) {
					clear();
					return;
				}
				else {
					clear();
					std::cout << P0_Error[1] << E1_Error;
				}
			}
			else {
				if (std::getline(std::cin, input)) {
					clear();
					return;
				}
				else {
					clear();
					std::cout << P0_Error[1] << E1_Error;
				}
			}
		}
	}
	template <class Type>
	void Prompt(Type & input, const std::string message, double min = -99999.99, double max = 99999.99) {
		//Prompt for input with numeric limitations of min and max.
		//Defaults limits implemented.
		while (true) {
			std::cout << message;
			if (std::cin >> input) {
				clear();
				if		(input < min) std::cout << P0_Error[0] << P1_Error[0] << input << P2_Error[0] << min << P3_Error[0] << E1_Error;
				else if (input > max) std::cout << P0_Error[0] << P1_Error[0] << input << P2_Error[1] << max << P3_Error[1] << E1_Error;
				else	return;
			}
			else {
				clear();
				std::cout << P0_Error[0] << P1_Error[1] << E1_Error;
			}
		}

	}
	//Accessors

	void clear() {
		// Clears cin buffer before continuing
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	}
};

