#include <iostream>
#include "MyLinkedList.h"

using namespace std;

void main() {
	cout << "Test LinkedList" << endl;
	LinkedList<int> list;
	list.pushToHead(7);
	list.pushToHead(8);
	list.pushToHead(9);
	list.pushToTail(10);
	list.pushToTail(11);
	list.show();
	list.removeFromHead();
	list.removeFromTail();
	list.pushToPos(77, 0);
	list.show();
	list.removeFromPos(0);
	list.show();
	list.clear();
}