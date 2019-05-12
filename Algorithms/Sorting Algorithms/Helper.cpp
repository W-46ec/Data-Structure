
/*
 * Helper.cpp
 *
 * Description: Some helper functions.
 *
 *
 */

#ifndef HELPER_H
#define HELPER_H

#include <iostream>

using namespace std;

// Desc: Fills the array with random integers.
void fillIntArr(int *arr, int length) {
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (100 * length);
} // fillIntArr

// Desc: Prints the content of the array.
template <class T>
void printArr(const T *arr, int length) {
	for (int i = 0; i < length; i++)
		cout << arr[i] << "  ";
	cout << endl;
} // printArr

// Desc: Returns true if the array is in increasing order.
template <class T>
bool isIncreasing(const T *arr, int length) {
	for (int i = 1; i < length; i++)
		if (arr[i] < arr[i - 1])
			return false;
	return true;
} // isIncreasing

#endif

// End of Helper.cpp

