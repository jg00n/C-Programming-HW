#pragma once
//Note: using pragma once elimiates the usage of preprocessor commands.

/*
* Jonathan Goon
* 
* Honor Code : "I have neither given nor received unauthorized aid in completing this work,
* nor have I presented someone else's work as my own."
*
* Function Header file for HW_3
* 2/14/2021
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//-----Function Prototypes-----//

//Note: Functions FileLen, Swap are the required functions for this assignment. Everything else is additional features/ error checking.

//File parsing functions
int     fileLen(ifstream&), lenCheck(ifstream&, int*&);
void    fileReset(ifstream&);
bool    is_file_empty(ifstream&);

//iomanip functions.
template<typename T> void printInd(T t, const int&);
//Array parsing function.
int*    Swap(int*, int);

//iostream cleanup.
void    Cleanup();


/******** Function definitions. ********/

//----- File parsing defintions. -----//

int fileLen(ifstream& file) {
    int length = 0;
    string items;
    while (getline(file, items))
        ++length;
    fileReset(file);
    //Return file length
    return length;
}

void fileReset(ifstream& file) {
    //Reset file position after reading.
    file.clear();
    file.seekg(0);
}

// Required function 1.
int lenCheck(ifstream& file, int*& array_1) {

    int counter, limit;
    //Check file for length.
    limit = fileLen(file);
    //Prompt for element size.
    while (true) {
        cout << "Enter number of elements to be read: ";
        cin >> counter;

        //Verify input before continuing.
        if (cin.fail()) {
            cout << "\nInvalid Entry!\n";
        }
        else if (counter < 2) {
            cout << "Cannot accept a value less than 2!\n";
        }
        else if (counter > limit){
            cout << counter << " is higher than the number of entries on file!\n";
        }
        else {
            //On a sucessful entry, create a dynamically allocated array.
            array_1 = new int[counter];
            Cleanup();
            break;
        }
        //Function will reach this condition upon failure.
        cout << "Please try again!\n";
        Cleanup();
    }

    //read data from the file
    string a;
    //index for array
    int i = 0;

    while (file >> a && i < counter) {
        //Promote value to int, store value into newly created array.
        array_1[i] = stoi(a);
        //
        i++;
    }
    fileReset(file);
    //return the length of array
    return counter;

}

bool is_file_empty(ifstream& file) {
    //Check file to see if contents are empty.
    return file.peek() == ifstream::traits_type::eof();
}
//----- iomanip functions. -----//

template<typename T> void printInd(T t, const int& width = 5) {
    //Format output 
    cout << left << setw(width) << setfill(' ') << t;
}


//----- Array parsing function. -----//

//Required function 2.
int* Swap(int* array_old, int size) {

    //Dynamic Allocation to a new array
    int* array_new = new int[size];

    //reverse the contents of the older array into the new array.
    //The new array is indexed upwards/ The old array is indexed downwards.
    for (int i = size - 1, j = 0; i >= 0; i--, j++) {
        array_new[j] = array_old[i];
    }

    //return the new array
    return array_new;
}

//----- iostream cleanup. -----//

void Cleanup() {
    //Clears out cin buffer to prevent enviroment contamination.
    cin.clear();
    cin.ignore(256, '\n');
}
