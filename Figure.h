#pragma once
#include <iostream>
using namespace std;

class Exception {
public:
	virtual string getMessage() = 0;
};

class Exception_BadTriangle : public Exception {
public:
	string getMessage() override {
		return "Bad triangle";
	}
};



class Figure {
public:
	int x;
	int y;
	virtual ~Figure() = 0 {};
	virtual double area() = 0;

};
/*
Figure::~Figure() {

}
*/
class Square : public Figure {
public:
	int width;

	Square(int width) : width{width} {}

	double area() override {
		return width * width;
	}
};

class Rectangle :public Square {
public:
	int height;
	Rectangle(int width, int height) : 
		Square(width), height{ height }{}

	double area() override {
		return width * height;
	}
};

class Trapec : public Rectangle {
public:
	int top;
	Trapec(int w, int t, int h) 
		: Rectangle(w, h), top{ t }{};
	double area() override {
		return 0.5 * (top + width) * height;
	}
};

class Triangle : public Figure {
	double p;
public:
	int a; 
	int b;
	int c;

	Triangle(int a, int b, int c) 
		: a{ a }, b{ b }, c{ c } {
		if (a + b > c || a + c > b || b + c > a)
			throw Exception_BadTriangle();
		p = (a + b + c) * 0.5;	
	}

	double area() override {
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

};


