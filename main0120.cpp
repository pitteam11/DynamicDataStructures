#include <iostream>
#include<time.h>
#include "BinaryTree.h"

using namespace std;

void test_binary_tree() {
	cout << "start test binarytree" << endl;
	BinaryTree tree;
	/*
	tree.push(7);
	tree.push(12);
	tree.push(12);
	tree.push(13);
	*/
	srand(time(0));
	for (int k = 0; k < 1000; k++)
		tree.push(k);


	tree.show();
	cout << endl;
	cout << "end test binarytree" << endl;
}


void main() {
	test_binary_tree();
}