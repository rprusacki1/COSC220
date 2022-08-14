/*
 * Rachel Prusacki, 10/15/2021
 * COSC220
 * Implements functions from the Book class
 */

#include "Book.h"

#include <iostream>
#include <string>

using namespace std;

Book :: Book (string t, string d, int r) {
	title = t;
	dueDate = d;

	if (r == 0)
		renew = true;
	else
		renew = false;

}

Book :: Book () {
	title = "";
	dueDate = "";
	renew = false;
}

void Book :: printBook () {
	cout << "Title: " << title << endl;

	cout << "Due Date: " << dueDate << endl;

	if (renew)
		cout << title << " is renewable." << endl;
	else
		cout << title << " is not renewable." << endl;

}

void Book :: updatedueDate () {
	if (renew) {
		cout << "Enter new Due Date: " << endl;
		getline(cin, dueDate);
	}

	else
		cout << title << " is not renewable." << endl;

}

string Book :: getTitle() {
	return title;
}

string Book :: getDate() {
	return dueDate;
}

bool Book :: getRenew() {
	return renew;
}
