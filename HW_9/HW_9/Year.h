#pragma once
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
*/

#include <iostream>

class Year
{
private:
	int year;
	int days = 0;		//temp variable to hold days
public:
	
	//Constructor
	Year() {
		year = 1;
	}
	//Overloaded variant (redundant for conversion constructor).
	Year(int x) {
		year = 1;
		if (x == 1) days = 366;
		else days = 365;
	}
	//Accessors
	int getValue() const{
		//GetValue : This function returns the value of number.It should use the const keyword as outlined in Chapter 13.
		return year;
	}
	bool isLeap() const{
		//isLeap : This function returns the bool value true if the year would be a leap year, otherwise it returns false.
		if (year % 4 == 0) {
			if (year % 100 == 0) {
				if (year % 400 == 0) return true;
				else return false;
			}
			else return true;
		}
		else return false;

	}
	
	operator int(){
		//type conversion for int that returns the number of days in the year.
		return days;
	}

	//Mutator
	void setValue(int x) {
		//SetValue : This function sets the value of number.The year 0 does not exist, so if the user enters 0 it should default to 1.
		switch (x) {
		case 0: year = 1; break;
		default: year = x;
		}
	}
	
	//Friend Operators
	friend std::ostream& operator <<(std::ostream& stream, const Year obj) {
		//type conversion for int that returns the number of days in the year.
		std::string YN[2] = { "Yes","No" };
		int toggle = 1;
		if (obj.isLeap()) toggle = 0;

		//An operator overload for << that prints the value of number followed by BC if it's negative or AD if its positive.
		if (obj.year < 0) {
			stream << abs(obj.year) << " B.C.\n";
		}
		else {
			stream << obj.year << " A.D.\n";
		}
		Year i(obj.isLeap());		//Overloaded Constructor.
		int day = i;				//Conversion Operator.
		stream << "Days for this year: " << day << "\n";
		stream << "Is it a leap year?: " << YN[toggle] << "\n";

		return stream;
	}

};