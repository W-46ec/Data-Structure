
/*
 * Heap.h
 *
 * Class Description: Binary Heap data structure (template).
 * Class Invariant: Each node has a smaller / greater (depends on the tag) key than its children.
 *
 *
 */


#pragma once

#include <iostream>

using namespace std;

// Desc: The type of heap.
typedef enum Type {
	min_heap, max_heap
} heapType;

template <class T>
class Heap {
private:
	static int const INITIAL_SIZE = 8;		// Initial capacity
	int (*prior)(const T& x, const T &y);	// Temp
	int length;		// Number of elements in the heap.
	int capacity;	// The maximum number of elements it can hold.
	heapType tag;	// Either min_heap or max_heap.
	T *elements;	// Elements

	// Utility functions

	// Desc: Swaps two elements.
	void swap(T &x, T &y);

	// Desc: Heapifies a subtree with the root at given index.
	//  Pre: The given index is valid.
	//       Both left and right subtrees of the given root are heaps.
	void heapify(int index);

	// Desc: Trickle up the tree, so that the heap properties can be maintained.
	void trickleUp(int index);

public:
	// Desc: Default constructor
	// Post: By default, heap type is min_heap.
	Heap();

	// Desc: Non-default constructor
	// Post: Capacity is 1 unit larger than the length of given array.
	Heap(const T *arr, int length, heapType tag);

	// Desc: Copy constructor
	Heap(const Heap &rhs);

	// Desc: Destructor
	~Heap();

	// Desc: Builds a heap from a given array of given size.
	// Post: Capacity is 1 unit larger than the length of given array.
	void initHeap(const T *arr, int length, heapType tag);

	// Desc: Returns the reference of the root node.
	//  Pre: Heap is not empty.
	T& root() const;

	// Desc: Extracts the root node.
	//  Pre: Heap is not empty.
	// Post: Root node is being removed from the heap.
	//       Length is decreased by 1.
	//       Returns a copy of the root node.
	T extractRoot();

	// Desc: Insert the given element to the correct position in heap.
	// Post: The element is being inserted to the correct position in heap.
	//       Length is increased by 1.
	//       Capacity is doubled if the heap is full.
	void insert(const T &x);

	// Desc: Returns true if Heap is empty.
	bool empty() const;

	// Desc: Returns the size of the heap.
	int size() const;

	// Desc: Assignment operator.
	Heap& operator = (const Heap &rhs);

	// Desc: Prints the content of the heap.
	template <class K>
	friend ostream& operator << (ostream& os, const Heap<K> &H);

};


// Utility functions

// Desc: Swaps two elements.
template <class T>
void Heap<T>::swap(T &x, T &y) {
	if (&x != &y) {
		T tmp = x;
		x = y;
		y = tmp;
	}
} // swap

// Desc: Heapifies a subtree with the root at given index.
//  Pre: The given index is valid.
//       Both left and right subtrees of the given root are heaps.
template <class T>
void Heap<T>::heapify(int index) {
	int left = 2 * index + 1, right = 2 * index + 2;
	if (index < 0 || index > (length - 2) / 2)	// Invalid index or leaf node.
		return;
	if (tag == min_heap) {	// Temp
		int priorIdx = index;
		if (right < length && elements[right] < elements[index])
			priorIdx = right;
		if (elements[left] < elements[priorIdx])
			priorIdx = left;
		if (priorIdx != index) {
			swap(elements[index], elements[priorIdx]);
			heapify(priorIdx);
		}
	} else {	// max_heap
		int priorIdx = index;
		if (right < length && elements[right] > elements[index])
			priorIdx = right;
		if (elements[left] > elements[priorIdx])
			priorIdx = left;
		if (priorIdx != index) {
			swap(elements[index], elements[priorIdx]);
			heapify(priorIdx);
		}
	}
} // heapify

// Desc: Trickle up the tree, so that the heap properties can be maintained.
template <class T>
void Heap<T>::trickleUp(int index) {
	if (index <= 0 || index >= length)	// Root node or invalid index.
		return;
	int parent = (index - 1) / 2;
	if (tag == min_heap) {	// Temp
		if (elements[index] < elements[parent]) {
			swap(elements[index], elements[parent]);
			trickleUp(parent);
		}
	} else {	// max heap
		if (elements[index] > elements[parent]) {
			swap(elements[index], elements[parent]);
			trickleUp(parent);
		}
	}
} // trickleUp


// Desc: Default constructor
// Post: By default, heap type is min_heap.
template <class T>
Heap<T>::Heap() {
	capacity = INITIAL_SIZE;
	tag = min_heap;
	length = 0;
	elements = new T[capacity];
} // Default constructor

// Desc: Non-default constructor
// Post: Capacity is 1 unit larger than the length of given array.
template <class T>
Heap<T>::Heap(const T *arr, int length, heapType tag) {
	capacity = length + 1;
	this -> length = length;
	this -> tag = tag;
	elements = new T[capacity];
	for (int i = 0; i < length; i++)
		elements[i] = arr[i];
	for (int i = (length - 2) / 2; i >= 0; i--)
		heapify(i);
} // Non-default constructor

// Desc: Copy constructor
template <class T>
Heap<T>::Heap(const Heap &rhs) {
	length = rhs.length;
	capacity = rhs.capacity;
	tag = rhs.tag;
	elements = new T[capacity];
	for (int i = 0; i < length; i++)
		elements[i] = rhs.elements[i];
} // Copy constructor

// Desc: Destructor
template <class T>
Heap<T>::~Heap() {
	delete [] elements;
} // Destructor

// Desc: Builds a heap from a given array of given size.
// Post: Capacity is 1 unit larger than the length of given array.
template <class T>
void Heap<T>::initHeap(const T *arr, int length, heapType tag) {
	if (capacity > 0) {
		delete [] elements;
	}
	capacity = length + 1;
	this -> length = length;
	this -> tag = tag;
	elements = new T[capacity];
	for (int i = 0; i < length; i++)
		elements[i] = arr[i];
	for (int i = (length - 2) / 2; i >= 0; i--)
		heapify(i);
} // initHeap

// Desc: Returns the reference of the root node.
//  Pre: Heap is not empty.
template <class T>
T& Heap<T>::root() const {
	return elements[0];
} // root

// Desc: Extracts the root node.
//  Pre: Heap is not empty.
// Post: Root node is being removed from the heap.
//       Length is decreased by 1.
//       Returns a copy of the root node.
template <class T>
T Heap<T>::extractRoot() {
	T root = elements[0];
	elements[0] = elements[--length];
	heapify(0);
	return root;
} // extractRoot

// Desc: Insert the given element to the correct position in heap.
// Post: The element is being inserted to the correct position in heap.
//       Length is increased by 1.
//       Capacity is doubled if the heap is full.
template <class T>
void Heap<T>::insert(const T &x) {
	if (length < capacity) {	// Heap is not full.
		elements[length++] = x;
		trickleUp(length - 1);
	} else {	// Heap is full.
		capacity *= 2;
		T *tmp = new T[capacity];
		for (int i = 0; i < length; i++)
			tmp[i] = elements[i];
		delete [] elements;
		elements = tmp;
		elements[length++] = x;
		trickleUp(length - 1);
	}
} // insert

// Desc: Returns true if Heap is empty.
template <class T>
bool Heap<T>::empty() const {
	return (length == 0);
} // empty

// Desc: Returns the size of the heap.
template <class T>
int Heap<T>::size() const {
	return length;
} // size

// Desc: Assignment operator.
template <class T>
Heap<T>& Heap<T>::operator = (const Heap<T> &rhs) {
	if (&rhs == this)
		return *this;
	if (this -> capacity > 0)
		delete [] elements;
	length = rhs.length;
	capacity = rhs.capacity;
	tag = rhs.tag;
	elements = new T[capacity];
	for (int i = 0; i < length; i++)
		elements[i] = rhs.elements[i];
	return *this;
} // operator =

// Desc: Prints the content of the heap.
template <class K>
ostream& operator << (ostream& os, const Heap<K> &H) {
	// Temp
	for (int i = 0; i < H.length; i++) {
		os << H.elements[i] << " ";
	}
	return os;
} // operator <<

// End of Heap.h

