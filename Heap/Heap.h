
/*
 * Heap.h
 *
 * Class Description: Binary Heap data structure (template).
 * Class Invariant: Each node has a smaller / greater (depends on "type") key than its children.
 *
 *
 */


#pragma once

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Desc: The type of heap.
typedef enum Type {
	min_heap, max_heap
} heapType;

// Desc: Comparison function.
// Post: Return true if x is greater than y.
template <class T>
bool isGreater(const T &x, const T &y) {
	return x > y;
} // isGreater

// Desc: Comparison function.
// Post: Return true if x is smaller than y.
template <class T>
bool isSmaller(const T &x, const T &y) {
	return x < y;
} // isSmaller



template <class T>
class Heap {
private:
	static int const INITIAL_SIZE = 8;		// Initial capacity
	int length;		// Number of elements in the heap.
	int capacity;	// The maximum number of elements it can hold.
	heapType type;	// Either min_heap or max_heap.
	T *elements;	// Elements

	// Utility functions

	// Desc: Comparison function.
	// Post: Returns true if x has higher priority than y.
	bool (*prior)(const T& x, const T &y);

	// Desc: Swaps two objects.
	void swap(T &x, T &y);

	// Desc: Heapifies a subtree rooted at the given index.
	//  Pre: The given index is a valid index.
	//       Both its left and right subtrees are heaps.
	void heapify(int index);

	// Desc: Trickle up the tree, so that the heap properties can be maintained.
	void trickleUp(int index);

	// Desc: Prints the content of the heap in form of binary tree (Helper function).
	void display(int index, bool drawBranch[]) const;

public:
	// Desc: Default constructor
	// Post: By default, heap type is min_heap.
	Heap();

	// Desc: Non-default constructor
	// Post: Capacity is 1 unit larger than the length of given array.
	Heap(const T *arr, int length, heapType type);

	// Desc: Copy constructor
	Heap(const Heap &rhs);

	// Desc: Destructor
	~Heap();

	// Desc: Returns the heap type.
	heapType getType() const;

	// Desc: Builds a heap from a given array of given size.
	// Post: Capacity is 1 unit larger than the length of given array.
	void initHeap(const T *arr, int length, heapType type);

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

	// Desc: "Equal to" operator.
	// Post: Returns true if the type and the content of two heaps are the same.
	bool operator == (const Heap &rhs) const;

	// Desc: Prints the content of the heap in form of binary tree.
	template <class K>
	friend ostream& operator << (ostream& os, const Heap<K> &H);

}; // Heap


// Utility functions

// Desc: Swaps two objects.
template <class T>
void Heap<T>::swap(T &x, T &y) {
	if (&x != &y) {
		T tmp = x;
		x = y;
		y = tmp;
	}
} // swap

// Desc: Heapifies a subtree rooted at the given index.
//  Pre: The given index is a valid index.
//       Both its left and right subtrees are heaps.
template <class T>
void Heap<T>::heapify(int index) {
	if (index < 0 || index > (length - 2) / 2)	// Invalid index or leaf node.
		return;
	int left = 2 * index + 1, right = 2 * index + 2, priorIdx = index;
	if (right < length && prior(elements[right], elements[index]))	// Right child has higher priority.
		priorIdx = right;
	if (prior(elements[left], elements[priorIdx]))	// Left child has higher priority.
		priorIdx = left;
	if (priorIdx != index) {	// One of the children has higher priority.
		swap(elements[index], elements[priorIdx]);
		heapify(priorIdx);
	}
} // heapify

// Desc: Trickle up the tree, so that the heap properties can be maintained.
template <class T>
void Heap<T>::trickleUp(int index) {
	if (index <= 0 || index >= length)	// Root node or invalid index.
		return;
	int parent = (index - 1) / 2;
	if (prior(elements[index], elements[parent])) {
		swap(elements[index], elements[parent]);
		trickleUp(parent);
	}
} // trickleUp

// Desc: Prints the content of the heap in form of binary tree (Helper function).
template<class T>
void Heap<T>::display(int index, bool drawBranch[]) const {
	if (index == length) {
		
		// If there's left child but no right child, place an "NULL" 
		// at right child's position. It happens only to the last node.
		cout << "NULL" << endl;
	} else {	// Print the elements.
		cout << elements[index] << endl;
	}

	// Leaf or invalid index.
	if (index > (length - 2) / 2)
		return;

	int left = 2 * index + 1, right = 2 * index + 2, parent = (index - 1) / 2;
	int level = (int)log2((float)(index + 1)), count;

	// Set the "drawBranch" of previous level to false if current node
	// is the left child of its parent. Otherwise, set it to true.
	if (index > 0 && 2 * parent + 1 == index) {
		drawBranch[level - 1] = false;
	} else if (index > 0 && 2 * parent + 2 == index) {
		drawBranch[level - 1] = true;
	}

	string branch1 = "|   ", branch2 = "|---", spaces = "    ";
	count = 0;
	while (count++ < level) {	// Draw branches.
		if (drawBranch[count - 1]) {
			cout << branch1;
		} else {
			cout << spaces;
		}
	}
	cout << branch2;
	display(right, drawBranch);

	count = 0;
	while (count++ < level) {	// Draw branches.
		if (drawBranch[count - 1]) {
			cout << branch1;
		} else {
			cout << spaces;
		}
	}
	cout << branch2;
	display(left, drawBranch);

	// Draw gaps between siblings.
	if (index == 2 * parent + 2) {
		for (int i = 0; i < level - 1; i++) {
			if (drawBranch[i]) {
				cout << branch1;
			} else {
				cout << spaces;
			}
		}
		cout << branch1 << endl;
	}
} // display


// Desc: Default constructor
// Post: By default, heap type is min_heap.
template <class T>
Heap<T>::Heap() {
	capacity = INITIAL_SIZE;
	type = min_heap;
	prior = &isSmaller<T>;
	length = 0;
	elements = new T[capacity];
} // Default constructor

// Desc: Non-default constructor
// Post: Capacity is 1 unit larger than the length of given array.
template <class T>
Heap<T>::Heap(const T *arr, int length, heapType type) {
	capacity = length + 1;
	this -> length = length;
	this -> type = type;
	prior = (type == min_heap) ? &isSmaller<T> : &isGreater<T>;
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
	type = rhs.type;
	prior = (type == min_heap) ? &isSmaller<T> : &isGreater<T>;
	elements = new T[capacity];
	for (int i = 0; i < length; i++)
		elements[i] = rhs.elements[i];
} // Copy constructor

// Desc: Destructor
template <class T>
Heap<T>::~Heap() {
	delete [] elements;
} // Destructor

// Desc: Returns the heap type.
template <class T>
heapType Heap<T>::getType() const {
	return type;
} // getType

// Desc: Builds a heap from a given array of given size.
// Post: Capacity is 1 unit larger than the length of given array.
template <class T>
void Heap<T>::initHeap(const T *arr, int length, heapType type) {
	if (capacity > 0)
		delete [] elements;
	capacity = length + 1;
	this -> length = length;
	this -> type = type;
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
	type = rhs.type;
	elements = new T[capacity];
	for (int i = 0; i < length; i++)
		elements[i] = rhs.elements[i];
	return *this;
} // operator =

// Desc: "Equal to" operator.
// Post: Returns true if the type and the content of two heaps are the same.
template <class T>
bool Heap<T>::operator == (const Heap<T> &rhs) const {
	if (this == &rhs)
		return true;
	if ((length != rhs.length) || (type != rhs.type))
		return false;
	for (int i = 0; i < length; i++) {
		if (elements[i] != rhs.elements[i])
			return false;
	}
	return true;
} // operator ==

// Desc: Prints the content of the heap in form of binary tree (Helper function).
template <class K>
ostream& operator << (ostream& os, const Heap<K> &H) {
	if (H.length <= 0) {
		os << "NULL" << endl;
	}  else if (H.length == 1) {
		os << H.elements[0] << endl;
	} else {
		int height = (int)log2((float)(H.length));
		bool *drawBranch = new bool[height];
		H.display(0, drawBranch);
		delete [] drawBranch;
	}
	return os;
} // operator <<

// End of Heap.h

