#pragma once

/*
*	Jonathan Goon
*   2/16/21
*
*	Imagine you are developing a software package that requires users to enter their own package. Your software requires that users' passwords meet the following criteria:
*
*   The password should be at least six characters long.
*   The password should contain at least one uppercase and at least one lowercase letter.
*   The password should have at least one numeric digit.
*
*	Write a program that asks for a password then verifies that it meets the stated criteria. If it doesn't the program should display a message telling the user why and allow them to try again.
*
*   Honor Code: "I have neither given nor received unauthorized aid in completing this work,
*   nor have I presented someone else's work as my own."
*/


#include <iostream>
#include <string>

using namespace std;

void PassCheck(char*);
bool PassLength(char*);
void PassComplex(char*, bool);

void Cleanup();


void PassCheck(char* ptr) {
	//Single call for other 2 functions.
	bool flags = PassLength(ptr);
	PassComplex(ptr, flags);

}

bool PassLength(char *ptr) {
	const int MIN = 6, MAX = 20;
	int eval = strlen(ptr);
	bool fail = false;
	//Check password length requirements
	if (eval >= MIN && eval <= MAX) {
		//Do not do additional validation if it is within the length requirements.
		//Could also put a flag here in the event that it's true
	}
	else {
		 fail = true;
		cout << "Password must contain at ";
		if (eval < MIN)
			cout << "least "<< MIN;
		else
			cout << "most " << MAX;

		cout << " characters!\n";
	}
	return fail;
}

void PassComplex(char* ptr, bool fail) {
	//Bool array to verify string conditions
	bool cond[3] = { false };

	//Perform evaluation on each character of the array.
	for (int i = 0; i < signed(strlen(ptr)); i++) {

		if (isupper(ptr[i])) cond[0] = true;
		if (islower(ptr[i])) cond[1] = true;
		if (isdigit(ptr[i])) cond[2] = true;
	}

	//Check array contents for prompt

	for (int i = 0; i < (sizeof(cond)/sizeof(cond[0])); i++) {
		switch (cond[i]) {
			case true: break;
			default: {
				fail = true;
				cout << "Password must contain at least one ";

				switch (i) {
				case 0: cout << "uppercase character!"; break;
				case 1: cout << "lowercase character!"; break;
				case 2: cout << "digit!"; break;
				}
				cout << "\n";
			}

		}
	}
	if (!fail) cout << "Your password has been accepted...\n";

}

void Cleanup() {
	//Clears out cin buffer to prevent enviroment contamination.
	cin.clear();
	cin.ignore(256, '\n');
}
