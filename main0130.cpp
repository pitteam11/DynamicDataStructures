#include <iostream>

using namespace std;

class Base {
public:
	int x;
	void show() {
		cout << "Show from base " << x << endl;
	}
};

class Child : public Base {
public:
	double y;
	void show1() {
		cout << "Show from child " << x << " "
			<< y << endl;
		show();
	}
};

void test_standart_type() {
	double x{ 13.5 };
	int y = x;
	std::cout << x << " " << y << endl;

	double* pX = &x;
	std::cout << *pX << endl;

	int* pY = (int*)&x; // не безопасно приводить т.к. работаем с указателями на память
	std::cout << *pY << endl; 
}

void test_users_class() {
	Base base;
	Child chaid;

	base.x = 11;
	chaid.x = 12;
	chaid.y = 13.5;

	base.show();

	chaid.show();
	cout << endl;
	chaid.show1();

	base = chaid;
	cout << "After base = chaid: ";
	base.show();

	//Child gg = base; // base - "не помнит" о том, что был child
}

void test_class_pointer() {
	Base* pBase = new Base();
	Child* pChild = new Child();

	pBase->x = 777;
	pBase->show();

	pChild->x = 888;
	pChild->y = 999;
	pChild->show1();

	Base* pBase2 = pChild;
	cout << "pBase2: ";
	pBase2->show();

	Child* pChild2 = (Child*)pBase;
	cout << "pChild2: ";
	pChild2->show1();

	delete pBase;
	delete pChild;
}


class Animal {
public:
	virtual void say() {
		cout << "AAA";
	};

	//virtual ~Animal() = 0;
};


/*virtual*/ /*void Animal::say() { // тут virtual не пишут
	cout << "AAAA\n";
}
*/

class Dog : public Animal {
public:
	void say() override {
		cout << "Gav Gav\n";
	}
};

class Cat : public Dog {
public:
	void say() override {
		cout << "Myau Myau\n";
	}
};


void do_say(Animal& animal) {
	//animal.say();
}
/*
void do_say(Cat& animal) {
	animal.say();
}

void do_say(Dog& animal) {
	animal.say();
}
*/

void main() {
	Animal** animals = new Animal*[] { new Cat(), new Dog(), new Dog() };
	
	Animal ani;


	//Cat* cats[2]{ new Dog(), new Cat() }; // так нельзя	
	for(int k =0; k < 3; ++k)
		animals[k]->say();


	Dog cat;
	do_say(cat);

	for (int k = 0; k < 3; k++)
		delete animals[k];
	delete[] animals;
}