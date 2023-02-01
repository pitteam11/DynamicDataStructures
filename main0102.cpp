#include <iostream>
#include "Figure.h"

using namespace std;

class ISayable {
public:
	virtual void say() = 0;
};

class IMoveable {
public:
	virtual void move() = 0;
};

class Animal : public IMoveable, public ISayable {
public:
	int x = 0;
	int y = 0;

	int* legs;

	void showPos() {
		cout << "A am at " << x << ", " << y << "\n";
	}

	virtual ~Animal() {
		cout << "Animals destructor\n";
		delete[] legs;
	}
};

class Pig : public Animal {
public:
	Pig() {
		legs = new int[4];
	}

	void say() override {
		cout << "Hry - Hry \n";
	}

	void move() override {
		x += 1;
		y += 1;
	}
};

class Cow : public Animal {
public:

	int* medals;

	Cow() {
		legs = new int[4];
		medals = new int[7];
	}

	void say() override {
		cout << "Muu - Muu \n";
	}

	void move() override {
		x += 2;
		y += 0;
	}

	~Cow() {
		delete[] medals;
	}
};

class Base abstract {
public:
	virtual void fun1() = 0; /* {
		cout << "I am Base\n";
	}*/
	virtual void show() {
		cout << "I am\n";
	}
};











void touch(Animal& animal) {
	animal.say();
	animal.move();
	animal.showPos();
}


class Child : public Base {
public:
	void fun1() {
		cout << "I am child\n";
	}
};

void test() {
	cout << "Test vitruals \n";
	Base* pObj = new Child();
	pObj->fun1();
	delete pObj;
}

void test_animals() {
	Animal* pFarm[]{ new Cow, new Pig };

	//Animal* animals = new Animal;

	for (int k = 0; k < 2; k++)
		touch(*(pFarm[k]));

	for (int k = 0; k < 2; k++)
		delete pFarm[k];
}

void main() {
	Figure* pFig = new Triangle(1, 1, 10); /*Figure();*/
	
	cout << "Area: " << pFig->area() << endl;

	delete pFig;
}