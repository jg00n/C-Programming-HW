#include <iostream>
#include "LList.h"

namespace Josephus{
	inline std::string ID() {
		return "Josephus";
	}
	static int joseph(int n, int m) {
		if (n == 1) return 1;
		else return (joseph(n - 1, m) + m - 1) % n + 1;
	}
	static int maindev() {
		int n = 14;
		int k = 2;
		std::cout << "The chosen place is " << joseph(n, k);
		return 0;
	}

}