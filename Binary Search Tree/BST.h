
/*
 * BST.h
 *
 * Class Description: Binary Search Tree (template).
 * Class Invariant: Key in each node must be greater than or equal to any key in the left subtree, 
 *                  and less than any key in the right subtree.
 *                  Both left and right subtree of each node must also be BST.
 *
 *
 */


#pragma once

#include <iostream>
#include <string>
#include "BTnode.h"

using namespace std;

template <class T>
class BST {
private:
	BTnode<T> *root;	// Root of the tree.
	int size;			// Total number of keys in the tree.

	/* Private member functions */

	// Tree operations (Helper functions)

	// Desc: Insert a node with the given key to the tree (Helper function).
	// Post: The node is being inserted to the correct position.
	BTnode<T> *insert(BTnode<T> *tree, const T &key);

	// Desc: Search for a key and return the pointer to the node 
	//       with that key (Helper function).
	// Post: Return NULL if it does not exist.
	BTnode<T> *search(BTnode<T> *tree, const T &target) const;

	// Desc: Delete a node from the tree (Helper function).
	//  Pre: The given node must exist.
	void deleteNode(BTnode<T> *BTnodePtr);

	// Desc: Delete all nodes from the tree (Helper functions).
	// Post: All nodes are deleted. The root pointer is NULL.
	void deleteTree(BTnode<T> *tree);

	// Desc: Make a copy of the given tree (Helper functions).
	// Post: Return the root of the new tree.
	BTnode<T> *copyTree(BTnode<T> *tree) const;

	// Desc: Perform pre-order traversal (Helper functions).
	// Post: The pointers to the nodes are stored in the given array.
	void preorder(BTnode<T> *tree, BTnode<T> **arr, int &idx) const;

	// Desc: Perform in-order traversal (Helper functions).
	// Post: The pointers to the nodes are stored in the given array.
	void inorder(BTnode<T> *tree, BTnode<T> **arr, int &idx) const;

	// Desc: Perform post-order traversal (Helper functions).
	// Post: The pointers to the nodes are stored in the given array.
	void postorder(BTnode<T> *tree, BTnode<T> **arr, int &idx) const;

	// Desc: Prints the content of the tree (Helper function).
	void display(BTnode<T> *tree, bool drawBranch[]) const;


	// Utility functions

	// Desc: Return the height of the tree. Return -1 if tree is empty.
	int maxDepth(BTnode<T> *tree) const;

	// Desc: Return a pointer to the node with the smallest key.
	//       Return NULL if tree is empty.
	BTnode<T> *min(BTnode<T> *tree) const;

	// Desc: Return a pointer to the node with the greatest key.
	//       Return NULL if tree is empty.
	BTnode<T> *max(BTnode<T> *tree) const;

	// Desc: Return a pointer to the predecessor of the given element.
	//       Return NULL if it does not exist.
	BTnode<T> *predecessor(BTnode<T> *BTnodePtr) const;

	// Desc: Return a pointer to the successor of the given element.
	//       Return NULL if it does not exist.
	BTnode<T> *successor(BTnode<T> *BTnodePtr) const;


public:

	BST();					// Default constructor
	BST(const BST &tree);	// Copy constructor
	~BST();					// Destructor


	/* Public interface */

	// Desc: Insert a node with the given key to the tree.
	// Post: The node is being inserted to the correct position.
	void insert(const T &key);

	// Desc: Search for a key and return the pointer to the node 
	//       with that key.
	// Post: Return NULL if it does not exist.
	BTnode<T> *search(const T &target) const;

	// Desc: Delete the node with the given key from the tree.
	//       If there is more than one element with the same key, delete ONE only.
	// Post: Return true if the node is being successfully deleted.
	//       Return false if target does not exist.
	bool deleteNode(const T &target);

	// Desc: Delete ALL nodes with the same key.
	//       Return the number of nodes being deleted.
	int deleteNodes(const T &target);

	// Desc: Return the size of the tree.
	int getSize() const;

	// Desc: Return the height of the tree.
	int getHeight() const;

	// Desc: Return true is the tree is empty.
	bool empty() const;

	// Desc: Traverse the tree and store the sequence of pointers in the given array.
	//  Pre: The given array must be long enough to hold all the pointers.
	//       mode is either 1, 0, or -1;
	//        1: pre-order traversal;
	//        0: in-order traversal;
	//       -1: post-order traversal;
	void traversal(BTnode<T> **arr, int mode) const;

	// Desc: Assignment operator.
	BST& operator = (const BST &rhs);

	// // Desc: "Equal to" operator.
	// // Post: Returns true if the content of two trees are the same.
	// bool operator == (const BST &rhs) const;

	// Desc: Prints the content of the tree.
	template <class K>
	friend ostream& operator << (ostream& os, const BST<K> &Tree);
	
}; // BST



/* Private member functions */


// Tree operations (Helper functions)

// Desc: Insert a node with the given key to the tree (Helper function).
// Post: The node is being inserted to the correct position.
template <class T>
BTnode<T> *BST<T>::insert(BTnode<T> *tree, const T &key) {
	if (tree == NULL) {
		// Create a new node.
		size++;
		return new BTnode<T>(key);
	}
	if (key <= tree -> key) {
		// Insert to left subtree.
		tree -> left = insert(tree -> left, key);
		tree -> left -> parent = tree;
		tree -> left -> depth = tree -> depth + 1;
	} else {
		// Insert to right subtree.
		tree -> right = insert(tree -> right, key);
		tree -> right -> parent = tree;
		tree -> right -> depth = tree -> depth + 1;
	}
	return tree;
} // insert

// Desc: Search for a key and return the pointer to the node 
//       with that key (Helper function).
// Post: Return NULL if it does not exist.
template <class T>
BTnode<T> *BST<T>::search(BTnode<T> *tree, const T &target) const {
	if (tree == NULL)	// Empty tree.
		return NULL;
	if (tree -> key == target) {
		// Target found.
		return tree;
	} else if (target < tree -> key) {
		// Search left subtree.
		return search(tree -> left, target);
	} else {
		// Search right subtree.
		return search(tree -> right, target);
	}
} // search

// Desc: Delete a node from the tree (Helper function).
//  Pre: The given node must exist.
template <class T>
void BST<T>::deleteNode(BTnode<T> *BTnodePtr) {
	if (BTnodePtr -> left == NULL && BTnodePtr -> right == NULL) {
		// No children.
		// There is only one node in the tree.
		if (BTnodePtr -> parent == NULL) {
			root = NULL;
		} else if (BTnodePtr -> parent -> left == BTnodePtr) {
			BTnodePtr -> parent -> left = NULL;
		} else {
			BTnodePtr -> parent -> right = NULL;
		}
		delete BTnodePtr;
		size--;
	} else if (BTnodePtr -> left != NULL && BTnodePtr -> right == NULL) {
		// One child: left child.
		BTnode<T> *pre = predecessor(BTnodePtr);
		BTnodePtr -> key = pre -> key;
		deleteNode(pre);
	} else if (BTnodePtr -> left == NULL && BTnodePtr -> right != NULL) {
		// One child: right child.
		BTnode<T> *succ = successor(BTnodePtr);
		BTnodePtr -> key = succ -> key;
		deleteNode(succ);
	} else {
		// Two children.
		BTnode<T> *pre, *succ;
		pre = predecessor(BTnodePtr);
		if (pre != NULL) {
			// Replace it with predecessor first. 
			BTnodePtr -> key = pre -> key;
			deleteNode(pre);
		} else {
			// Replace it with successor if predecessor does not exist.
			succ = successor(BTnodePtr);
			BTnodePtr -> key = succ -> key;
			deleteNode(succ);
		}
	}
} // deleteNode

// Desc: Delete all nodes from the tree (Helper functions).
// Post: All nodes are deleted. The root pointer is NULL.
template <class T>
void BST<T>::deleteTree(BTnode<T> *tree) {
	if (tree == NULL)
		return;
	if (tree -> left != NULL)
		deleteTree(tree -> left);
	if (tree -> right != NULL)
		deleteTree(tree -> right);
	delete tree;
	tree = NULL;
	size = 0;
} // deleteTree

// Desc: Make a copy of the given tree (Helper functions).
// Post: Return the root of the new tree.
template <class T>
BTnode<T> *BST<T>::copyTree(BTnode<T> *tree) const {
	if (tree == NULL)
		return NULL;

	BTnode<T> *newNode = new BTnode<T>;
	*newNode = *tree;
	newNode -> parent = NULL;

	BTnode<T> *leftSubtree = copyTree(tree -> left);
	newNode -> left = leftSubtree;
	if (leftSubtree != NULL)
		leftSubtree -> parent = newNode;

	BTnode<T> *rightSubtree = copyTree(tree -> right);
	newNode -> right = rightSubtree;
	if (rightSubtree != NULL)
		rightSubtree -> parent = newNode;

	return newNode;
} // copyTree

// Desc: Perform pre-order traversal (Helper functions).
// Post: The pointers to the nodes are stored in the given array.
template <class T>
void BST<T>::preorder(BTnode<T> *tree, BTnode<T> **arr, int &idx) const {
	if (tree == NULL)
		return;
	arr[idx++] = tree;
	preorder(tree -> left, arr, idx);
	preorder(tree -> right, arr, idx);
} // preorder

// Desc: Perform in-order traversal (Helper functions).
// Post: The pointers to the nodes are stored in the given array.
template <class T>
void BST<T>::inorder(BTnode<T> *tree, BTnode<T> **arr, int &idx) const {
	if (tree == NULL)
		return;
	inorder(tree -> left, arr, idx);
	arr[idx++] = tree;
	inorder(tree -> right, arr, idx);
} // inorder

// Desc: Perform post-order traversal (Helper functions).
// Post: The pointers to the nodes are stored in the given array.
template <class T>
void BST<T>::postorder(BTnode<T> *tree, BTnode<T> **arr, int &idx) const {
	if (tree == NULL)
		return;
	postorder(tree -> left, arr, idx);
	postorder(tree -> right, arr, idx);
	arr[idx++] = tree;
} // postorder

// Desc: Prints the content of the tree (Helper function).
template<class T>
void BST<T>::display(BTnode<T> *tree, bool drawBranch[]) const {
	if (tree == NULL) {		// NULL internel vertex.
		cout << "NULL" << endl;
		return;
	} else {
		cout << tree -> key << endl;
	}

	if (tree -> left == NULL && tree -> right == NULL)	// Leaf
		return;

	// Set the "drawBranch" of previous level to false if current node
	// is the left child of its parent. Otherwise, set it to true.
	int level = tree -> depth;
	if (level > 0 && tree -> parent -> right == tree)
		drawBranch[level - 1] = true;
	else if (level > 0 && tree -> parent -> left == tree)
		drawBranch[level - 1] = false;

	string branch1 = "|   ", branch2 = "|---", spaces = "    ";
	unsigned count = 0;

	// Draw right subtree.
	while (count++ < tree -> depth) {	// Draw branches.
		if (drawBranch[count - 1])
			cout << branch1;
		else
			cout << spaces;
	}
	cout << branch2;
	display(tree -> right, drawBranch);

	// Draw left subtree.
	count = 0;
	while (count++ < tree -> depth) {	// Draw branches.
		if (drawBranch[count - 1])
			cout << branch1;
		else
			cout << spaces;
	}
	cout << branch2;
	display(tree -> left, drawBranch);

	// Draw gaps between siblings.
	if (level > 0 && tree -> parent -> right == tree) {
		for (int i = 0; i < level - 1; i++) {
			if (drawBranch[i])
				cout << branch1;
			else
				cout << spaces;
		}
		cout << branch1 << endl;
	}
} // display


// Utility functions

// Desc: Return the height of the tree. Return -1 if tree is empty.
template <class T>
int BST<T>::maxDepth(BTnode<T> *tree) const {
	if (tree == NULL)
		return -1;
	int leftHeight = maxDepth(tree -> left);
	int rightHeight = maxDepth(tree -> right);
	return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
} // maxDepth

// Desc: Return a pointer to the node with the smallest key.
//       Return NULL if tree is empty.
template <class T>
BTnode<T> *BST<T>::min(BTnode<T> *tree) const {
	if (tree == NULL)
		return NULL;
	return (tree -> left == NULL) ? tree : min(tree -> left);
} // min

// Desc: Return a pointer to the node with the greatest key.
//       Return NULL if tree is empty.
template <class T>
BTnode<T> *BST<T>::max(BTnode<T> *tree) const {
	if (tree == NULL)
		return NULL;
	return (tree -> right == NULL) ? tree : max(tree -> right);
} // max

// Desc: Return a pointer to the predecessor of the given element.
//       Return NULL if it does not exist.
template <class T>
BTnode<T> *BST<T>::predecessor(BTnode<T> *BTnodePtr) const {
	if (BTnodePtr -> left != NULL)
		return max(BTnodePtr -> left);
	for (; BTnodePtr -> parent; BTnodePtr = BTnodePtr -> parent)
		if (BTnodePtr -> parent -> right == BTnodePtr)
			return BTnodePtr -> parent;
	return NULL;
} // predecessor

// Desc: Return a pointer to the successor of the given element.
//       Return NULL if it does not exist.
template <class T>
BTnode<T> *BST<T>::successor(BTnode<T> *BTnodePtr) const {
	if (BTnodePtr -> right != NULL)
		return min(BTnodePtr -> right);
	for (; BTnodePtr -> parent; BTnodePtr = BTnodePtr -> parent)
		if (BTnodePtr -> parent -> left == BTnodePtr)
			return BTnodePtr -> parent;
	return NULL;
} // successor



/* Public interface */


// Desc: Default constructor
template <class T>
BST<T>::BST() {
	root = NULL;
	size = 0;
} // Default constructor

// Desc: Copy constructor
template <class T>
BST<T>::BST(const BST<T> &tree) {
	root = copyTree(tree.root);
	size = tree.size;
} // Copy constructor

// Desc: Destructor
template <class T>
BST<T>::~BST() {
	deleteTree(root);
} // Destructor

// Desc: Insert a node with the given key to the tree.
// Post: The node is being inserted to the correct position.
template <class T>
void BST<T>::insert(const T &key) {
	root = insert(root, key);
} // insert

// Desc: Search for a key and return the pointer to the node 
//       with that key.
// Post: Return NULL if it does not exist.
template <class T>
BTnode<T> *BST<T>::search(const T &target) const {
	return search(root, target);
} // search

// Desc: Delete the node with the given key from the tree.
//       If there is more than one element with the same key, delete ONE only.
// Post: Return true if the node is being successfully deleted.
//       Return false if target does not exist.
template <class T>
bool BST<T>::deleteNode(const T &target) {
	BTnode<T> *BTnodePtr = search(root, target);
	if (BTnodePtr != NULL) {
		deleteNode(BTnodePtr);
		return true;
	} else {
		return false;
	}
} // deleteNode

// Desc: Delete ALL nodes with the same key.
//       Return the number of nodes being deleted.
template <class T>
int BST<T>::deleteNodes(const T &target) {
	int count = 0;
	BTnode<T> *BTnodePtr = search(root, target);
	while (BTnodePtr != NULL) {
		deleteNode(BTnodePtr);
		count++;
		BTnodePtr = search(root, target);
	}
	return count;
} // deleteNodes

// Desc: Return the size of the tree.
template <class T>
int BST<T>::getSize() const {
	return size;
} // size

// Desc: Return the height of the tree.
template <class T>
int BST<T>::getHeight() const {
	return maxDepth(root);
} // getHeight

// Desc: Return true is the tree is empty.
template <class T>
bool BST<T>::empty() const {
	return (size == 0);
} // empty

// Desc: Traverse the tree and store the sequence of pointers in the given array.
//  Pre: The given array must be long enough to hold all the pointers.
//       mode is either 1, 0, or -1;
//        1: pre-order traversal;
//        0: in-order traversal;
//       -1: post-order traversal;
template <class T>
void BST<T>::traversal(BTnode<T> **arr, int mode) const {
	int idx = 0;
	switch (mode) {
	case 1:		// Pre-order traversal
		preorder(root, arr, idx);
		break;
	case 0:		// In-order traversal
		inorder(root, arr, idx);
		break;
	case -1:	// Post-order traversal
		postorder(root, arr, idx);
		break;
	}
} // traversal

// Desc: Assignment operator.
template <class T>
BST<T>& BST<T>::operator = (const BST<T> &rhs) {
	if (this != &rhs) {
		if (size != 0)
			deleteTree(root);
		root = copyTree(rhs.root);
		size = rhs.size;
	}
	return *this;
} // operator =

template <class K>
ostream& operator << (ostream& os, const BST<K> &Tree) {
	int height = Tree.getHeight();
	if (height < 0) {	// Empty tree
		os << "NULL" << endl;
	} else if (height == 0) {	// One node only.
		os << Tree.root -> key << endl;
		os << "|---NULL" << endl;
		os << "|---NULL" << endl;
	} else {
		bool *drawBranch = new bool[height];
		Tree.display(Tree.root, drawBranch);
		delete [] drawBranch;
	}
	return os;
} // operator <<

// End of BST.h

