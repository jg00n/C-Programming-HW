/*
*
*   Jonathan Goon
*   2/14/21
*
*   HW 3
*
*	Write the following a functions:
*
*	One that accepts an ifstream and a pointer to an int array as arguments. The function should ask the user for the number of elements in said list,
*	create a dynamic array, and store the values from the file into it. The function should return the length of the new array.
*
*	One that accepts a pointer to an int array, and the array's size as arguments. The function should create a copy of the array, 
*	except that the elements should be be in reverse order in the copy. The function then returns a pointer to the new array.
* 
*	Demonstrate both functions in a single program that reads numbers from a file and prints the reversed list on screen. Do not use
*	vectors. Remember that ifstream must be passed by reference.
* 
*	Honor Code: "I have neither given nor received unauthorized aid in completing this work,
*   nor have I presented someone else's work as my own."
*
*/

#include "Functions.h"
//All libraries are in the header file. 


int main() {
    //create a ifstream object
    ifstream file("list.txt");
    const int MINIMUM = 2;
    //Check if the file exists, otherwise, terminate the application.
    if (file) {
        //Check file length before continuing.
        int check = fileLen(file);
        cout << "The text file has " << check << " entries.\n";

        if (check > MINIMUM ) {
            //create a pointer to int array
            int* array_1;
            //call lenCheck to prompt user for the new array size (Also performs a fileLen check to prevent overflows.)
            int limit = lenCheck(file, array_1);
            //call Swap with the old array to reverse contents into new array.
            int* array_2 = Swap(array_1, limit);

            //Print the original array.
            cout << "\nReading from the beginning of the file...\n Array 1:\n\n";
            for (int i = 0; i < limit; i++)
                printInd(array_1[i]);

            //Print the copied/flipped array.
            cout << "\n Array 1 Reversed:\n\n";
            for (int i = 0; i < limit; i++)
                printInd(array_2[i]);

            //Delete the dynamic arrays.
            delete(array_1);
            delete(array_2);
        }
        else {
        //Returns here if file contents are empty.
            cout << "list.txt is not usable since it has " << check << " entries.\n Minimum entries required: " << MINIMUM << "\n";
            return 1;
        }
    }
    else {
        cout << "File not found!\n";
        return 1;
    }
    
    cout << "\n";
	system("pause");
	return 0;
}