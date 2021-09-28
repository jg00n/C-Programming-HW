/*
*    Design a class called Year with the following member variables :
*    
*    integer number : Represents the year number.i.e. 2021
*    
*    The class should have the following functions :
*    
*    A default constructor that sets value to 1.
*    GetValue : This function returns the value of number.It should use the const keyword as outlined in Chapter 13.
*    SetValue : This function sets the value of number.The year 0 does not exist, so if the user enters 0 it should default to 1.
*    isLeap : This function returns the bool value true if the year would be a leap year, otherwise it returns false.
*    An operator overload for << that prints the value of number followed by BC if it's negative or AD if its positive.
*    A type conversion for int that returns the number of days in the year.
*    
*    Write a program that :
*    
*    Declares an object of the class.
*    Asks the user for the year number.
*    Use the overloaded << operator to display the year, followed by the amount of days it has, and whether it is a leap year.
*    
*    Hint :
*    
*        Wikipedia has a very useful pseudo code on how to determine if a year is leap.
*    
*        Submit the.cpp file with your main function, the.h file with your other functions, and one or more screenshots of your program running.
*    
*        You must include your name and the honor code as a comment at the top of the file.
* 
*	Jonathan Goon
*	4/4/2021
* 
*   Honor Code: "I have neither given nor received unauthorized aid in completing this work,
*   nor have I presented someone else's work as my own."
*	
*/

#include "Year.h"
#include "IO_Text.h"

int main() {
	///Declares an object of the class.
	char ans;
	do {
		Year date;
		IO_text message;
		int temp;
		//Asks the user for the year number.
		message.Prompt(temp, "Please enter the number of the year: ");
		date.setValue(temp);
		//Use the overloaded << operator to display the year, followed by the amount of days it has, and whether it is a leap year

		std::cout << date;
		//Quick repeat prompt.
		message.Prompt("Do you wish to try another value?\nEnter y to continue, otherwise enter any key to exit...");
		std::cin >> ans;
		message.clear();
	} while (toupper(ans) == 'Y');

	return 0;
}