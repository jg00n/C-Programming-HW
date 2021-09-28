#pragma once

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
* 
*/
#include <iomanip>

class Substance
{
private:
	std::string name;
	double freezingPoint;
	double boilingPoint;
	double temperature;

	//Private Accessors
	bool isBoiling(double value) const {
		//isBoiling: This function returns the bool value true if the value of temperature is at or above the boilingPoint, otherwise it returns false.
		if (value > boilingPoint) return true;
		else return false;
	}
	bool isFreezing(double value) const {
		//isFreezing: This function returns the bool value true if the value of temperature is at or below the freezingPoint, otherwise it returns false.
		if (value < freezingPoint) return true;
		else return false;
	}
public:
	//Constructors
	Substance() {
		//Default Constructor
		name			=  "";
		freezingPoint	= -9999.99;
		boilingPoint	=  9999.99;
		temperature		=  0.0;
	}
	Substance(std::string w, double x, double y, double z) {
		name			= w;
		freezingPoint	= x;
		boilingPoint	= y;
		temperature		= z;
	}
	Substance(std::string w, double x, double y) {
		name			= w;
		freezingPoint	= x;
		boilingPoint	= y;
		temperature		= 0.0;
	}
	//Accessors Functions
	std::string checkTemp(double & temp) {
		if (isBoiling(temp)) {
			return " is boiling.";
		}
		else if (isFreezing(temp)) {
			return " is freezing.";
		}
		else return " is neither freezing or boiling.";
	}
	void printSubstance(int decim = 2) {
		//printSubstance: This function prints the name, freezingPointand boilingPoint 
		//in one line with tabulations in between so they're visually aligned.
		int wid = 15;
		/*
		*	std::cout << std::left << std::setprecision(decim) <<std::fixed;
		*	std::cout << std::setw(wid) << name <<
		*		std::setw(wid) << freezingPoint <<
		*		std::setw(wid) << boilingPoint << "\n";
		*	
		*	Old version, did not align output nicely.
		*/
		printf("%-*s %*.2f %*.2f\n", wid, name.c_str(), wid, freezingPoint, wid, boilingPoint);
	}
	//Accessors
	double get_Freeze()		const{
		return freezingPoint;
	}
	double get_Boil()		const{
		return boilingPoint;
	}
	std::string get_Name()	const{
		return name;
	}
	double get_Temp()		const{
		return temperature;
	}
	//Mutators
	void set_Freeze(double x) {
		freezingPoint = x;
	}
	void set_Boil(double x)		{
		boilingPoint = x;
	}
	void set_Name(std::string x) {
		name = x;
	}
	void set_Temp(double x) {
		temperature = x;
	}
};

