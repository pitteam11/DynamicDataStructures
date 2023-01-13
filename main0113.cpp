#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"

using namespace std;

class Man {
	string name;
	int age;

public:
	Man(string name = "John Do", int age = 99)
		: name{ name }, age{ age }{};
	
	string Name() {
		return name;
	}
	int Age() {
		return age;
	}

};


void test_MyStack() {
	cout << "test myStack" << endl;

	MyStack<int> stack(100); // 100 - maxcounter

	int a = 21;

	stack.push(a);
	stack.push(11);
	stack.push(14);

	while (!stack.isEmpty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl; // 14 11 21


	MyStack<string> stack2(100); // 100 - maxcounter

	stack2.push("Ruslan");
	stack2.push("Dmitrii");
	stack2.push("Alexandr");

	while (!stack2.isEmpty()) {
		cout << stack2.top() << " ";
		stack2.pop();
	}
	cout << endl; // "Alexandr" "Dmitrii" "Ruslan"

	MyStack<Man> stack3(3);
	stack3.push(Man("Igor", 22));
	stack3.push(Man("Ivan", 32));
	stack3.push(Man("Ilya", 42));

	while (!stack3.isEmpty()) {
		cout << stack3.top().Name() << " "
			<< stack3.top().Age() << endl;
		stack3.pop();
	}
	cout << endl;
}


struct Student {
	string name;
	int number;
};

void add(int& sz, Student*& sts, Student st) {
	//int sz = sizeof(sts) / sizeof(sts[0]);
	Student* buff = new Student[sz + 1];
	for (int k = 0; k < sz; k++)
		buff[k] = sts[k];
	buff[sz] = st;
	delete[] sts;
	sts = buff;
	sz++;
}

void show(int sz, Student* sts) {
	//int sz = sizeof(sts) / sizeof(sts[0]);
	for (int k = 0; k < sz; ++k)
		cout << sts[k].name << " " << sts[k].number << endl;
}	

void remove(int &sz, Student*& sts, int id) {
	//int sz = sizeof(sts) / sizeof(sts[0]);
	Student* buff = new Student[sz - 1];
	for (int k = 0; k < id; k++)
		buff[k] = sts[k];
	for (int k = id + 1; k < sz; k++)
		buff[k - 1] = sts[k];
	delete[] sts;
	sts = buff;
	sz--;
}

void main() {
	int sz = 0;
	Student* sts = new Student[sz];
	add(sz, sts, Student{ "Ivan", 1 });
	add(sz, sts, Student{ "Igor", 2 });
	add(sz, sts, Student{ "Ilya", 3 });

	show(sz, sts);
	remove(sz, sts, 0);
	cout << "-------------" << endl;
	show(sz, sts);
	sz = 0;
	delete[] sts;



	/*
	MyQueue<int> line(20);
	line.push(12);
	line.push(14);
	line.push(17);

	while (!line.isEmpty()) {
		cout << line.top() << " ";
		line.pop();
	}
	*/
}