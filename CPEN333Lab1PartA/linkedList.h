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
		head = NULL;
		tail = NULL;
	}

	// Add new node (not insert)
	void AddNode (int n) {
		Node* temp = new Node; // create pointer to new node
		temp->data = n; // assign new data
		temp->next = NULL; // nothing after it (may need changing)

		// assign head and tail to be new node if first one
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next; // new tail is next of current tail
		}
	}

	// List all data in LL
	void ListData() {
		Node* temp = head;
		while (temp != NULL) {
			cout << head->data << endl;
			temp = temp->next;
		}
	}

	//List(); // return all vals in LL?
	//Insert(); // insert LL, create new pointer to new object, new object next to old next, delete original pointer
	//Delete(); // delete LL, next pointer needs to skip
	//Get(); // return data from LL
};
#endif