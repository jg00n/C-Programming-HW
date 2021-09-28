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
*	This solution only uses the <iostream> class. Seems to be fairly quicker without loading the string class.
*
*/
#include "Ship.h"
#include "IO_text.h"

int main() {
	// Create ship pointers. also dynamic objects.
	const int OBJECT_SIZE = 5;
	Ship* ships[OBJECT_SIZE] = {
		new Ship(),
		new CruiseShip(),
		new CruiseShip(),
		new CargoShip(),
		new CargoShip()
	};
	IO_text Message;


	Message.Show("Created 5 ship objects...");
	//Display Created Objects.
	Message.Counter("\nShip ", OBJECT_SIZE, ships, true);
	
	Message.Show("Printed Ship information...setting ship information...");
	ships[0]->setName("USS Constitution");
	ships[0]->setYear("1797");
	Message.Show("Ship 1 is set.");

	//Requires pointers to derived class to access functions
	CruiseShip* cpoint[2] = { 
		static_cast<CruiseShip*>(ships[1]),
		static_cast<CruiseShip*>(ships[2])
	};
	cpoint[0]->setName("Symphony of the Seas");
	cpoint[0]->setCap("6680");
	Message.Show("Ship 2 is set.");

	cpoint[1]->setName("Queen Mary 2");
	cpoint[1]->setCap("2695");
	Message.Show("Ship 3 is set.");

	//Repetition since CargoShip is a derived class.
	CargoShip* dpoint[2] = { 
		static_cast<CargoShip*>(ships[3]),
		static_cast<CargoShip*>(ships[4])
	};
	dpoint[0]->setName("Aframax");
	dpoint[0]->setLoad("120000");
	Message.Show("Ship 4 is set.");

	dpoint[1]->setName("Ever Given");
	dpoint[1]->setLoad("220940");
	Message.Show("Ship 5 is set.");

	//Print again;
	Message.Counter("\nShip ", OBJECT_SIZE, ships);

	return 0;
}