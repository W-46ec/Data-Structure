
/*
 * BTnode.h
 *
 * Class Description: Binary search tree node (template).
 *
 *
 */

#pragma once

#include <iostream>

using namespace std;

template <class T>
class BTnode {
public:
	T key;
	unsigned depth;		// Number of edges from current node to root.
	BTnode *left, *right, *parent;

	// Constructors
	BTnode();
	BTnode(const T &key);
	BTnode(const T &key, BTnode<T> *left, BTnode<T> *right, BTnode<T> *parent);

	// Desc: Prints the key of the node.
	template <class K>
	friend ostream &operator << (ostream &os, const BTnode<K>* BTnodeptr);
}; // BTnode

// Desc: Default constructor
template <class T>
BTnode<T>::BTnode() {
	depth = 0;
	left = NULL;
	right = NULL;
	parent = NULL;
} // Default constructor

// Desc: Non-default constructor
template <class T>
BTnode<T>::BTnode(const T &key) {
	depth = 0;
	this -> key = key;
	left = NULL;
	right = NULL;
	parent = NULL;
} // Non-default constructor

// Desc: Non-default constructor
template <class T>
BTnode<T>::BTnode(const T &key, BTnode<T> *left, BTnode<T> *right, BTnode<T> *parent) {
	depth = 0;
	this -> key = key;
	this -> left = left;
	this -> right = right;
	this -> parent = parent;
} // Non-default constructor

// Desc: Prints the key of the node.
template <class K>
ostream &operator << (ostream &os, const BTnode<K> &node) {
	os << node.key;
	return os;
} // operator <<

// End of BTnode.h

