
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
#include "Heap.h"

using namespace std;

int main() {

	srand(time(NULL));

	int n = 10;
	int num = rand() % n + 1;
	cout << "num = " << num << endl;

	// Test for integers.
	int *A = new int[n];
	for (int i = 0; i < n; i++)
		A[i] = rand() % n;

	Heap<int> H1(A, n, max_heap), H2;
	cout << "H1: " << endl;
	H1.getType() == 0 ? cout << "type: min heap" << endl : cout << "type: max heap" << endl;
	cout << H1 << endl;

	cout << "H2: " << endl;
	H2.getType() == 0 ? cout << "type: min heap" << endl : cout << "type: max heap" << endl;
	cout << H2 << endl;

	while (num--) {
		cout << "Press Enter to continue...";
		getchar();
		int root = H1.extractRoot();
		cout << "extract root \"" << root << "\" from H1." << endl;
		cout << "H1: " << endl << H1 << endl;
		cout << "insert " << root << " to H2." << endl;
		H2.insert(root);
		cout << "H2: " << endl << H2 << endl;
	}

	cout << "\nH1 == H2: " << (H1 == H2) << endl;
	cout << "\nAssignment operator test." << endl;
	H1 = H2;
	H1 = H1;
	cout << "H1 == H2: " << (H1 == H2) << endl;
	cout << "H1: " << endl;
	H1.getType() == 0 ? cout << "type: min heap" << endl : cout << "type: max heap" << endl;
	cout << H1 << endl;

	delete [] A;


	// Test for strings.
	Heap<string> str_H1;
	string s = "a";
	for (int i = 0; i < n; i++) {
		str_H1.insert(s);
		s += (rand() % 26 + 'a');
	}

	cout << "str_H1: " << endl;
	str_H1.getType() == 0 ? cout << "type: min heap" << endl : cout << "type: max heap" << endl;
	cout << str_H1 << endl;

	cout << "\nCopy constructor test." << endl;
	Heap<string> str_H2 = str_H1;
	cout << "str_H2: " << endl;
	str_H2.getType() == 0 ? cout << "type: min heap" << endl : cout << "type: max heap" << endl;
	cout << str_H2 << endl;

	num = rand() % n + 1;
	cout << "num = " << num << endl;
	while (num--) {
		cout << "Press Enter to continue...";
		getchar();
		string root = str_H2.extractRoot();
		cout << "extract root \"" << root << "\" from str_H2." << endl;
		cout << "str_H2: " << endl << str_H2 << endl;
	}

	cout << "\nstr_H1 == str_H2: " << (str_H1 == str_H2) << endl;
	cout << "\nAssignment operator test." << endl;
	str_H1 = str_H2;
	str_H1 = str_H1;
	cout << "str_H1 == str_H2: " << (str_H1 == str_H2) << endl;
	cout << "str_H1: " << endl;
	str_H1.getType() == 0 ? cout << "type: min heap" << endl : cout << "type: max heap" << endl;
	cout << str_H1 << endl;

	return 0;
} // main

// End of main.cpp

