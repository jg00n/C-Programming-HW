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
*    4 / 25 / 21
*    Honor Code : "I have neither given nor received unauthorized aid in completing this work,
*    nor have I presented someone else's work as my own."
*    
*/

#pragma once
#include <iostream>

// class Node definition
template<class Type>
class Node {
public:

	Type		data;  // holds values.
	Node<Type>* next;  // pointer for the next node.

};


// class LinkedList definition
template<class T>
class LinkedList {
private:

	//Navigational pointers
	Node<T> *head, *current, *previous, *next;

public: 

	// constructor with navigational pointers initialized.
	LinkedList<T>() {

		head		= NULL;
		previous	= NULL;
		next		= NULL;
		current		= NULL;

	}        
	// destructor        
	~LinkedList<T>() {      
		// make a current node pointer current initialized with head
		current = head;		
		Node<T>* temp;            
	    
		while (current != NULL) {                                
			temp = current->next;           // store the next node into temp
			delete current;                 // delete current node.
			current = temp;					// assign current to next node.
		}
	}

	// append(T value)
	void append(T value) {            
		// initialize current with head.
		current = head;            
		// Create a new node object.
		Node<T>* New = new Node<T>;
		New->data = value;                     
		New->next = NULL;

		// if current is NULL we are at the first node. Otherwise navigate to the next node until NULL.
		if (current == NULL) head = New;
		else {   
			while (current->next != NULL) current = current->next;
			// the next node of current will point to New.          
			current->next = New;
		}

	}

	// insertAt(T value, int index)
	void insertAt(T value, int index) {

		// initialize pointers previous and current.
		previous = NULL;
		current = head;

		// create new node object.
		Node<T>* New = new Node<T>;
		New->data = value;                        
		
		// cycle through the nodes until we reach the end.
		while (current != NULL) {
			// if index is 0 then insert.

				if (index == 0) {
					// if previous is NULL then it is inserted as the first node                    
					if (previous == NULL) {

						New->next = head;				// set next of New to head pointer.
						head = New;						// Set head to new.

					}
					else {

						New->next = previous->next;		//Assign next of new to next of previous.
						previous->next = New;			//Assign next of previous to node New.

					}
					return;
				}
				//Decrease pointer and set previous pointer to current, set current to the next pointer
				index--;
				previous = current;
				current = current->next;
		}            
		// if index is 0 after the loop that means the node should be inserted at end.
		if (index == 0) {                                
			New->next = NULL;
			// assign next of new node to null and next of previous to new node.
			previous->next = New;
		}

	}
	// Delete(T value)
	void Delete(T value) {
		// initialize current and previous pointers.           
		previous = NULL;
		current = head;

		// loop till current node pointer becomes NULL            
		while (current != NULL) {

			// if the value is found in the current node.          
			if (current->data == value) {

				// temp node used to hold the node for deletion.
				Node<T>* temp;
				// if previous is null, the first node must be deleted.
				if (previous == NULL) {

					temp = head;					// set node to head
					head = head->next;				// shift head to the next node
					delete temp;					// delete temp

				} else {

					temp = current;					// assign current in temp
					previous->next = current->next;	// shift next of previous to next of current.
					delete temp;					// delete temp

				}
				break;

			}
			             
			previous = current;						// make previous point to current node
			current = current->next;				// make current point to next of current node
		}

	}
	//Find an element within the array
	bool search(Node* head, int x)
	{
		Node* current = head; // Initialize current 
		while (current != NULL)
		{
			if (current->data == x)
				return true;
			current = current->next;
		}
		return false;
	}

	//Print contents of the linked list.
	void print() {
		            
		current = head;								//set current node pointer

		// loop until end of list.
		do  {
			
			std::cout << current->data << ' ';		// print data seperated by space.
			current = current->next;				// set the current pointer to the next pointer.

		} while (current != NULL);

		std::cout << "\n";
	}
};