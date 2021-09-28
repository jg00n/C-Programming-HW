/*
*    Design a simple program where:
*    
*    An array of five(5) integers called Integers is declared.
*    An array of six(6) real numbers called Reals is declared.
*    The program uses loops to have the user fill Integers with their desired values.
*    The program uses loops to have the user fill Reals with their desired values.
*    Minimumand Maximum are called on both arrays, storing the results.
*    The highestand lowest numbers of both arrays are printed on the screen.
* 
*    Jonathan Goon
*    4 / 18 / 21
*    Honor Code : "I have neither given nor received unauthorized aid in completing this work,
*    nor have I presented someone else's work as my own."
*
*	 
*/

#include "IO_text.h"
#include "Arrayfunct.h"
#include <string>		//Just to use the to_string function.

int main() {
	const int INTEG = 5, REALS = 6;
	int Integers[INTEG] = {0};
	double Reals[REALS] = {0};
	IO_text Message;

	Message.Show("Please enter the following:");
	Message.Show("Enter some integers below...");
	for (int i = 0; i < INTEG; i++) {
		std::string x = std::to_string(i + 1);
		Message.Prompt(Integers[i], "Enter the value for ", x);
	}
	Message.Show("Now enter some real numbers below...");
	for (int i = 0; i < REALS; i++) {
		std::string x = std::to_string(i + 1);
		Message.Prompt(Reals[i], "Enter the value for ", x);
	}
	Message.Show("Now finding values:");
	int		min_1 = Num::Minimum(Integers, INTEG),
			max_1 = Num::Maximum(Integers, INTEG);
	double	min_2 = Num::Minimum(Reals, REALS),
			max_2 = Num::Maximum(Reals, REALS);
	Message.Show("Minimum of Integer Array");
	std::cout << min_1 << "\n";
	Message.Show("Maximum of Integer Array");
	std::cout << max_1 << "\n";

	Message.Show("Minimum of Real Array");
	std::cout << min_2 << "\n";
	Message.Show("Maximum of Real Array");
	std::cout << max_2 << "\n";

	return 0;
}

