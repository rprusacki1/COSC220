/*
 * Rachel Prusacki, 10/15/2021
 * COSC220
 * Creates Student class header file
 */
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Book.h"

#include <fstream>

using namespace std;

class Student {
	//Creates Node and student name
	private:
		//Creates a node struct
		struct Node {
			Book value;
			struct Node * next;
		};
		//points to first Node
		Node *head;
		
		//Metadata
		string name;
		string year;
		int sID;

	public:
		//Constructor
		Student();
		
		//Extra credit constructor:
		Student(string, string, int);

		//Destructor
		~Student();

		void insertNode();
		void deleteNode();
		void searchList();
		void printList();
		void printStudent();
		string getName();
		int getID();
		string getYear();

		void booktxt(string s);
};

#endif //STUDENT_H
