
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

#include "bubbleSort.cpp"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"
#include "MergeSort.cpp"

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

	int *A = new int[n];

	// Bubble Sort
	cout << "\nBubble Sort: " << endl;
	fillIntArr(A, n);
	printArr<int>(A, n);
	bubbleSort<int>(A, n);
	printArr<int>(A, n);

	// Insertion Sort
	cout << "\nInsertion Sort: " << endl;
	fillIntArr(A, n);
	printArr<int>(A, n);
	InsertionSort<int>(A, n);
	printArr<int>(A, n);

	// Selection Sort
	cout << "\nSelection Sort: " << endl;
	fillIntArr(A, n);
	printArr<int>(A, n);
	SelectionSort<int>(A, n);
	printArr<int>(A, n);

	// Merge Sort
	cout << "\nMerge Sort: " << endl;
	fillIntArr(A, n);
	printArr<int>(A, n);
	MergeSort<int>(A, 0, n - 1);
	printArr<int>(A, n);

	delete [] A;

	return 0;
} // main

// End of main.cpp

