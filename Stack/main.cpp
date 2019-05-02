
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
#include "Stack.h"

using namespace std;

int main() {

	srand(time(NULL));

	int n = 5;
	int num = rand() % n;

	// Test for int.
	Stack<int> S;
	for (int i = 0; i < n; i++) {
		int x = rand() % n;
		cout << endl << "push(" << x << "):" << endl;
		S.push(x);
		cout << "size: " << S.size() << endl;
		cout << S << endl;
	}
	cout << "\nCopy constructor test." << endl;
	Stack<int> S1 = S;
	for (int i = 0; i < num; i++) {
		cout << endl << "top: " << S1.top() << endl;
		cout << "pop(): " << S1.pop() << endl;
		cout << "size: " << S1.size() << endl;
		cout << "stack: " << S1 << endl;
	}
	cout << "\nS == S1: " << (S == S1) << endl;
	cout << "\nAssignment operator test." << endl;
	S = S1;
	cout << "S == S1: " << (S == S1) << endl;
	cout << "size: " << S.size() << endl;
	cout << "S: " << S << endl;

	// Test for string.
	Stack<string> str_S;
	string s = "a";
	for (int i = 0; i < n; i++) {
		str_S.push(s);
		cout << endl << "push(" << s << "):" << endl;
		cout << "size: " << str_S.size() << endl;
		cout << str_S << endl;
		s += 'a' + (i + 1) % 26;
	}
	cout << "\nCopy constructor test." << endl;
	Stack<string> str_S1 = str_S;
	for (int i = 0; i < num; i++) {
		cout << endl << "top: " << str_S1.top() << endl;
		cout << "pop(): " << str_S1.pop() << endl;
		cout << "size: " << str_S1.size() << endl;
		cout << "stack: " << str_S1 << endl;
	}
	cout << "\nstr_S == str_S1: " << (str_S == str_S1) << endl;
	cout << "\nAssignment operator test." << endl;
	str_S = str_S1;
	cout << "str_S == str_S1: " << (str_S == str_S1) << endl;
	cout << "size: " << str_S.size() << endl;
	cout << "str_S: " << str_S << endl;

	return 0;
} // main

// End of main.cpp

