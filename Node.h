/*
 * Rachel Prusacki
 * 10/15/2021
 * COSC220
 * Creates Node class for a doubly linked list of Students
 */

#ifndef NODE_H
#define NODE_H

#include "Student.h"

using namespace std;

class Node {
	public:
		Student value;
		Node * prev;
		Node * next;

		Node() {
			next = this;
			prev = this;
		}

		Node (Student s) {
			value = s;
			next = this;
			prev = this;
		}
};

#endif //NODE_H
