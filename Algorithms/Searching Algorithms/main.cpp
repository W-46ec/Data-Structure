
/*
 * main.cpp
 *
 * Description: main file.
 *
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "sequentialSearch.cpp"
#include "binarySearch.cpp"

#include "Helper.cpp"

using namespace std;

int main() {

	srand(time(NULL));
	int n = 1000;
	int *A = new int[n];

	fillIntArr(A, n);
	for (int i = 0; i < n; i++) {
		if (sequentialSearch<int>(A, n, A[i]) == -1)
			cout << "Error!!!" << endl;
	}

	fillIntArr(A, n);
	QuickSort(A, 0, n - 1);
	if (isIncreasing<int>(A, n)) {
		for (int i = 0; i < n; i++) {
			if (binarySearch<int>(A, 0, n - 1, A[i]) == -1)
				cout << "Error!!!" << endl;
		}
	} else {
		cout << "Not increasing." << endl;
	}

	delete [] A;

	return 0;
} // main

// End of main.cpp

