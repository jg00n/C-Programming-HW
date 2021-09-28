#pragma once
#include <iostream>
template <class T>
class Stack
{
private:
	
	struct Node {
		T data;
		Node* next;
		Node(T dat, Node* nxt) {
			data = dat;
			next = nxt;
		};
	}*head, *current;
	
public:
	Stack() {
		head = 0;
		current = NULL;
	};
	~Stack() {

		Node* temp;
		current = head;

		while (current != NULL) {
			temp = current->next;           // store the next node into temp
			delete current;                 // delete current node.
			current = temp;					// assign current to next node.
		}

	};
	void push(T dat) {
		head = new Node(dat, head);
	};
	T pop() {
		if (head != 0) {
			T result = head->data;
			Node* temp = head;

			head = head->next;
			delete temp;
			return result;
		}
		else {
			std::cout << "Stack is empty\n";
			return NULL;
		}
	};
	
	T peek() {
		if (head != 0) {
			return head->data;
		}
		else { 
			std::cout << "Stack is empty\n";
			return NULL;
		}
	};
};