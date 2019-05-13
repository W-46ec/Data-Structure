
/*
 * main.cpp
 *
 * Description: main file.
 *
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "BST.h"

using namespace std;

int main() {

	srand(time(NULL));

	int n = 8;
	int *A = new int[n];

	for (int i = 0; i < n; i++)
		A[i] = rand() % n + 1;


	BST<int> Tree0;
	cout << "Tree0.empty(): " << Tree0.empty() << endl;

	// Insertion test
	cout << "\nInsertion test..." << endl;
	for (int i = 0; i < n; i++) {
		Tree0.insert(A[i]);
		// Tree0.insert(i);
	}
	cout << "Inserted " << n << " elements." << endl;
	cout << "Tree0.Size: " << Tree0.getSize() << endl;
	cout << "Tree0.Height: " << Tree0.getHeight() << endl;
	cout << "Tree0: " << endl << Tree0 << endl;

	// Copy constructor test
	cout << "\nCopy constructor test..." << endl;
	BST<int> Tree1 = Tree0;
	cout << "Tree1.Size: " << Tree1.getSize() << endl;
	cout << "Tree1.Height: " << Tree1.getHeight() << endl;
	cout << "Tree1: " << endl << Tree1 << endl;

	// Search test
	cout << "\nSearch test..." << endl;
	cout << "Search from " << n - 1 << " to 0: ";
	for (int i = n - 1; i >= 0; i--) {
		BTnode<int> *ptr = Tree1.search(i);
		if (ptr)
			cout << (*ptr) << " ";
	}
	cout << "are found." << endl;

	// Deletion test
	cout << "\nDeletion test..." << endl;
	cout << "Press Ctrl + D/Z to quit the test." << endl;
	int target;
	cout << "Tree1: " << endl << Tree1 << endl;
	cout << "Enter the key of the node to be deleted: ";
	while (!Tree1.empty() && cin >> target) {
		// cout << "delete " << target << ": " << Tree1.deleteNode(target) << endl;
		cout << Tree1.deleteNodes(target) << " of " << target << "'s are deleted." << endl;
		cout << Tree1 << endl;
		if (!Tree1.empty())
			cout << "Enter the key of the node to be deleted: ";
	}
	cout << endl;


	// Assignment operator test
	cout << "\nAssignment operator test..." << endl;
	BST<int> Tree2;
	Tree2 = Tree0;
	Tree0 = Tree1;
	cout << "Tree0 == Tree1: " << (Tree0 == Tree1) << endl; 
	

	// Traversal
	cout << "\nTraversal test on Tree2..." << endl;
	BTnode<int> **nodePtrArr = new BTnode<int>*[Tree2.getSize()];

	// Pre-order
	Tree2.traversal(nodePtrArr, 1);
	cout << "pre-order:\t";
	for (int i = 0; i < Tree2.getSize(); i++) {
		cout << *(nodePtrArr[i]) << " ";
	}
	cout << endl;

	// In-order
	Tree2.traversal(nodePtrArr, 0);
	cout << "in-order:\t";
	for (int i = 0; i < Tree2.getSize(); i++) {
		cout << *(nodePtrArr[i]) << " ";
	}
	cout << endl;

	// Post-order
	Tree2.traversal(nodePtrArr, -1);
	cout << "post-order:\t";
	for (int i = 0; i < Tree2.getSize(); i++) {
		cout << *(nodePtrArr[i]) << " ";
	}
	cout << endl;

	// cout << Tree0 << endl;

	delete [] A;
	delete [] nodePtrArr;

	return 0;
} // main

// End of main.cpp

