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
*    4 / 25 / 21 ~~~~~ For the ORIGINAL ASSIGNMENT.
*	 10/  2 / 21 ~~~~~ Added search, advanced_search, sort, append array.
* 
* 
* 
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
	
	Node<T> *head, *current, *previous, *next;							//Navigational pointers

public: 

	//Constructor with navigational pointers initialized.
	LinkedList<T>() {

		head		= NULL;
		previous	= NULL;
		next		= NULL;
		current		= NULL;

	}        
	//Destructor        
	~LinkedList<T>() {      
		// make a current node pointer current initialized with head
		current = head;		
		Node<T>* temp;            
	    
		while (current != NULL) {                                
			temp = current->next;										// store the next node into temp
			delete current;												// delete current node.
			current = temp;												// assign current to next node.
		}
	}

	//Append a value to the end of the list.
	void append(T value) {            
		
		current = head;													// initialize current node position with head.
		
		Node<T>* New = new Node<T>;										// Create a new node object.
		New->data = value;                     
		New->next = NULL;

		if (current == NULL) head = New;								// if current is NULL we are at the first node. Otherwise navigate to the next node until NULL.
		else {   
			while (current->next != NULL) current = current->next;
			current->next = New;										// the next node of current will point to New.       
		}
		//Big O notation of O(N)
	}
	//Appends multiple values to the end of a list, requires an array size to be specified. An Overload.
	void append(T* values, int index) {
		for (int x = 0 ; x < index; x++) {
			append(values[x]);
		}
		//Big O notation of O(N).
		//Encapsulation of the previous function leads to O(N^2).
	}

	//insert a value into the list with a specified index (value, index).
	void insertAt(T value, int index) {

		//Initialize pointers previous and current.
		previous = NULL;
		current = head;

		//Create new node object.
		Node<T>* New = new Node<T>;
		New->data = value;                        
		
		//Cycle through the nodes until we reach the end.
		while (current != NULL) {						
			
				if (index == 0) {						// if index is 0 then insert.
					                
					if (previous == NULL) {				// if previous is NULL then it is inserted as the first node    

						New->next = head;				// set next of New to head pointer.
						head = New;						// Set head to new.

					}
					else {

						New->next = previous->next;		//Assign next of new to next of previous.
						previous->next = New;			//Assign next of previous to node New.

					}
					return;
				}
				
				index--;								//Decrease pointer and set previous pointer to current, set current to the next pointer
				previous = current;
				current = current->next;
		}            
		
		if (index == 0) {								// if index is 0 that means the node should be inserted at end.
			New->next = NULL;
			previous->next = New;						// assign next of new node to null and next of previous to new node.
		}

	}


	// Delete a node based on it's position in the list.
	void Delete(T value) {
		        
		previous = NULL;								// initialize current and previous pointers.   
		current = head;

		while (current != NULL) {						// loop till current node pointer becomes NULL            
			    
			if (current->data == value) {				// if the value is found in the current node.      

				Node<T>* temp;							// temp node used to hold the node for deletion.
				
				if (previous == NULL) {					// if previous is null, the first node must be deleted.

					temp = head;						// set node to head
					head = head->next;					// shift head to the next node
					delete temp;						// delete temp

				} else {

					temp = current;						// assign current in temp
					previous->next = current->next;		// shift next of previous to next of current.
					delete temp;						// delete temp

				}
				break;

			}
			             
			previous = current;							// make previous point to current node
			current = current->next;					// make current point to next of current node
		}

	}


	//Find an element within the array
	bool search (T value) {
		current = head;	
	
		while (current != NULL)
		{
			if (current->data == value) return true;
			current = current->next;
		}
		return false;
	}

	//Search and return a fixed amount of items.
	void search_adv(T value) {
		current = head;					
		bool present = false;
		int index = 0,counter = 0;
		int res_size = 20;
		int ind_count[res_size] = { 0 };						//Created a fixed array for storing found values, should be using a vector instead.

		while (current != NULL) {						
			if (current->data == value) {
				ind_count[counter] = index;
				counter++;										//Increment if an index was found 
				present = true;									//Check condition for the statement below.

			}
			index++;
			current = current->next;
		}
		
		if (present) {
			std::cout << " Found " << value << " at index ";
			for (int i = 0; i < counter && i <res_size ; i++) {	//Added a temporary double condition for ind_count overflow.
				std::cout << ind_count[i];
				if (counter - i == 1) std::cout << ".\n";
				else std::cout << ", ";
			}
			
		}
		else std::cout << "\"" <<
			value << "\" was not found in the list!!\n";

	}

	//Count the values to produce the linked list size.
	int count() {											
		current = head;
		int counter = 0;
		while (current != NULL){
			counter++;
			current = current->next;

		}
		return counter;
		//Big O notation of O(N).
	}

	//Sort the linked list
	void sort() {
		current = head;
		previous = NULL;
		int temp;
		if (head == NULL) {									//"Don't do anything"
			return;
		}
		else {
			
			while (current != NULL) {

				previous = current->next;					//Sets previous to next pointer

				while (previous != NULL) {
					if (current->data > previous->data) {	//If the current value is larger than previous value, swap contents.
						temp = current->data;
						current->data = previous->data;
						previous->data = temp;
					}
					previous = previous->next;				//Otherwise move the previous node to the next node.
				}
				current = current->next;					//Move the pointer to the next node
			}
			
		}
	}

	//Returns the indexed value of a specific element, requires the index position.
	int index(int val) {									
		current = head;
		int x = 0;
		while (current != NULL ){

			if (x == val) return current->data;				//return the contents of the node once x matches the index;
			x++;											
			current = current->next;						

		}
		return NULL;										//If the counter doesn't reach the index, return NULL.
		//Big O notation of O(N).
	}

	//Get to the end of the list.
	int end() {
		current = head;
		while (current != NULL) {
			current = current->next;
		}
		return current->data;
	}

	//Print contents of the linked list.            
	void print() {											
		current = head;										
		do  {												
			
			std::cout << current->data << ' ';				// print data seperated by space.
			current = current->next;						// set the current pointer to the next pointer.

		} while (current != NULL);

		std::cout << "\n";
	}
};
