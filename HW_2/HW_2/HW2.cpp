/*
*
*   Jonathan Goon
*   2/7/21
*
*   HW 2
*
*	Write a program that lets the user enter a charge account number. The program should determine if the number if valid by checking for it in the given pre-sorted filePreview the document using Binary Search. The numbers should be initialized into a vector (Links to an external site.).
*
*	If the user enters a number in the array, the program should display a message saying the number is valid.
*
*	If the user enters a number that is not in the array, the program should display a message indicating the number is invalid.
*
*   Honor Code: "I have neither given nor received unauthorized aid in completing this work,
*   nor have I presented someone else's work as my own."
*
*/


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main() {

	int valuecheck;
	bool repeat = false, trigger = false;
	char toggle;
	vector <int>listings;

	//Throw File into same repository for script to find it.
	ifstream Compare("Homework2_Input.txt");
	if (Compare) {
		int value;

		while (Compare >> value) {

			listings.push_back(value);

		}
	}
	else
	{
		cout << "File not found!\n";
		return 0;
	}

	do {
		//While loop to check for proper int input.
		while (true) {
	
			cout << "Enter an account #: ";
			cin >> valuecheck;

			if (cin.fail())
				//Was getting weird closing quote errors here. Not sure why.
				cout << "Invalid Entry, please enter a number!\n";
			else break;

			cin.clear();
			cin.ignore(256, '\n');
		}

	//Search occurs below.
	

		//if (find(listings.begin(), listings.end(), valuecheck) != listings.end()) {
		//	cout << "the number is valid.\n";
		//}
		//Linear Search
		//for (int i = 0; i < listings.size(); i++) {
		//	if (valuecheck != listings.at(i));
		//	else trigger = true;
		//}

		//Binary Search
		int start = 0, middle, end;
		bool check = false;
		end = listings.size();

		while (!trigger && start <= end) {
			// Resets middle of list with each iteration. Divide in half for average
			middle = (start + end) / 2;
			if (listings.at(middle) == valuecheck) {
				trigger = true;
				break;
			}
			else if (listings.at(middle) > valuecheck) end = middle - 1;	//If number is larger, decrease last in half.
			else start = middle + 1;										//If number is smaller, increase first by half.  
		}


		if (trigger) cout << "The number is valid.\n";
		else cout << "the number is invalid.\n";
		//Quick Reset
		trigger = false;
		while (true) {
			cout << "Do you wish to search for another number (y/n)? :";
			cin >> toggle;
			if (cin.fail()) {
				cout << "Invalid Input! Try again!\n";
			}
			//This is toggled if the the user wants to repeat a check.
			if (toggle == 'y') break;
			else if (toggle == 'n') {
				repeat = true;
				break;
			}
			else { cout << "Invalid Input! Try again!\n"; }

			cin.clear();
			cin.ignore(256, '\n');
		}
	} while (!repeat);

	system("pause");
	return 0;
}
