
/*
 * binarySearch.cpp
 *
 * Description: Binary Search (template).
 *
 *
 */

// Desc: Binary Search.
//  Pre: arr[] is sorted in increasing order.
// Post: Returns the index of the target if it can be found in the array.
//       Otherwise, return -1.
template <class T>
int binarySearch(const T arr[], int low, int high, const T &target) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == target)
			return mid;
		if (arr[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
} // binarySearch


// // Desc: Binary Search (Recursive implementation).
// //  Pre: arr[] is sorted in increasing order.
// // Post: Returns the index of the target if it can be found in the array.
// //       Otherwise, return -1.
// template <class T>
// int binarySearch(const T arr[], int low, int high, const T &target) {
// 	if (high >= low) {
// 		int mid = (low + high) / 2;
// 		if (arr[mid] == target)
// 			return mid;
// 		if (arr[mid] > target)
// 			return binarySearch(arr, low, mid - 1, target);
// 		else
// 			return binarySearch(arr, mid + 1, high, target);
// 	} else {
// 		return -1;
// 	}
// } // binarySearch

// End of binarySearch.cpp

