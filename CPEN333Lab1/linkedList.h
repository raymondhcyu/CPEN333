#pragma once

#ifndef   __linkedList__
#define   __linkedList__

#include <iostream>

using namespace std;

struct Node
{
	int data; // int data storage
	Node* next; // pointer to the next struct of same element
};

class LinkedList {
private:
	Node* head, * tail;
public:
	// Default constructor to set 
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	// Add new node (not insert)
	void AddNode (int n) {
		Node* temp = new Node; // create pointer to new node
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
		Node* temp = head; 
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
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << endl; // can't use head->data b/c head doesn't change
			temp = temp->next;
		}
	}

	// Retrieve LL data from specific location (no check for exceeding LL size)
	int GetVal(int n) {
		Node* temp = head;
		if (n == 1) // initial condition
			return head->data;
		else {
			for (int i = 0; i < n; i++) {
				temp = temp->next;
			}
		}
		return temp->data;
	}

	// Delete last element of LL
	void DelVal() {

	}

	//List(); // default constructor
	//Insert(); // add at end
	//Delete(); // delete at end
	//Get(); // return data from LL at int number
};
#endif