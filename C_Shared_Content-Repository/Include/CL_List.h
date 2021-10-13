#pragma once

#include <iostream>
#include "LList.h"

//Child Class of parent Linked List.
template <class T>
class CircleLinkList :public LinkedList {

public:
	CircleLinkList<T>() : public LinkedList<T>(){
	
	}

	void append_empty(T value) {
		current = head;
		if (current != NULL) return current;							//Escape method if the list is not empty.

		Node<T>* New = new Node<T>;										//Create new object.
		New->data = value;
		current = New;

		current->next = current;										//Set current pointer to itself.
	}
	//Append to beginning of the list.
	void append_begin(T value) {

		if (current == NULL) return append_empty(value);				//Append empty if there are no values in the list.

		Node<T>* New = new Node<T>;										//Create a new object
		New->data = value;
		New->next = current->next;

		current->next = New;
	
	}
	void append_end(T_value) {

		if (current == NULL) return append_empty(value);				//Append empty if there are no values in the list.

		Node<T>* New = new Node<T>;										//Create a new object
		New->data = value;
		New->next = current->next;
		current = New;


	}
	//Append a value to the end of the list.
	void append(T value) {

		current = head;													// initialize current node position with head.

		Node<T>* New = new Node<T>;										// Create a new node object.
		New->data = value;
		New->next = *head;												//Set the next pointer to head.
		*head = New;													//The head is set as the new node.

		//Big O notation of O(N)
	}
	void convert(Node* head) {
		current = head;													//Initialize current position at head for linked list
	
		while (head->next != NULL) {									//Move the current pointer to the end of the list, where the ending node has a pointer of NULL
			head = head->next;
		}
		head->next = current;											//Set the head pointer (NULL) to the current head pointer.
	}
	// Delete a node based on it's position in the list.
	void Delete(T value) {

		current = head;

		while (head->next != head) {					// loop till current node pointer has a nav-pointer at head.            

			if (current->data == value) {				// if the value is found in the current node.      

				Node<T>* temp;							// temp node used to hold the node for deletion.

				if (previous == head) {					// if previous is set to head, that means it's the first node.

					temp = head;						// set node to head
					head = head->next;					// shift head to the next node
					delete temp;						// delete temp

				}
				else {

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
};