
/*
 * bubbleSort.cpp
 *
 * Description: Bubble sort (template).
 *
 *
 */

#include "swap.cpp"

// Desc: Bubble sort.
// Post: arr[] is sorted in increasing order.
template <class T>
void bubbleSort(T arr[], int length) {
	bool changed = true;
	for (int i = 0; i < length && changed; i++) {
		changed = false;
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap<T>(arr[j], arr[j + 1]);
				changed = true;
			}
		}
	}
} // bubbleSort

// End of bubbleSort.cpp

