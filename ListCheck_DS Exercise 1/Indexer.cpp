#include <iostream>
#include "LList.h"

int main() {
	LinkedList<int> L,P;


	int l_vals[] = { 18,40,1,22,44,5,7,3,9,10 };	//Used arrays here to convienently append later. Append can also take single values.
	int p_vals[] = { 1,3,4,6 };

	L.append(l_vals, *(&l_vals + 1) - l_vals );		//Pointer method to get size.
	P.append(p_vals, *(&p_vals + 1) - p_vals );

	for (int x = 0; x < P.count(); x++) {
		
		if (P.index(x) > L.count()) {
			std::cout << "Invalid index...\n";
		}
		else {
			std::cout << L.index(P.index(x)) << "\n";
		}
	
	}
	//One for loop is has a time complexity of O(N).
	return 0;

}