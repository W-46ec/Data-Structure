
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

	int n = 20;
	int num = rand() % n;
	int *A = new int[n];

	for (int i = 0; i < n; i++) {
		A[i] = rand() % n;
	}

	Heap<int> H(A, n, min_heap);
	cout << H << endl;

	cout << "num = " << num << endl;
	while (num--) {
		getchar();
		cout << "delete: " << H.extractRoot() << endl;
		cout << H << endl;
		cout << "size: " << H.size() << endl;
	}

	delete [] A;
	return 0;
} // main

// End of main.cpp

