/*
*   Design your own linked list class. It should be a template class, capable to hold a series of objects of type T.
*	The class should have the following template functions:
*   void append(T value) : Adds a new node with the value T at the end of the linked list.
*   void insertAt(T value, int index) : Adds a new node with the value T at the position specified by index.
*
*   The node New is inserted AT index.So, for example, if the list has 3 values :
*
*		If the user inserts at 0, the head pointer will point to Newand New will point to the first node.
*    	If the user inserts at 1, the first node will point to Newand it will points to the second one.
*    	If the user inserts at 2, the second node will point to Newand it will points to the third one.
*    	If the user inserts at 3, the third node will point to Newand New will point to nullptr.
*    	If index is higher than the count of elements in the list, the function should do nothing.
*    	void delete(T value) : Finds value in the linked listand removes it from the linked list.
*    	A destructor for the linked list that deallocates the memory used.
*
*    	Demonstrate the class and every function with a program. Make sure the object of the class in the demonstration has at least 5 elements by the time it ends.
*
*    Jonathan Goon
*    9 / 28 / 21
*    Honor Code : "I have neither given nor received unauthorized aid in completing this work,
*    nor have I presented someone else's work as my own."
*
*/

#include "LList.h"
#include "IO_text.h"
int main() {
	// make linked list object    
	LinkedList<int> LList;
	IO_text Message;
	// check for the append function    
	Message.Show("\nTest append() function...");
	for (int i = 0; i < 5; i++) {
		int temp = rand() % 5 + 1;
		LList.append(temp);
		Message.Show("Appended ", temp);
		LList.print();
	}

	// check for the insertAt() function    
	Message.Show("\nTest insertAt() function...");
	int x = 0;

	for (int i = 9; i > 5; i--) {
		
		LList.insertAt(i,x);
		printf("Inserted (%i,%i):\n", i, x);
		LList.print();
		x++;
	}
	Message.Show("\n Finding 5...");
		bool result =LList.search(5);
		Message.Show("Results: ",result);
		LList.search_adv(5);

		Message.Show("\n Finding 20...");
		result = LList.search(20);
		Message.Show("Results: ",result);

	Message.Show("\nTest insertAt(5,21) outside of list.");
 	LList.insertAt(5, 21);
	LList.print();
	
	// check for the delete function    
	Message.Show("\nTest Delete() function...");
	for (int i = 0; i < 4; i++) {
		int temp = rand() % 5 + 1;
		LList.Delete(temp);
		Message.Show("Deleted ", temp);
		LList.print();
	}

	Message.Show("\nTesting sort function...");
	LList.sort();
	LList.print();

	return 0;
}