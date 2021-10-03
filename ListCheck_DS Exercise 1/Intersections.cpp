#include <iostream>
#include "LList.h"


int main() {

	LinkedList<int> L, P;
	//Pulled from indexer functions for quick reference
	int l_vals[] = { 18,40,1,22,44,5,7,3,9,10,44,44 };		//Numbered list that we will be checking
	int p_vals[] = { 1,3,4,6,44};							//A list of numbers that we will be checking in the previous list.

	L.append(l_vals, *(&l_vals + 1) - l_vals);		//Pointer method to get size.
	P.append(p_vals, *(&p_vals + 1) - p_vals);

	//Get content from one array, compare it with another array to see if it exists.

	//Index the first list
	int index1 = P.count();
	int index2 = L.count();
	for (int i = 0; i < index1; i++) {
		//Compare with other linked list.
		int counter = 0;

		//Check if the element exists in the other linked list.
		for (int j = 0; j < index2; j++) {
			if (P.index(i) == L.index(j)) counter++;
			
		}

		//There are 2 for loops with complexity of N, notation would be O(N^2)
		if (counter != 0) std::cout << "Found " << P.index(i) << " in both arrays " << counter << " time(s)!\n";
		else std::cout << "Did not find " << P.index(i) << " in both arrays!\n";
	}



	return 0;
}