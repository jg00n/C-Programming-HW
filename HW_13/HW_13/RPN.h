#pragma once
#include <sstream>
#include "Stack.h"


namespace RPN {
	//Reverse Polish Notation.
	template <class T>
	T evaluate(const std::string &tokens) {
		std::istringstream iss(tokens);
		
		Stack<T> stack;
		//Bug during token conversion.
		T token;

		while (iss >> token) {
			double tokenNum;
			if (iss >> tokenNum) {
				stack.push(token);
				printf("Pushed into RPN: %i\n", stack.peek());
			}
			else {
				T a = stack.pop();
				T b = stack.pop();
				printf("Popped %i, %i, token is %c\n", a, b, token);

				switch (token) {
				case '+': stack.push(a + b); break;
				case '-': stack.push(a - b); break;
				case '*': stack.push(a * b); break;
				case '/': stack.push(a / b); break;
				};
				printf("Current total: %i", stack.peek());
			}

		}
		
		return stack.peek();
	}

}