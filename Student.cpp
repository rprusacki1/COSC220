/*
 * Rachel Prusacki, 10/15/2021
 * COSC220
 * Implements Student class
 */

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

//Constructor
Student :: Student () {
	int y;
	cout << "-------------------------------------------" << endl;
	cout << "Enter Student's Name: " << endl;
	getline(cin, name);
	
	cout << "Enter Student's ID: " << endl;
	cin >> sID;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter Student's ID: " << endl;	
		cin >> sID;
	}

	cout << "Enter Student's Year of College: " << endl;
	cout << "1 for Freshman, 2 for Sophomore, 3 for Junior, 4 for Senior.\n";
	cin >> y;

	while (cin.fail() || y < 1 || y > 4) {
		cin.clear();
		cin.ignore();
		cout << "Enter Valid Selction" << endl;
		cin >> y;
	}

	if (y == 1)
		year = "Freshman";
	if (y == 2)
		year = "Sophomore";
	if (y == 3)
		year = "Junior";
	if (y == 4)
		year = "Senior";

	head = NULL;
	cout << endl;
}

Student :: Student(string n, string y, int i) { //Extra credit constructor
	name = n;
	year = y;
	sID = i;
}

//Destructor
Student :: ~Student() {
	Node * nodePtr;
	Node * nextNode;

	nodePtr = head;

	//Deletes all nodes
	while (nodePtr != NULL) {
		nextNode = nodePtr -> next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

//Adds new student node to the end
void Student :: insertNode() {
	Node * newNode;
	Node * nodePtr;

	string t;
	string d;
	int r;

	cout << "-------------------------------------------" << endl;
	//Creates Book Object
	cout << "Enter Book Title: " << endl;
	getline(cin, t);

	cout << "Enter Due Date: " << endl;
	getline(cin, d);
	
	cout << "Enter 0 for Renewable, 1 for Not Reneweable: " << endl;
	cin >> r;

	while (cin.fail() || r < 0 || r > 1) { //Checks input
		cin.clear();
		cin.ignore();
		cout << "Enter 0 for Renewable, 1 for Not Reneweable: " << endl;
		cin >> r;
	}

	Book b = Book(t, d, r);

	newNode = new Node;
	newNode -> value = b;
	newNode -> next = NULL;

	//If there are no nodes
	if (!head)
		head = newNode;
	
	//Adds to the end
	else {
		nodePtr = head;

		while (nodePtr -> next)
			nodePtr = nodePtr -> next;

		nodePtr -> next = newNode;
	}
	cout << endl;
}

void Student :: deleteNode() {
	Node * nodePtr;
	Node * prevNode;
	
	cout << "-------------------------------------------" << endl;
	string del;
	cout << "Enter title to delete: " << endl;
	getline(cin, del);

	//If its empty
	if (!head)
		return;

	//If its first
	if (head -> value.getTitle() == del) {
		nodePtr = head -> next;
		delete head;
		head = nodePtr;
	}

	else {
		nodePtr = head;

		//Skip nodes until the title book is equal
		while (nodePtr != NULL && !(nodePtr -> value.getTitle() == del)) {
			prevNode = nodePtr;
			nodePtr = nodePtr -> next;
		}

		//if its not at the end
		if (nodePtr) {
			prevNode -> next = nodePtr -> next;
			delete nodePtr;
		}
	}
	cout << endl;
}

void Student :: searchList() {
	Node * nodePtr = head;

	string te;
	cout << "-------------------------------------------" << endl;
	cout << "Enter title to search for: " << endl;
	getline(cin, te);

	//If empty
	if (!nodePtr) {
		cout << "List is empty" << endl;
		return;
	}

	while (nodePtr) {
		if (nodePtr -> value.getTitle() == te) {
			cout << te << " has the following details: " << endl;
			nodePtr -> value.printBook();
			return;
		}
		nodePtr = nodePtr -> next;
	}

	if (!nodePtr)
		cout << name << " does not have " << te << endl;
	cout << endl;
}

//Prints what books the student has
void Student :: printList() {
	Node * nodePtr;
	
	cout << "-------------------------------------------" << endl;
	cout << name << " has the following books taken out: " << endl;

	nodePtr = head;

	while (nodePtr) {
		nodePtr -> value.printBook();
		cout << endl;
		nodePtr = nodePtr -> next;
	}
}

//Prints the student's information
void Student :: printStudent() {
	cout << "-------------------------------------------" << endl;
	cout << name << " is a " << year << " with ID: " << sID << endl;

}

string Student :: getName() {
	return name;
}

int Student :: getID() {
	return sID;
}

string Student :: getYear() {
	return year;
}

void Student :: booktxt(string f) {
	ofstream myfile;
	myfile.open(f);
	Node * nodePtr = head;
	
	if (myfile.is_open()) { //Check if file is open
		while (nodePtr) { 
			myfile << nodePtr -> value.getTitle() << ", " << nodePtr->value.getDate() << ", " << nodePtr -> value.getRenew() << "\n";
			nodePtr = nodePtr -> next;
		}
	}

	else {
		cout << "Error" << endl;
	}
}
