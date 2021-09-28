#pragma once

/*
*    Design a Ship class that has the following members :
*    
*    A protected member variable called Name for the name of the ship(a string).
*    A protected member variable called YearBuilt for the YearBuilt the ship was built(an integer).
*    A constructor.
* 
*    Appropriate accessors.
*    Appropiate mutators.
*    A virtual Print function that displays the ship's name and the YearBuilt it was built.
*    
*    Design a CruiseShip class that is derived from the Ship class.It should have the following members :
*    
*    A private member variable called MaxP for the maximum number of passengers(an integer).
*    A constructor.
*    Appropriate accessors.
*    Appropiate mutators.
*    A Print function that displays the ship's name, the YearBuilt it was built, and the maximum number of passengers.
*    
*    Design a CargoShip class that is derived from the Ship class.It should have the following members :
*    
*    A private member variable called Capacity for the cargo capacity in tonnage(an integer).
*    A constructor.
*    Appropriate accessors.
*    Appropiate mutators.
*    A Print function that displays only the ship's name and the ship's Capacity.
*    
*    Demonstrate the classes in a program that has an array of five(5) Ship pointers.The array elements should be 
*    initialized with the addresses of dynamically allocated Ship, CruiseShip, and CargoShip objects.
*    The program should then step through the array using a loop, calling each object's Print function.
* 
*	Jonathan Goon
*	4/11/21
*   Honor Code: "I have neither given nor received unauthorized aid in completing this work,
*   nor have I presented someone else's work as my own."
* 
*	Since this sample has been already made for a prior course, this is just a refactored version.
*	
*/
#include "IO_text.h"
class Ship {
private:

protected:
	std::string name;
	std::string YearBuilt;
	const unsigned short AGE = 1700;
	//Used for internal message handling.
	IO_text Message;

public:
	//Default Constructor
	Ship() {
		//Default Values
		name = "";
		YearBuilt = "1800";
	}
	Ship(std::string x, std::string y) {
		name = x;
		YearBuilt = y;

	}
	//Accessors
	std::string getName() const{
		return name;
	}
	std::string getYear() const{
		return YearBuilt;
	}
	
	//Mutators
	void setName(std::string x) {
		name = x;
	}
	void setYear(std::string x) {
		YearBuilt = x;
	}
	//Virtual Print function
	virtual void print() const {
		std::cout << "Ship name: " << name << ", built: " << YearBuilt << "\n";
	}
};

//Derivative class Cruise Ship of Class Ship.
class CruiseShip : public Ship {
private:
	int MaxP;

	void CapVer(int cap) {
		//Handles MaxP verification
		try {
			if (cap < 0) {
				Message.Show("Cannot accept an negative passenger capacity!");
			}
			else {
				MaxP = cap;
			}
		}
		catch (...) {
			// Catch all errors.
			Message.Show("Invalid input in Capacity Assignment!");
		}
	}
public:
	CruiseShip() : Ship() {
		// Default constructor that also calls upon parent class.
		// Set passenger MaxP to 0.
		MaxP = 0;
	}

	CruiseShip(int cap, std::string x, std::string y) :Ship(x, y) {
		//Cruise Ship overload constructor that calls on parent overload.
		//Goes to private function that verifies MaxP
		CapVer(cap);
	}
	//Accessors
	int getCap() const {		
		return MaxP;
	}
	//Mutators
	void setCap(std::string val) {
		if (isdigit(val[0])) {
			int temp = Message.stoi(val);
			//Goes to private function that verifies MaxP
			CapVer(temp);
		}
		else Message.Show("Capacity only accepts numeric input!");
	}
	//Print override.
	virtual void print() const {
		std::cout << "Ship name: " << name << ", Capacity: " << MaxP << "\n";
	}
};

//Derivative class Cargo Ship of Class Ship.
class CargoShip : public Ship {
private:
	int Capacity = 0;

	void CapVer(int cap) {
		//Handles capacity verification (Copied over)
		try {
			if (cap < 0) {
				Message.Show("Cannot accept an negative Payload capacity!");
			}
			else {

				Capacity = cap;
			}
		}
		catch (...) {
			// Catch all errors.
			Message.Show("Invalid input in Payload Assignment!");
		}
		
	}
public: 
	CargoShip() : Ship() {
		// Default constructor that also calls upon parent class.
		// Set Capacity capacity to 0.
		Capacity = 0;
	}

	CargoShip(int cap, std::string x, std::string y) :Ship(x, y) {
		//Cargo Ship overload constructor that calls on parent overload.
		//Goes to private function that verifies capacity
		CapVer(cap);
	}
	
	//Accessors
	int getLoad() const {
		return Capacity;
	}
	//Mutators
	void setLoad(std::string val) {
		if (isdigit(val[0])) {
			int temp = Message.stoi(val);
			//Goes to private function that verifies capacity
			CapVer(temp);
		}
		else Message.Show("Payload only accepts numeric input!");
	}
	//Print override.
	virtual void print() const {
		std::cout << "Ship name: " << name << ", Max Tonnage: " << Capacity << "\n";
	}
};