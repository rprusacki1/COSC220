/*
 * Rachel Prusacki, 10/15/2021
 * COSC220
 * Book Class header file
 */

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
	public:
		//Constructor
		Book(string, string, int);

		//Default Constructor
		Book ();
		//prints book details
		void printBook();
		//updates due date
		void updatedueDate();

		string getTitle();
		string getDate();
		bool getRenew();

	private:
		string title;
		string dueDate;
		bool renew;


};

#endif //BOOK_H
