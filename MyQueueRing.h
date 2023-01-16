#pragma once
#include "MyQueue.h"

class MyQueueRing : public MyQueue<int>
{
	int pos = 0;

public:
	MyQueueRing(int maxcounter) : MyQueue<int>(maxcounter) {}
	  void push(int& val) {
		  queue[pos] = val;
		  pos = (pos + 1) % maxcounter;
		  if (counter < maxcounter)
			  counter++;		  
	  }

	  void push(int&& val) {
		  queue[pos] = val;
		  pos = (pos + 1) % maxcounter;
		  if (counter < maxcounter)
			  counter++;
	  }
};

template <typename T>
class MyQueueRing2 {

	int maxcounter;
	int counter = 0;
	T* queue = nullptr;
	int pos = 0;

public:
	explicit MyQueueRing2(int maxcounter) :
		maxcounter{ maxcounter } {
		queue = new T[maxcounter];
	}

	void push(T& val) {
		queue[pos] = val;
		pos = (pos + 1) % maxcounter;
		if (counter < maxcounter)
			counter++;
	}

	void push(T&& val) {
		queue[pos] = val;
		pos = (pos + 1) % maxcounter;
		if (counter < maxcounter)
			counter++;
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
