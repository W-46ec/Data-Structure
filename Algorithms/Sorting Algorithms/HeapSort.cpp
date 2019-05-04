
/*
 * HeapSort.cpp
 *
 * Description: Heap sort (template).
 *
 *
 */

#include "swap.cpp"

// Desc: Comparison function.
// Post: Return true if x is greater than y.
template <class T>
bool isGreater(const T &x, const T &y) {
	return x > y;
} // isGreater

// Desc: Heapifies a subtree rooted at the given index.
//  Pre: The given index is a valid index.
//       Both its left and right subtrees are heaps.
template <class T>
void heapify(int index, T arr[], int length) {
	if (index < 0 || index > (length - 2) / 2 || length <= 1)	// Invalid index or leaf node.
		return;
	int left = 2 * index + 1, right = 2 * index + 2, priorIdx = index;
	if (right < length && isGreater<T>(arr[right], arr[index]))	// Right child has higher priority.
		priorIdx = right;
	if (isGreater<T>(arr[left], arr[priorIdx]))	// Left child has higher priority.
		priorIdx = left;
	if (priorIdx != index) {	// One of the children has higher priority.
		swap<T>(arr[index], arr[priorIdx]);
		heapify<T>(priorIdx, arr, length);
	}
} // heapify

// Desc: Heap sort.
// Post: arr[] is sorted in increasing order.
template <class T>
void HeapSort(T arr[], int length) {

	// Build a max-heap --- (O(N)).
	for (int i = (length - 2) / 2; i >= 0; i--)
		heapify<T>(i, arr, length);

	// Call length * extractRoot() --- (O(NlogN)).
	for (int i = length - 1; i >= 0; i--) {
		swap<T>(arr[0], arr[i]);
		heapify<T>(0, arr, i);
	}
} // HeapSort

// End of HeapSort.cpp

