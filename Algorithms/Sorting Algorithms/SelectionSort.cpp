
/*
 * SelectionSort.cpp
 *
 * Description: Selection sort (template).
 *
 *
 */

#include "swap.cpp"

// Desc: Selection sort.
template <class T>
void SelectionSort(T arr[], int length) {
	for (int i = length - 1; i >= 0; i--) {
		int maxIdx = 0;
		for (int j = 1; j <= i; j++)
			if (arr[j] > arr[maxIdx])
				maxIdx = j;
		swap<T>(arr[maxIdx], arr[i]);
	}
} // SelectionSort

// End of SelectionSort.cpp

