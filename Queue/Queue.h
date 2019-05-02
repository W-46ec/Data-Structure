
/*
 * Queue.h
 *
 * Class Description: Queue ADT (template).
 * Class Invariant: A sequence of data with enqueue/dequeue in FIFO order.
 *
 *
 */


#pragma once

#include <iostream>

using namespace std;

template <class T>
class Queue {
private:
	static int const INITIAL_SIZE = 8;		// Initial capacity
	int length;			// Number of elements in the queue.
	int capacity;		// The maximum number of elements it can hold.
	int frontIndex;		// Index of the topmost element.
	int backIndex;		// Index where the next element will be placed.
	T *arr;				// Sequence of data.

public:

	Queue();	// Constructor
	Queue(const Queue &rhs);	// Copy constructor
	~Queue();	// Destructor

	// Desc: Returns true if Queue is empty.
	bool empty() const;

	// Desc: Returns the size of the stack.
	int size() const;

	// Desc: Inserts the given element at the back of the Queue.
	// Post: The element is being inserted to the back of the queue.
	//       Size is increased by 1.
	//       Capacity is doubled if the queue is full.
	void enqueue(const T &x);

	// Desc: Removes the element at the front.
	//  Pre: Queue not empty.
	// Post: The topmost element is being removed from the front of the queue.
	//       Size is decreased by 1.
	//       Capacity is halved if the array is less than 1/4 full.
	//       However, capacity can never be less than INITIAL_SIZE.
	void dequeue();

	// Desc: Returns the reference of the topmost element.
	//  Pre: Queue not empty.
	// Post: Queue remains unchanged.
	T& front() const;

	// Desc: Assignment operator.
	Queue& operator = (const Queue &rhs);

	// Desc: "Equal to" operator.
	// Post: Returns true if the content of two queues are the same.
	bool operator == (const Queue &rhs) const;

	// Desc: Prints the content of the queue.
	template <class K>
	friend ostream& operator << (ostream& os, const Queue<K> &Q);

}; // Queue


// Desc: Constructor
template <class T> Queue<T>::Queue() {
	length = 0;
	capacity = INITIAL_SIZE;
	frontIndex = 0;
	backIndex = 0;
	arr = new T[capacity];
} // Constructor

// Desc: Copy constructor
template <class T> Queue<T>::Queue(const Queue<T> &rhs) {
	length = rhs.length;
	capacity = rhs.capacity;
	frontIndex = rhs.frontIndex;
	backIndex = rhs.backIndex;
	arr = new T[capacity];
	for (int i = 0; i < length; i++) {
		int idx = (frontIndex + i) % capacity;
		arr[idx] = rhs.arr[idx];
	}
} // Copy constructor

// Desc: Destructor
template <class T> Queue<T>::~Queue() {
	delete [] arr;
} // Destructor

// Desc: Returns true if Queue is empty.
template <class T>
bool Queue<T>::empty() const {
	return (length == 0);
} // empty

// Desc: Returns the size of the stack.
template <class T>
int Queue<T>::size() const {
	return length;
} // size

// Desc: Inserts the given element at the back of the Queue.
// Post: The element is being inserted to the back of the queue.
//       Size is increased by 1.
//       Capacity is doubled if the queue is full.
template <class T>
void Queue<T>::enqueue(const T &x) {
	if (length < capacity) {		// enqueue
		length++;
		arr[backIndex] = x;
		backIndex = (backIndex + 1) % capacity;
	} else {		// Resize the queue
		T *tmp = new T[capacity * 2];	// double the capacity
		for (int i = 0; i < length; i++) {	// Copy the values
			tmp[i] = arr[(frontIndex + i) % capacity];
		}

		tmp[length] = x;		// Insert the new value.
		capacity *= 2;
		frontIndex = 0;		// New front index is 0.
		backIndex = ++length;

		delete [] arr;		// Deallocation
		arr = tmp;
	}
} // enqueue

// Desc: Removes the element at the front.
//  Pre: Queue not empty.
// Post: The topmost element is being removed from the front of the queue.
//       Size is decreased by 1.
//       Capacity is halved if the array is less than 1/4 full.
//       However, capacity can never be less than INITIAL_SIZE.
template <class T>
void Queue<T>::dequeue() {

	length--;
	frontIndex = (frontIndex + 1) % capacity;

	// Halve the queue if it is less than 1/4 full
	if ((length < capacity / 4) && (capacity / 2 >= INITIAL_SIZE)) {
		T *tmp = new T[capacity / 2];
		for (int i = 0; i < length; i++) {
			tmp[i] = arr[(frontIndex + i) % capacity];
		}
		capacity /= 2;
		frontIndex = 0;		// New front index is 0.
		backIndex = length;

		delete [] arr;		// Deallocation
		arr = tmp;
	}
} // dequeue

// Desc: Returns the reference of the topmost element.
//  Pre: Queue not empty.
// Post: Queue remains unchanged.
template <class T>
T& Queue<T>::front() const {
	return arr[frontIndex];
} // front

// Desc: Assignment operator.
template <class T>
Queue<T>& Queue<T>::operator = (const Queue<T> &rhs) {
	if (&rhs == this)
		return *this;

	if (this -> capacity > 0)
		delete [] arr;
	length = rhs.length;
	capacity = rhs.capacity;
	frontIndex = rhs.frontIndex;
	backIndex = rhs.backIndex;
	arr = new T[capacity];
	for (int i = 0; i < length; i++) {
		int idx = (frontIndex + i) % capacity;
		arr[idx] = rhs.arr[idx];
	}
	return *this;
} // operator =

// Desc: "Equal to" operator.
// Post: Returns true if the content of two queues are the same.
template <class T>
bool Queue<T>::operator == (const Queue<T> &rhs) const {
	if (this == &rhs)
		return true;
	if (length != rhs.length)
		return false;
	for (int i = 0; i < length; i++) {
		int idx1 = (frontIndex + i) % capacity;
		int idx2 = (rhs.frontIndex + i) % rhs.capacity;
		if (arr[idx1] != rhs.arr[idx2])
			return false;
	}
	return true;
} // operator ==

// Desc: Prints the content of the queue.
template <class K>
ostream& operator << (ostream& os, const Queue<K> &Q) {
	for (int i = 0; i < Q.length; i++) {
		os << Q.arr[(Q.frontIndex + i) % Q.capacity] << " ";
	}
	return os;
} // operator <<

// End of Queue.h

