#include <iostream>
#include "LList.h"

namespace Intersections {
	inline std::string ID() {								//Identifier dud.
		return "Intersections";
	}
	static int maindev() {

		LinkedList<int> L, P;
		//Pulled from indexer functions for quick reference
		int l_vals[] = { 18,40,1,22,44,5,7,3,9,10,44,44 };		//Numbered list that we will be checking
		int p_vals[] = { 1,3,4,6,44 };							//A list of numbers that we will be checking in the previous list.

		L.append(l_vals, *(&l_vals + 1) - l_vals);		//Pointer method to get size.			//O(N^2)
		P.append(p_vals, *(&p_vals + 1) - p_vals);												//O(N^2)

		//Get content from one array, compare it with another array to see if it exists.

		//Index the first list
		int index1 = P.count();																	//O(N)
		int index2 = L.count();																	//O(N)
		for (int i = 0; i < index1; i++) {														//O(N)+
			//Compare with other linked list.
			int counter = 0;

			//Check if the element exists in the other linked list.
			for (int j = 0; j < index2; j++) {													//O(N^2)+
				if (P.index(i) == L.index(j)) counter++;										//O(N^2+3N)------

			}

			//There are 2 for loops with complexity of N, notation would be O(N^2)
			if (counter != 0) std::cout << "Found " << P.index(i) << " in both arrays " << counter << " time(s)!\n";	//O(N)
			else std::cout << "Did not find " << P.index(i) << " in both arrays!\n";									//O(N)
		}

		//Big O O(3N^2+7N)
		//Big O O(3N^2)

		return 0;
	}

}