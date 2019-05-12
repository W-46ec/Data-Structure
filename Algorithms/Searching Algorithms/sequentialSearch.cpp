
/*
 * sequentialSearch.cpp
 *
 * Description: Sequential Search (template).
 *
 *
 */

// Desc: Sequential Search.
// Post: Returns the index of the target if it can be found in the array.
//       Otherwise, return -1.
template <class T>
int sequentialSearch(const T arr[], int length, const T &target) {
	for (int i = 0; i < length; i++)
		if (arr[i] == target)
			return i;
	return -1;
} // sequentialSearch


// // Desc: Sequential Search (Recursive implementation).
// // Post: Returns the index of the target if it can be found in the array.
// //       Otherwise, return -1.
// template <class T>
// int sequentialSearch(const T arr[], int length, const T &target) {
// 	if (length <= 0) {
// 		return -1;
// 	} else {
// 		return (arr[length - 1] == target) ? length - 1 : sequentialSearch(arr, length - 1, target);
// 	}
// } // sequentialSearch

// End of sequentialSearch.cpp

