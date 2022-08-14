/*
 * Rachel Prusacki, 10/15/2021
 * COSC220
 * StudentDList header file
 */

#ifndef STUDENTDLIST_H
#define STUDENTDLIST_H
#include <fstream>
#include <iostream>
#include <string>
#include "Student.h"
#include "Node.h"

using namespace std;

class StudentDList {

	private:

		Node *header;
		int listSize;

		void derase (Node *);
		void dinsert (Node *);
		
	public:
		StudentDList();
		~StudentDList();
		void insert();
		void remove();
		void displayStudent();
		void displayBook();
		void search();
		void addBook();
		void maketxt(string);
		void makedata(string);
};

#endif //STUDENTDLIST_H
