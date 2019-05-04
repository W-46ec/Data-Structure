
/*
 * MergeSort.cpp
 *
 * Description: Merge sort (template).
 *
 *
 */

// Desc: Merges two sub-arrays (template).
//  Pre: arr[low ... mid] is sorted in increasing order.
//       arr[mid + 1 ... high] is sorted in increasing order.
// Post: arr[low .. high] is sorted in increasing order.
template <class T>
void Merge(T arr[], int low, int mid, int high) {
	if (low >= high)	// The array has only one element or arguments are invalid.
		return;
	T *tmpArr = new T[high - low + 1];	// Temporary space.
	int i = low, j = mid + 1, idx = 0;

	while (i <= mid && j <= high) {
		if (arr[i] < arr[j])
			tmpArr[idx++] = arr[i++];
		else
			tmpArr[idx++] = arr[j++];
	}

	while (i <= mid)	// Copy the remaining elements from the first part.
		tmpArr[idx++] = arr[i++];

	while (j <= high)	// Copy the remaining elements from the second part.
		tmpArr[idx++] = arr[j++];

	for (i = low; i <= high; i++)	// Copy the elements back to the original array.
		arr[i] = tmpArr[i - low];

	delete [] tmpArr;
} // Merge

// Desc: Merge Sort.
// Post: arr[low ... high] is sorted in increasing order.
template <class T>
void MergeSort(T arr[], int low, int high) {
	if (low >= high)	// The array has only one element or arguments are invalid.
		return;
	int mid = (low + high) / 2;
	MergeSort<T>(arr, low, mid);
	MergeSort<T>(arr, mid + 1, high);
	Merge<T>(arr, low, mid, high);
} // MergeSort

// End of MergeSort.cpp

