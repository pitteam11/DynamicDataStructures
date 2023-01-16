#pragma once
#include <iostream>

template <typename T>
class MyQueue
{
protected:
	int maxcounter;
	int counter = 0;
	T *queue = nullptr;

public:
	explicit MyQueue(int maxcounter) :
		maxcounter{maxcounter} {
		queue = new T[maxcounter];
	}

	void push(T& val) {
		if (counter < maxcounter)
			queue[counter++] = val;
		else
			std::cout << "Error! Queue overflow\n";
	}

	void push(T&& val) {
		if (counter < maxcounter)
			queue[counter++] = val;
		else
			std::cout << "Error! Queue overflow\n";
	}

	T& top() const {
		if (counter)
			return queue[0];
	}
	
	void pop() {
		if (counter) {
			for (int k = 0; k < counter - 1; ++k)
				std::swap(queue[k], queue[k + 1]);
			--counter;
		}
	}

	bool isEmpty() const {
		return !counter;
	}
};

