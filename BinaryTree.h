#pragma once
#include <iostream>

using namespace std;

struct Node {
	int id;
	Node* l = nullptr;    
	Node* r = nullptr;
	Node* p = nullptr;
};

class BinaryTree {
	Node* root = nullptr;
	int size = 0;

public:
	void push(int&& val) {
		Node* node = new Node{ val };
		if (size == 0) {
			root = node;
			size++;
		} else {
			Node* buff = root;
			while (1) {
				if (node->id > buff->id) {
					if (buff->r != nullptr)
						buff = buff->r;						
					else {
						node->p = buff;
						buff->r = node;
						size++;
						break;
					}
				}
				else if (node->id < buff->id) {
					if (buff->l != nullptr)
						buff = buff->l;
					else {
						node->p = buff;
						buff->l = node;
						size++;
						break;
					}
				}
				else {
					break; // 
				}
			}
		}
	}

	void push(int& val) {
		Node* node = new Node{ val };
		if (size == 0) {
			root = node;
			size++;
		}
		else {
			Node* buff = root;
			while (1) {
				if (node->id > buff->id) {
					if (buff->r != nullptr)
						buff = buff->r;
					else {
						node->p = buff;
						buff->r = node;
						size++;
						break;
					}
				}
				else if (node->id < buff->id) {
					if (buff->l != nullptr)
						buff = buff->l;
					else {
						node->p = buff;
						buff->l = node;
						size++;
						break;
					}
				}				
			}
		}
	}


	void show(Node* node = nullptr) {
		if (node == nullptr) {
			node = root;
			cout << "size: " << size << " | ";
		}
		cout << node->id << " ";
		if(node->l != nullptr)
			show(node->l);
		if (node->r != nullptr)
			show(node->r);
	}

	Node* find(int id) {
		if (size == 0)
			return nullptr;
		Node* node = root;
		while (1) {
			if (id == node->id)
				return node;
			if (id > node->id) {
				if (node->r != nullptr)
					node = node->r;
				else {
					return nullptr;
				}
			}
			else {
				if (node->l != nullptr)
					node = node->l;
				else {
					return nullptr;
				}
			}
		}
	}

	void remove(int id) {
		Node* node = find(id);
		if (node == nullptr)
			return;
		if (size == 1) {
			delete node;
			root = nullptr;
			size--;
			return;
		}			
		if (node->l == nullptr && node->r == nullptr) {
			if (node->p->l == node) 
				node->p->l = nullptr;
			else 
				node->p->r = nullptr;
			delete node;
			size--;
			return;
		}		
		if (node->l == nullptr) {
			if (node->p->l == node) {
				node->p->l = node->r;
				node->r->p = node->p->l;
				delete node;
				size--;
				return;
			}			
			if (node->p->r == node) {
				node->p->r = node->r;
				node->r->p = node->p->r;
				delete node;
				size--;
				return;
			}			
		}
		if (node->r == nullptr) {
			if (node->p->l == node) {
				node->p->l = node->l;
				node->l->p = node->p->l;
				delete node;
				size--;
				return;
			}
			if (node->p->r == node) {
				node->p->r = node->l;
				node->l->p = node->p->r;
				delete node;
				size--;
				return;
			}
		}
		Node* iter = node->r;
		while (iter->l != nullptr)
			iter = iter->l;
		if (node != root) {			
			if (node->p->l == node) {
				node->p->l = iter;
				//iter->l = node->l;
				iter->r = node->r;
				delete node;
				size--;
				return;
			}
			else {
				node->p->r = iter;
				iter->l = node->l;
				node->r->l = nullptr; // костыль для конкретного случая
				iter->r = node->r;
				delete node;
				size--;
				return;
			}
		} 
		if (iter->p->r == iter)
			iter->p->r = nullptr;
		else
			iter->p->l = nullptr;
		iter->l = root->l;
		Node* iter2 = iter;
		while (iter2->r != nullptr)
			iter2 = iter2->r;
		iter2->r = root->r;
		root = iter;
		delete node;
		size--;
	}
};
