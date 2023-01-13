#pragma once
#include <iostream>

template <typename T>
class MyStack
{
	int maxcounter = 0;
	int counter = 0;
	T* stack = nullptr;


public:
	explicit MyStack(int maxcounter) 
		: maxcounter{maxcounter} {
		stack = new T[maxcounter];
	}

	~MyStack() {
		if (stack != nullptr)
			delete[] stack;
	}

	void push(T& val) {
		if (counter < maxcounter)
			stack[counter++] = val;
		else
			std::cout << "Error! Stack overflow\n";
	}

	void push(T&& val) {
		if (counter < maxcounter)
			stack[counter++] = val;
		else
			std::cout << "Error! Stack overflow\n";
	}

	void emplace(T& val) {
		push(val);
	}

	bool isEmpty() const {
		return !counter;
	}

	bool isFull() const {
		return (counter == maxcounter);
	}

	int size() const {
		return counter;
	}

	T& top() const {
		if (!isEmpty())
			return stack[counter-1];
	}

	void pop() {
		if (!isEmpty())
			--counter;
	}
};

