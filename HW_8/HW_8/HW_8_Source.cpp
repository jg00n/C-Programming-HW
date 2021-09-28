/*
*    Design a class called Substance with the following member variables :
*
*    string name             : stores the name of the substance(ex.Oxygen)
*    double freezingPoint    : stores the freezing point of the substance
*    double boilingPoint     : stores the boiling point of the substance.
*    double temperature      : stores the current temperature of the substance
*
*    In addition to the appropriate accessorsand mutators, the class should have the following functions :
*
*    isBoiling: This function returns the bool value true if the value of temperature is at or above the boilingPoint, otherwise it returns false.
*    isFreezing : This function returns the bool value true if the value of temperature is at or below the freezingPoint, otherwise it returns false.
*    printSubstance : This function prints the name, freezingPointand boilingPoint in one line with tabulations in between so they're visually aligned.
*
*    Write a program that contains an array of objects of the Substance class and initialize them as the table above.It should then :
*
*    Use printSubstance to display the table as seen above.
*    Ask the user for the value of temperature of each objectand change it accordingly.
*    For each substance, report if it's freezing, boiling, or neither.
*
*    Submit the.cpp file with your main function, the.h file with your other functions, and one or more screenshots of your program running.
*
*    You must include your name and the honor code as a comment at the top of the file.
*
*    Jonathan Goon
*    3/28/2021
*   Honor Code: "I have neither given nor received unauthorized aid in completing this work,
*   nor have I presented someone else's work as my own."
*/

#include "IO_text.h"        //This file is reused. Check the Project Properties for info.
#include "Substance.h"

int main() {

	/*
	*Write a program that contains an array of objects of the Substance classand initialize them as the table above.It should then :
	*
	*	Use printSubstance to display the table as seen above.
	*	Ask the user for the value of temperature of each objectand change it accordingly.
	*	For each substance, report if it's freezing, boiling, or neither.
	*/
	const int	 SIZE		=  3;
	const double MIN_TEMP	= -459.17;		//Temp is in fahrenheit.
	IO_text message;
	Substance contents[SIZE] = {
		{"Ethyl Alcohol", -173,  172},
		{"Oxygen"		, -362, -306},
		{"Water"		,  32 ,  212}
	};
	message.Prompt("\t\tSubstances (Degrees F)");
	for (int i = 0; i < SIZE; i++) {
		contents[i].printSubstance();
	}
	message.Prompt("\nPlease enter the following:\n");
	for (int i = 0; i < SIZE; i++) {
		double input = 0;
		message.Prompt(input, "Please enter the temperature for ", contents[i].get_Name(), MIN_TEMP, INT_MAX);
		contents[i].set_Temp(input);
	}
	message.Prompt("\n\nResults:");
	for (int i = 0; i < SIZE; i++) {
		double getTemp = contents[i].get_Temp();
		//Rough string manipulation 
		std::string temp = std::to_string(getTemp);
		std::string temp_r = temp.substr(0, temp.find(".") + 3);

		std::string result = "The substance " + contents[i].get_Name() + contents[i].checkTemp(getTemp);
		std::string result2 = "Temp was recorded at: " + temp_r + " F";
		message.Prompt(result);
		message.Prompt(result2);
	}

	return 0;
}