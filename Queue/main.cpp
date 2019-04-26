
/*
 * main.cpp
 *
 * Description: main file.
 *
 *
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Queue.h"

using namespace std;

int main() {

	srand(time(NULL));

	int n = 9;
	int num = rand() % n;

	// Test for int.
	Queue<int> Q;
	for (int i = 0; i < n; i++) {
		int x = rand() % n;
		cout << endl << "enqueue(" << x << "):" << endl;
		Q.enqueue(x);
		cout << "size: " << Q.size() << endl;
		cout << Q << endl;
	}
	cout << "\nCopy constructor test." << endl;
	Queue<int> Q1 = Q;
	for (int i = 0; i < num; i++) {
		cout << endl << "front: " << Q1.front() << endl;
		cout << "dequeue()" << endl;
		Q1.dequeue();
		cout << "size: " << Q1.size() << endl;
		cout << "Queue: " << Q1 << endl;
	}
	cout << "\nAssignment operator test." << endl;
	Q = Q1;
	cout << "size: " << Q.size() << endl;
	cout << "Q: " << Q << endl;

	// Test for string.
	Queue<string> str_Q;
	string s = "a";
	for (int i = 0; i < n; i++) {
		cout << endl << "enqueue(" << s << "):" << endl;
		str_Q.enqueue(s);
		cout << "size: " << str_Q.size() << endl;
		cout << str_Q << endl;
		s += 'a' + (i + 1) % 26;
	}
	cout << "\nCopy constructor test." << endl;
	Queue<string> str_Q1 = str_Q;
	for (int i = 0; i < num; i++) {
		cout << endl << "front: " << str_Q1.front() << endl;
		cout << "dequeue()" << endl;
		str_Q1.dequeue();
		cout << "size: " << str_Q1.size() << endl;
		cout << "Queue: " << str_Q1 << endl;
	}
	cout << "\nAssignment operator test." << endl;
	str_Q = str_Q1;
	cout << "size: " << str_Q.size() << endl;
	cout << "str_Q: " << str_Q << endl;

	return 0;
} // main

// End of main.cpp

