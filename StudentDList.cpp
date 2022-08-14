/*
 * Rachel Prusacki, 10/15/2021
 * COSC220
 * Main method and StudentDList file. Implements the functions of the
 * StudentDList class. Main method allows the user to interact with the
 * database.
 */

#include <fstream>
#include <iostream>
#include <string>
#include "Student.h"
#include "StudentDList.h"

using namespace std;

StudentDList :: StudentDList() {
	header = nullptr;
	listSize = 0;
}

StudentDList :: ~StudentDList () {
	//Erases list from front to end
	
	if (header) {
	  while (header -> next != header) {
		derase(header->next);
	  }

	  listSize = 0;
	  delete header;
	}
}

//Private function erase
void StudentDList :: derase (Node *curr) {
	//Unlink node from the list
	curr -> prev -> next = curr->next;
	curr -> next -> prev = curr->prev;

	delete curr;
}

void StudentDList :: dinsert(Node *newNode) { //for E.C.
	if (!header) { //if empty
	       header = newNode;
       		listSize = 1;
	}
 	else if(header -> next == header) { //Only one node
		if (header -> value.getID() == newNode -> value.getID()) {
			cout << "ID already in list" << endl;
			return;
		}
		header -> next = newNode;
		header -> prev = newNode;
		
		newNode -> next = header;
		newNode -> prev = header;
	}

	else {
		Node * curr = header;
		while (curr -> next != header) {
			if (header -> value.getID() == newNode -> value.getID()) {
				cout << "ID already in list" << endl;
			}
			curr = curr -> next;
		}

		curr = header -> prev;
		
		newNode -> prev = curr;
		newNode -> next = curr -> next;
		curr -> next -> prev = newNode;
		curr -> next = newNode;	
	}
}

void StudentDList :: insert () {
	Node * curr;

	if (!header) { // list is empty
		header = new Node ();
		return;
		listSize = 1;
	}

	else {
		listSize++;
		Node * newNode = new Node();

		if (header -> next == header) { //if only one element
		       if (header -> value.getID() == newNode -> value.getID()) {
				cout << "ID already in list" << endl;
				return;
			}

			header -> next = newNode;
			header -> prev = newNode;

			newNode -> next = header;
			newNode -> prev = header;
		}

		else {
		  curr = header;
		  if (header -> value.getID() == newNode -> value.getID()) {
			  cout << "ID already in list" << endl;
			  return;
		  }
		  curr = header -> next;
		  while (curr != header) {//Checks Duplicate
		  	if (newNode->value.getID() == curr->value.getID()) {
			  cout << "ID already in list" << endl;
			  return;
			}
			curr= curr -> next;
		  }


		  curr = header -> prev; //last element in list

		  //insert after curr but before header
		  newNode -> prev = curr;
		  newNode -> next = curr -> next;

		  curr -> next -> prev = newNode;
		  curr -> next = newNode;
		}
	}
}

void StudentDList :: remove () {
	//Checks empty
	if (!header) {
		cout << "List is Empty" << endl;
		return;
	}

	string rem;
	cout << "Enter Student Name to Delete: " << endl;
	getline(cin, rem);

	Node *curr = header;
	
	if (curr -> next == header) { //Only 1 element
		header = nullptr;
		delete curr;
		return;
	}

	//Searches for node
	while (curr -> next != header && curr -> value.getName() !=rem) {
		curr = curr -> next;
	}
	
	if (curr == header) { //if its first
		header = header -> next;
		derase(header-> prev);
		listSize--;
	}

	else if (curr -> value.getName() == rem) { //if its found anywhere else
		derase(curr);
		listSize--;
	}

	else
		cout << "Data not found." << endl;

}

void StudentDList :: displayStudent() {
	
	Node * temp = header;

	if (!header) //If list is empty
		cout << "List is empty" << endl;

	else if (temp -> next == header) //if only 1 element
		header -> value.printStudent();

	else { //2 or more
		header -> value.printStudent();
		cout << endl;
		while (temp -> next != header) {
			temp = temp -> next;
			temp -> value.printStudent();
			cout << endl;
		}
	}
	cout << endl;
}


void StudentDList :: displayBook () {
	Node * temp = header;

	if (!header) //If list is empty
		cout << "List is empty" << endl;

	else if (temp -> next == header) //if only 1 element
		header -> value.printList();

	else { //2 or more
	  header -> value.printList();
	  cout << endl;
	  while (temp -> next != header) {
		temp = temp -> next;
		temp -> value.printList();
		cout << endl;
	  } 
	}
	cout << endl;
}

void StudentDList :: search () {
	string name;
	cout << "Enter Student Name" << endl;
	getline(cin, name);
	Node * temp = header;

	if (!header) { //If empty
		cout << "List is empty" << endl;
		return;
	}

	while (temp -> next != header && temp -> value.getName() != name) {
		temp = temp -> next;
	}

	if (temp -> value.getName() == name) { //If it's found
		temp -> value.printStudent();
		cout << endl;
		temp -> value.printList();
	}

	else {
		cout << "Student not in database" << endl;
	}

}

void StudentDList :: addBook() {
	Node * temp = header;

	if (!header) { //Empty
		cout << "List is empty" << endl;
		return;
	}

	int ID, ch;
	cout << "Enter Student ID of Student to Edit: " << endl;
	cin >> ID;
	while (cin.fail()) { //Ensures ID is a number
		cin.clear();
		cin.ignore();
		cout << "Enter Valid Selection:" << endl;
		cin >> ID;
	}

	while (temp -> next != header && temp -> value.getID() != ID) {
		temp = temp -> next;
	}

	if (temp -> value.getID() == ID) { //If there is a match
		while (true) { //Continue Editing Books Until User Quits
			cout << "1. Insert Book" << endl;
			cout << "2. Delete Book" << endl;
			cout << "3. Print Student's Books" << endl;
			cout << "4. Search for a Book" << endl;
			cout << "5. Quit" << endl;
			cin >> ch;
			
			while (cin.fail() || ch < 1 || ch > 5) {
			  cin.clear();
			  cin.ignore();
			  cout << "Enter Valid Selection: " << endl;
			  cin >> ch;
			}
				
			cin.ignore();

			if (ch == 1) {
				temp -> value.insertNode();
			}

			if (ch == 2) {
				temp -> value.deleteNode();
			}

			if (ch == 3) {
				temp -> value.printList();
			}

			if (ch == 4) {
				temp -> value.searchList();
			}

			if (ch == 5) { //Exits loop
				return; 
			}

			cout << endl;
		}
	}

	else {
		cout << "No Student Matches the Entered ID." << endl;
	}

}

void StudentDList :: maketxt(string f) { //Makes file from list
	ofstream myfile;
	myfile.open(f);

	if (!header) //Empty
		cout << "List is empty" << endl;
	else if (header -> next == header) { //One element
		myfile << header -> value.getName() << ", " << header->value.getID() << ", " << header -> value.getYear() << "\n";
		header -> value.booktxt(f); //Calls book printing function
	}

	else { //2 or more
		Node * curr = header;
		while (curr -> next != header) {
			myfile << curr -> value.getName() << ", " << curr->value.getID() << ", " << curr -> value.getYear() << "\n";
		curr -> value.booktxt(f); //Calls book printing
		}
	}
	myfile.close();

}

void StudentDList :: makedata(string f) { //Makes lists from file (only student)
	
	ifstream myfile;
	myfile.open(f);
	string line;
	string delimiter = ", ";
	string n, id, y;
	int p;

	if (myfile.is_open()) { //If it exists
		while (getline(myfile, line)) {
		 for (int i = 1; i < 4; i++) {
			n = line.substr(0, line.find(delimiter));
			id = line.substr(line.find(n)+ 2, line.find(delimiter));
			y = line.substr(line.find(i) + 2, line.find(delimiter));
			p = stoi(id, nullptr, 10);
			Student s = Student(n, y, p);
			Node * n = new Node (s);
			dinsert(n);
		  }
		}
	}

	else {
		cout << "Error" << endl;
	}

	myfile.close();
		
}

int main () {
	StudentDList d;
	bool run = true;
	int choice;
	
	cout << "Open an existing file? 0 for yes 1 for no: " << endl;
	cin >> choice;
	
	string file;
	ifstream myfile;
	cin.ignore();
	if (choice == 0) { //Open existing file
		cout << "Enter file name: " << endl;
		getline(cin, file);
		myfile.open(file);
		if (myfile.is_open())
		  d.makedata(file);
		else
		  cout << "Error" << endl;
	}
	cin.ignore();

	while (run) { 
		cout << "-------------------------------------------" << endl;
		cout << "Enter Selection: " << endl;
		cout << "1. Insert a Student" << endl;
		cout << "2. Remove a Student" << endl;
		cout << "3. Print Student Database" << endl;
		cout << "4. Print Student's Book Database" << endl;
		cout << "5. Search a Student's Records" << endl;
		cout << "6. Edit a Student's Books" << endl;
		cout << "7. Quit the Program" << endl;
		cout << "8. Save Database to Text File" << endl;
		cin >> choice;
		cout << endl;

		while (cin.fail() || choice < 1 || choice > 8) {
			cin.clear();
			cin.ignore();
			cout << "Enter Valid Selection:" << endl;
			cin >> choice;
		}
			
		cin.ignore();

		if (choice == 1) {
			d.insert();
		}

		if (choice == 2) {
			d.remove();
		}

		if (choice == 3) {
			d.displayStudent();
		}

		if (choice == 4) {
			d.displayBook();
		}

		if (choice == 5) {
			d.search();
		}

		if (choice == 6) {
			d.addBook();
		}

		if (choice == 7) {
			run = false;
		}

		if (choice == 8) {
			ofstream myfile;
			string f = "";
			cout << "Enter File Name: " << endl;
			getline(cin, f); //assuming .txt is entered

			myfile.open(f);
			if (myfile.is_open()) {	//If it opens
				myfile.close();
				d.maketxt(f);
			}

			else
				cout << "Error" << endl;
		}
	}

	return 0;
}
