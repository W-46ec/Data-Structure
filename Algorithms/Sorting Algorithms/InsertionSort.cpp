
/*
 * InsertionSort.cpp
 *
 * Description: Insertion sort (template).
 *
 *
 */

// Desc: Insertion sort.
// Post: arr[] is sorted in increasing order.
template <class T>
void InsertionSort(T arr[], int length) {
	for (int i = 1; i < length; i++) {
		if (arr[i] < arr[i - 1]) {
			T tmp = arr[i];
			int j = i;
			while (j > 0 && tmp < arr[j - 1]) {
				arr[j] = arr[j - 1];
				j--;
			}
			arr[j] = tmp;
		}
	}
} // InsertionSort

// End of InsertionSort.cpp

