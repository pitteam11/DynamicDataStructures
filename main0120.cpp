#include <iostream>
#include<time.h>
#include "BinaryTree.h"

using namespace std;

void test_binary_tree() {
	cout << "start test binarytree" << endl;
	BinaryTree tree;
	
	tree.push(3);
	tree.push(7);
	tree.push(2);
	tree.push(9);
	tree.push(8);
	tree.push(5);
	tree.push(6);
	tree.push(4);
	tree.push(11);

	Node* node = tree.find(8);
	if (node != nullptr) {
		if (node->p != nullptr)
			cout << "pearent: " << node->p->id << endl;
		cout << "current: " << node->id << endl;
		if (node->r != nullptr)
			cout << "right: " << node->r->id << endl;
		if (node->l != nullptr)
			cout << "left: " << node->l->id << endl;
	}

	if (tree.find(1) != nullptr) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	tree.show();
	cout << endl;
	tree.remove(3);

	tree.show();
	cout << endl;

	/*
srand(time(0));
for (int k = 0; k < 1000; k++)
	tree.push(k);
	*/


	cout << "end test binarytree" << endl;
}


void main() {
	test_binary_tree();
}