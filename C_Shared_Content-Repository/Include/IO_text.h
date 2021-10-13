#pragma once
/*======================================================================================================================
* 
*	Jonathan Goon
* 
*	This is a input/ output handler for iostream validation.
*	mainly with anything that uses cin / cout.
* 
*	Currently a WIP
*	version 0.3.2
*	10/04/2021
* 
*   Honor Code: "I have neither given nor received unauthorized aid in completing this work,
*   nor have I presented someone else's work as my own."
* 
=======================================================================================================================*/
#include <iostream>
//Removed String class for optimization. Seems to be quicker.
class IO_text {
private:
	std::string text;
	int		integer;
	double	decimal;
	char	character;
	
	bool debug   = false,					//Toggle Debug.
		 trigger = false,					//Trigger
		 visible = false;					//Toggle Output

	//Error Prompts
		
		const std::string P0_Error[4] = {
			"ERROR: Invalid input, ",
			"ERROR: Invalid input!\n",
			"ERROR: Invalid limit!\n",
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
		const std::string E1_Error = "Please try again!\n\n";
	
protected:

public:
	// default constructor.
	IO_text(){
		text		= "";
		integer		= 0;
		decimal		= 0.0;
		character	= ' ';
	}

	//Mutators
	
	int stoi(std::string x) {
		//stoi alternative.

		int number = 0;
		for (auto ch : x) {
			number = (number * 10) + (ch - '0');
		}
		return number;

	}

	//Show Overloads (output only)
	void Show(std::string message) const{
		//Spit out 1 message with newline.
		std::cout << message << "\n";
	}	
	void Show(std::string message, std::string message2) const {
		//Spit out a concatenated message with newline
		std::cout << message << message2 << "\n";
	}
	template <class Type>
	void Show(std::string message, Type &value , char optional =  ' ') const{
		//Spit out message, value with newline.

		std::cout << message << value << optional << "\n";

	}

	//Count Overloads (output with counter)
	template <class Obj>
	void Counter(std::string message, const int &limit,const Obj& Object, bool vary = false) const{
		/*
		*	Prints Message counting up (false) or down (true). 
		*	Parameters are ( message, value, vary (optional)). 
		*	Requires an object with its own print function.
		*	Default is to count up.
		*/
		try {
			if (!vary) {

				for (int i = 0; i < limit; i++) {
					int x = i + 1;
					Show(message, x);
					Object[i]->print();
				}

			}	//Count Up;
			else {

				for (int i = limit - 1; i >= 0; i--) {
					int x = i + 1;
					Show(message, x);
					Object[i]->print();
				}

			}	//Count Down;
		}
		catch (const std::exception& e) {
			if (limit < 1) {
				Escape(P0_Error[3]);
			}
			else {
				Escape(P0_Error[3] + e.what());
			}
		}
	}
	//Escape Overloads (output for errors)
	void Escape(std::string message) const{
		//Used for premature exits
		std::cout << message << "\n";
		exit(EXIT_FAILURE);
	}

	//Quick continue prompt (only returns true or false.)
	bool Question(const std::string message = "continue") {
		char input =' ';

		do {
			std::cout << "Do you wish to " << message << "?(Y/N):\n";
			std::cin >> input;
			clear();
			input = tolower(input);
			if (input == 'y') return true;
			if (input == 'n') return false;
			
		}while (input != 'y' && input != 'n');
		return NULL;
	}
	//Prompt Overloads (input with reference modification).
	template <class Type>
	void Prompt(Type &input, const std::string message, bool longer) {
		//Prompt for input with no constraints aside from invalid types in some cases.
		//Longer is not an optional parameter to prevent confusion with the next overload.
		while (true) {
			std::cout << message;
			//If longer is false, assume that it's 1 word.
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
			//If longer is true, assume that it's a sentance.
			else {
				if (std::istream::getline(std::cin >> std::ws, input)) {
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
		//Prompt for input with numeric limitations of min and max. (1 Message).
		//Defaults limits implemented.
		while (true) {
			std::cout << message;
			if (std::cin >> input) {
				clear();
				//Input is less than minimum.
				if (input < min) std::cout << P0_Error[0] << P1_Error[0] <<
					input << P2_Error[0] << min << P3_Error[0] << E1_Error;
				//Input is greater than maximum.
				else if (input > max) std::cout << P0_Error[0] << P1_Error[0] <<
					input << P2_Error[1] << max << P3_Error[1] << E1_Error;
				//Input is good.
				else	return;
			}
			else {
				//Input is not the one we are looking for.
				clear();
				std::cout << P0_Error[0] << P1_Error[1] << E1_Error;
			}
		}

	}
	template <class Type>
	void Prompt(Type & input, const std::string message, const std::string message2, double min = -99999.99, double max = 99999.99) {
		//Prompt for input with numeric limitations of min and max. (2 Messages).
		//Defaults are implemented unless specified.
		
		while (true) {
			std::cout << message << message2 << ": ";
			if (std::cin >> input) {
				clear();
				//Input is less than minimum.
				if		(input < min) std::cout << P0_Error[0] << P1_Error[0] << 
						input << P2_Error[0] << min << P3_Error[0] << E1_Error;
				//Input is greater than maximum.
				else if (input > max) std::cout << P0_Error[0] << P1_Error[0] << 
						input << P2_Error[1] << max << P3_Error[1] << E1_Error;
				//Input is good.
				else	return;
			}
			else {
				//Input is not the one we are looking for.
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

