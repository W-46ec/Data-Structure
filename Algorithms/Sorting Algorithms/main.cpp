
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
#include <unistd.h>	// Needed for sleep()

#include "bubbleSort.cpp"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"

#define N 100000

using namespace std;

void fillIntArr(int *arr, int length) {
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (100 * length);
} // fillIntArr

template <class T>
void printArr(const T *arr, int length) {
	for (int i = 0; i < length; i++)
		cout << arr[i] << "  ";
	cout << endl;
} // printArr

int main() {

	srand(time(NULL));
	int n = 10;
	clock_t start;

	int *A = new int[n];

	// Bubble Sort
	cout << "\nBubble Sort: " << endl;
	start = clock();
	for (int i = 0; i < N; i++) {
		fillIntArr(A, n);
		bubbleSort<int>(A, n);
	}
	cout << "Completed in " << (clock() - start) / (double)(CLOCKS_PER_SEC) << " seconds." << endl;
	sleep(1);	// Wait for 1 second.

	// Insertion Sort
	cout << "\nInsertion Sort: " << endl;
	start = clock();
	for (int i = 0; i < N; i++) {
		fillIntArr(A, n);
		InsertionSort<int>(A, n);
	}
	cout << "Completed in " << (clock() - start) / (double)(CLOCKS_PER_SEC) << " seconds." << endl;
	sleep(1);	// Wait for 1 second.

	// Selection Sort
	cout << "\nSelection Sort: " << endl;
	start = clock();
	for (int i = 0; i < N; i++) {
		fillIntArr(A, n);
		SelectionSort<int>(A, n);
	}
	cout << "Completed in " << (clock() - start) / (double)(CLOCKS_PER_SEC) << " seconds." << endl;
	sleep(1);	// Wait for 1 second.

	// Merge Sort
	cout << "\nMerge Sort: " << endl;
	start = clock();
	for (int i = 0; i < N; i++) {
		fillIntArr(A, n);
		MergeSort<int>(A, 0, n - 1);
	}
	cout << "Completed in " << (clock() - start) / (double)(CLOCKS_PER_SEC) << " seconds." << endl;
	sleep(1);	// Wait for 1 second.

	// Quick Sort
	cout << "\nQuick Sort: " << endl;
	start = clock();
	for (int i = 0; i < N; i++) {
		fillIntArr(A, n);
		QuickSort<int>(A, 0, n - 1);
	}
	cout << "Completed in " << (clock() - start) / (double)(CLOCKS_PER_SEC) << " seconds." << endl;
	sleep(1);	// Wait for 1 second.

	delete [] A;

	return 0;
} // main

// End of main.cpp

