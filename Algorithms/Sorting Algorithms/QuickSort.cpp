
/*
 * QuickSort.cpp
 *
 * Description: Quick sort (template).
 *
 *
 */

// Desc: It takes the first element as pivot element,  
//       and perform a partition on arr[low ... high].
// Post: The pivot element is placed at the correct position.
//       Returns the correct position of pivot element.
template <class T>
int Partition(T arr[], int low, int high) {
	T pivot = arr[low];		// Pivot element.
	while (low < high) {
		while (low < high && arr[high] >= pivot)
			high--;
		arr[low] = arr[high];
		while (low < high && arr[low] <= pivot)
			low++;
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
} // Partition

// Desc: Quick sort.
// Post: arr[low ... high] is sorted in increasing order.
template <class T>
void QuickSort(T arr[], int low, int high) {
	if (low < high) {
		int pivot = Partition<T>(arr, low, high);
		QuickSort<T>(arr, low, pivot - 1);
		QuickSort<T>(arr, pivot + 1, high);
	}
} // QuickSort

// End of QuickSort.cpp

