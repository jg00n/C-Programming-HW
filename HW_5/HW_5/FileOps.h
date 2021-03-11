#pragma once

/*
* 
*	Jonathan Goon
*	3/7/2021
* 
*	Modify your program from Homework 5 (or a copy of it) to include the following:
*	(For clarity sake, I will be referring to the "array of structures" described in Homework 5 as Beverages)
*
*    When the program is executed, it checks if a file "SodaDatabase.dat" exists.
*        If it doesn't: The program should create the file, define Beverages with the default values from Homework 5, and write it to said file. Then continue normally.
*        If it does: The program should read the file and fill Beverages with the data in it. Then continue normally.
*    When the user decides to exit, the program should 'update' the file by clearing it and writing Beverages into it.
* 
*	NOTE: This version will "continue off" with previously created data as if the user did not quit. Did not elaborate on functions such as
*	restocking, number of sessions, etc. since it was not required. Resetting occurs when the data file is deleted.
*
*   Honor Code: "I have neither given nor received unauthorized aid in completing this work,
*   nor have I presented someone else's work as my own."
*/


#include <fstream>
#include "VMachDep.h"

void ifInput	(drinkMachine*);
inline bool ifCheck(const std::string&);
void ifCreate	(const std::string&, bool);
void ifRead		(const std::string&, drinkMachine*&, const int);
void ofWrite	(const std::string&, drinkMachine*&, const int);
void Term		(int);


class fileDef {
	public:
		std::string name = "SodaDatabase.dat";
		//const int does not work in ifCreate.
		const int SIZE = 5;
};

void ifInput(drinkMachine *drinkStruct) {
	fileDef def;
	bool check;
	//Only gives T/F statement if file exists.
	check = ifCheck(def.name);
	//NOTE: There is no implementation of checking if the data is valid in this scenario.
	//Only used to create the file.
	ifCreate(def.name, check);
	//Check if condition is good before continuing.
	ifRead(def.name, drinkStruct, def.SIZE);

}
void ofOutput(drinkMachine *drinkStruct) {
	fileDef def;
	ofWrite(def.name, drinkStruct, def.SIZE);
}

inline bool ifCheck(const std::string& File) {
	//Check if file exists.
	struct stat buffer;
	return (stat(File.c_str(), &buffer) == 0);
}

void ifCreate(const std::string & name,bool fExist) {
	std::fstream File;
	std::cout << "Searching for " << name << "\n";
	switch (fExist) {
		case true: {
			//This section is fairly redundant.
			std::cout << "File: " << name << " exists...\nReading contents...\n";
			Term(0);
			break;
		}
		default: {
			const int SIZE = 5;
			//Default Contents of the vending machine.
			drinkMachine defaultval[SIZE] = {
			{"Koka Cola"	, Soda,	0.75,	20},
			{"Spritz"		, Soda,	0.75,	20},
			{"Hourly Butler", Juice,0.80,	15},
			{"Bright-C"		, Juice,0.80,	20},
			{"Huron"		, Water,1.00,	12}
			};
			std::cout << "File " << name << " does not exist, creating a new file...\n";
			//Truncate is used to ensure its a clean enviroment. (Just in case)
			File.open(name, std::ios::out | std::ios::trunc | std::ios::binary);
			for (size_t i = 0; i < (size_t)SIZE; i++) {
				File.write(reinterpret_cast<char*>(&defaultval[i]), sizeof(drinkMachine));
			}
			//Close file. Upon errors, terminate application.
			File.close();
			if (!File.good()) {
				std::cout << "Error occured while generating " << name << "!\n";
				Term(1);
			}
			else Term(0);

		}

	}
}
void ifRead(const std::string& File, drinkMachine *& content, const int SIZE) {
	//Occurs while reading a file. No checks implemented here since the prior functions take care of it.
	std::ifstream inFile(File, std::ios::in | std::ios::binary);
	for (size_t i = 0; i < (size_t)SIZE; i++) {
		inFile.read(reinterpret_cast<char*>(& content[i]), sizeof(drinkMachine));
	
	}
	//Close file. Upon errors, terminate application.
	inFile.close();
	if (!inFile.good()) {
		std::cout << "Error occured at read time!\n";
		Term(1);
	}
	else Term(0);
}
void ofWrite(const std::string& File, drinkMachine*& content, const int SIZE) {
	//Occurs while saving a file.
	std::cout << "Writing contents to file\n";
	//Truncate is used to ensure its a clean enviroment. (Just in case) (Duplicate)
	std::ofstream inFile(File, std::ios::out | std::ios::trunc | std::ios::binary);
	for (size_t i = 0; i < (size_t)SIZE; i++) {
		inFile.write(reinterpret_cast<char*>(&content[i]), sizeof(drinkMachine));
	}
	//Close file. Upon errors, terminate application.
	inFile.close();
	if (!inFile.good()) {
		std::cout << "Error occured while writing to " << File << "!\n";
		Term(1);
	}
	else { 
		std::cout << "Writing to " << File << " complete!\n";
		Term(0); }

}
void Term(int code) {
	//Emulate script end conditions
	switch (code) {
		case 0:break;
		default:
			exit(code);
	}

}