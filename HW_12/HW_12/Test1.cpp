
#include <iostream>
using namespace std;
// class Node definition
template<class T>class Node {
public:        T data;        // add field for data        
	  Node<T>* next;  // add field for next pointer
};
// class LinkedList defintion

template<class T>
class LinkedList {
private:        Node<T>* head;       // head pointer
public:        // constructor initialize head with NULL
	LinkedList<T>() {
		head = NULL;
	}        // destructor        
	~LinkedList<T>() {            
		// make a current node pointer curr initialized with head            
		Node<T>* curr = head;
		Node<T>* temp;            
		// loop till curr becomes null            
		while (curr != NULL) {                
			// assign next node of current node to temp                
			temp = curr->next;                
			// delete current node                
			delete curr;                
			// assign temp in curr                
			curr = temp;
		}
	}
	// append function        
	void append(T value) {            
		// make a current node pointer curr with value head            
		Node<T>* curr = head;            
		// make a new node and assign its data and next            
		Node<T>* newNode = new Node<T>;
		newNode->data = value;            
		// next will be NULL as it is goint to be inserted at end            
		newNode->next = NULL;            
		// if curr is NULL that means it is first node,            
		if (curr == NULL) {                
			// make head to newNode and return                
			head = newNode;                return;
		}
		// else traverse list till next field of curr is not NULL            
		while (curr->next != NULL) { curr = curr->next; }
		// now curr points to the last node so add new node to the next of curr node            
		curr->next = newNode;
	}
	// function insertAt()        
	void insertAt(T value, int index) {
		// make two node pointer, prev and curr            

		Node<T>* prev = NULL;
		Node<T>* curr = head;            
		// make a new node and store the value in the new node            
		Node<T>* newNode = new Node<T>;
		newNode->data = value;                        
		// loop till curr becomes NULL            
		while (curr != NULL) {
			// if index is 0 then insert                
			if (index == 0) {
				// if prev is NULL then it is to be inserted as first node                    
				if (prev == NULL) {
					// so assign head to next of new node                        
					newNode->next = head;
					// make new node to head                         
					head = newNode;
				}
				else {
					// else assign next of prev to next of new node                        
					newNode->next = prev->next;
					// assign next of prev to new node now                        
					prev->next = newNode;
				}

			}
			// else decrease the index by 1                
			index--;
			// assign curr in prev and make curr points to next of curr                
			prev = curr;
			curr = curr->next;
		}            // if index is 0 after the loop that means the node should be inserted at end            
		if (index == 0) {                // so assign next of new node to null and next of prev to new node                
			newNode->next = NULL;
			prev->next = newNode;
		}
	}
	// function delete()        
	void Delete(T value) {
		// make two node pointers            
		Node<T>* prev = NULL;
		Node<T>* curr = head;
		// loop till curr node pointer becomes NULL            
		while (curr != NULL) {
			// if the data of curr is equal to value                
			if (curr->data == value) {
				// declare a temp pointer to store the node to be deleted                    
				Node<T>* temp;
				// if prev is null that means, first node need to be deleted                    
				if (prev == NULL) {
					// assign head in temp                        
					temp = head;
					// make head points to next node of head                        
					head = head->next;
					// delete the temp                        
					delete temp;
				}
				else {
					// else assign curr in temp                        
					temp = curr;
					// assign next of curr in next of prev                        
					prev->next = curr->next;
					// delete temp                        
					delete temp;
				}
				break;
			}
			// make prev points to current node                
			prev = curr;
			// make curr points to next of current node                
			curr = curr->next;
		}
	}
	// an extra function print which will print the list        
	void print() {
		// make a curr node pointer            
		Node<T>* curr = head;
		// loop till curr becomes NULL            
		while (curr != NULL) {
			// print the data separated by space                
			cout << curr->data << " ";
			// make curr points to next of curr                
			curr = curr->next;
		}
		cout << endl;
	}
};

// testing
int main() {

}

