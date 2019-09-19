/* Raymond Yu
 * 17 September 2019
 * 11298149
 */

#pragma once

#ifndef   __linkedList__
#define   __linkedList__

#include <iostream>

using namespace std;

// Templates: Declaration and member functions needs to be within this same file
template <class T>
struct Node {
	T data; // data storage of any form
	Node* next; // pointer to the next struct of same element
};

template <class T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	// Default constructor to set 
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	// Add new node with data n
	void Insert (T n) {
		Node<T>* temp = new Node<T>; // create pointer to new node
		temp->data = n; // assign new data
		temp->next = nullptr; // nothing after it (may need changing)

		// assign head and tail to be new node if first one
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next; // new tail is next of current tail
		}
	}

	// Retrieve length of LL
	int GetLen() {
		int length = -1;
		Node<T>* temp = head;
		if (temp == nullptr)
			return length; // nothing in LL
		else {
			length = 1;
			while (temp->next != nullptr) {
				length += 1;
				temp = temp->next;
			}
			// stuff
		}
		return length;
	}

	// List all data in LL
	void ListData() {
		Node<T>* temp = head;
		while (temp != nullptr) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}

	// Retrieve LL data from specific location (no check for exceeding LL size)
	T GetVal(int n) {
		Node<T>* temp = head;
		for (int i = 0; i < n; i++) {
			temp = temp->next;
		}
		return temp->data;
	}

	// Delete last element of LL
	void DelVal() {
		Node<T>* current = head;
		Node<T>* previous = nullptr;
		if (head == nullptr) { // empty LL
			return;
		}
		while (current->next != nullptr) {
			previous = current;
			current = current->next;
		}
		if (current == head)
			head = nullptr; // one element LL
		delete tail; // if a tail still exists
		tail = previous;
		if (previous != nullptr)
			previous->next = nullptr;
	}
};
#endif
