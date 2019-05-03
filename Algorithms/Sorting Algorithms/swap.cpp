
/*
 * swap.cpp
 *
 * Description: Swapping function (Helper function).
 *
 *
 */

#ifndef SWAP_H
#define SWAP_H

// Desc: Swapping function.
template <class T>
void swap(T &x, T &y) {
	if (&x != &y) {
		T tmp = x;
		x = y;
		y = tmp;
	}
} // swap

#endif

// End of swap.cpp

