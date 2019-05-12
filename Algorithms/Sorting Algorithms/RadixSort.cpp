
/*
 * RadixSort.cpp
 *
 * Description: Radix sort algorithm for integer.
 *
 *
 */

#include <cmath>

// Desc: Utility function.
// Post: Returns the maximum number of digit required for elements in arr[].
int getMaxDigit(const int arr[], int length) {
	int maxIdx = 0, digits = 0;
	for (int i = 1; i < length; i++)
		maxIdx = arr[i] > arr[maxIdx] ? i : maxIdx;
	int tmp = arr[maxIdx];
	while (tmp > 0) {
		digits++;
		tmp /= 10;
	}
	return digits;
} // getMaxDigit

// Desc: Performs counting sort on the digit represented by "exp", 
//       where "exp" is the exponent of 10 of the corresponding digit.
void countingSort(int arr[], int length, int exp) {
	int *tmp = new int[length];
	int count[10] = {0};

	// Compute frequencies of a specific digit.
	for (int i = 0; i < length; i++)
		count[(arr[i] / (int)pow(10.0, exp)) % 10]++;

	// Compute ranks.
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Place elements based on ranks.
	for (int i = length - 1; i >= 0; i--)
		tmp[--count[(arr[i] / (int)pow(10.0, exp)) % 10]] = arr[i];

	// Copy the outputs back to the original array.
	for (int i = 0; i < length; i++)
		arr[i] = tmp[i];

	delete [] tmp;
} // countingSort

// Desc: Radix sort.
// Post: arr[] is sorted in increasing order.
void RadixSort(int arr[], int length) {
	int maxDigits = getMaxDigit(arr, length);
	for (int exp = 0; exp < maxDigits; exp++)
		countingSort(arr, length, exp);
} // RadixSort

// End of RadixSort.cpp

