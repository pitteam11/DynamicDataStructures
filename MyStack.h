#pragma once
#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
};

class MyStack{
	Node* head = nullptr;
	int size = 0;

public:
	MyStack() {};

	void push_back(int val) {
		Node node;
		node.val = val;
		Node* currnode = head;
		while (currnode->next != nullptr)
			currnode = currnode->next;
		currnode->next = &node;
	}
};

