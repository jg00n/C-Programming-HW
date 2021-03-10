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

#include "PassAuth.h"
//All Dependancies are located in the header

int main() {
	//Threw in arbitrarily large length for now, will have overflow errors upon termination once input exceeds array size.
	//Did not figure out solution yet.
	char query[256] = {""};
	bool trigger = true;
	
	while (trigger) {
		
		cout << "Please enter a password (max length 20 characters!):\n";
		cin >> query;
		cout << "\n";
		PassCheck(query);

		bool uponexit = false;
		while (!uponexit) {
			cout << "Do you wish to try again? (y/n): ";
			char input;
			cin >> input;
			switch (tolower(input)) {
			case 'y':  uponexit = true; break;
			case 'n': {uponexit = true; trigger = false; break;}
				
			default:
				cout << "Invalid input! Try again.\n";
			}

			memset(query, 0, sizeof(query));
			Cleanup();
		}
	}


	system("pause");
	return 0;
}