/**    
*	Design either your own stack or queue class.It should be a template class, capable to hold a series of objects of type T.
*    
*    The stack class should have the following template functions :
*    
*    void push(T value) : Adds a new node with the value T to the stack, following the description in the book.
*    T pop() : Removes the element at the top of the stack.It returns that value.
*    T peek() : Returns the value at the top of the stack.
*    An appropiate constructor.
*    A destructor for the stack that deallocates the memory used.
*    
*    The queue class should have the following template functions :
*    
*    void enqueue(T value) : Adds a new node with the value T to the queue, following the description in the book.
*    T dequeue() : Removes the element at the front of the queue.It returns that value.
*    T peek() : Returns the value at the front of the queue.
*    An appropiate constructor.
*    A destructor for the queue that deallocates the memory used.
*    
*    Demonstrate the class you writeand every function with a program.Make sure the object of the class in the demonstration has at least 5 elements by the time it ends.
*    
*    Jonathan Goon
*    4 / 25 / 21
*    Honor Code : "I have neither given nor received unauthorized aid in completing this work,
*    nor have I presented someone else's work as my own."
* 
* 
*/

#include "Stack.h"
#include "RPN.h"

int main() {

	std::string text;
	Stack<int> intput;

	for (int i = 0; i < 10; i++) {
		intput.push(i);
		printf("pushed: %i\n", intput.peek());
	}
	printf("peek: %i\n", intput.peek());
	for (int i = 0; i < 3; i++) {
		printf("popped: %i\n", intput.pop());
		
	}
	printf("peek: %i\n", intput.peek());

	for (int i = 0; i < 10; i++){
		//Manually dump stack.
		printf("popped: %i\n", intput.pop());
	}

	/*
	* Working on this post class , theres a bug during conversions. 
	* std::string text2 = "5 4 2 3 9 8 + + - - *";
	* printf("\n Results : %i\n",RPN::evaluate<int>(text2));
	*/
	return 0;
}

