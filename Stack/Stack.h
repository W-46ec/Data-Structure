
/*
 * Stack.h
 *
 * Class Description: Stack ADT (template).
 * Class Invariant: A sequence of data with push/pop in LIFO order.
 *
 *
 */


#pragma once

#include <iostream>

using namespace std;

template <class T>
class Stack {
private:
	static unsigned const INITIAL_SIZE = 8;		// Initial capacity
	int capacity;	// The maximum number of elements it can hold.
	int length;		// Number of elements in the stack.
	T *arr;			// Sequence of data.
public:

	Stack();	// Constructor
	Stack(const Stack &rhs);	// Copy constructor
	~Stack();	// Destructor

	// Desc: Pushes the given element into the stack.
	// Post: The given element is being inserted to the top of the stack.
	//       Capacity is doubled if the stack is full.
	void push(const T &x);

	// Desc: Removes and returns the element at top of the stack.
	//  Pre: Stack is not empty.
	// Post: Top element is being removed. Size is decreased by 1.
	T pop();

	// Desc: Returns a reference to the topmost element of the stack.
	//  Pre: Stack is not empty.
	T& top() const;

	// Desc: Returns the size of the stack.
	int size() const;

	// Returns whether the stack is empty.
	bool empty() const;

	// Desc: Prints the content of the stack.
	template <class K>
	friend ostream& operator << (ostream& os, const Stack<K> &S);

}; // Stack

// Desc: Default constructor
template <class T>
Stack<T>::Stack() {
	capacity = INITIAL_SIZE;
	length = 0;
	arr = new T[capacity];
} // Stack

// Desc: Copy constructor
template <class T>
Stack<T>::Stack(const Stack &rhs) {
	capacity = rhs.capacity;
	length = rhs.length;
	arr = new T[capacity];
	for (int i = 0; i < length; i++)
		arr[i] = rhs.arr[i];
} // Stack

// Desc: Destructor
template <class T>
Stack<T>::~Stack() {
	delete [] arr;
} // ~Stack

// Desc: Pushes the given element into the stack.
// Post: The given element is being inserted to the top of the stack.
//       Capacity is doubled if the stack is full.
template <class T>
void Stack<T>::push(const T &x) {
	arr[length++] = x;

	// Stack is full.
	if (length == capacity) {
		capacity *= 2;
		T *tmp = new T[capacity];
		for (int i = 0; i < length; i++) {
			tmp[i] = arr[i];
		}
		delete [] arr;
		arr = tmp;
	}
} // push

// Desc: Removes and returns the element at top of the stack.
//  Pre: Stack is not empty.
// Post: Top element is being removed. Size is decreased by 1.
template <class T>
T Stack<T>::pop() {
	return arr[--length];
} // pop

// Desc: Returns a reference to the topmost element of the stack.
//  Pre: Stack is not empty.
template <class T>
T& Stack<T>::top() const {
	return arr[length - 1];
} // top

// Desc: Returns the size of the stack.
template <class T>
int Stack<T>::size() const {
	return length;
} // size

// Returns whether the stack is empty.
template <class T>
bool Stack<T>::empty() const {
	return (length == 0);
} // empty

// Desc: Prints the content of the stack.
template <class K>
ostream& operator << (ostream& os, const Stack<K> &S) {
	for (int i = 0; i < S.length; i++) {
		cout << S.arr[i] << " ";
	}
	return os;
}

// End of Stack.h

