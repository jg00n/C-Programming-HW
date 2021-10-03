#include <iostream>
#include "LList.h"


int main() {

	LinkedList<int> L, P;
	int l_vals[] = { 18,40,1,22,44,5,7,3,9,10 };	//Pulled from indexer functions for quick reference
	int p_vals[] = { 1,3,4,6 };

	L.append(l_vals, *(&l_vals + 1) - l_vals);		//Pointer method to get size.
	P.append(p_vals, *(&p_vals + 1) - p_vals);

	//Get content from one array, compare it with another array to see if it exists.

	//Index the first list
	for (int i = 0; i < P.count(); i++) {
		//Compare with other linked list.
		int counter = 0;

		for (int j = 0; j < L.count(); j++) {
			//Condition if element matches.
			if (P.index(i) == L.index(j)) {
				std::cout << "Found " << P.index(i) << " in both arrays " << counter << " time(s)!\n";
			}
			//There are 2 for loops with complexity of N, notation would be O(N^2)
		}
	
	}



	return 0;
}