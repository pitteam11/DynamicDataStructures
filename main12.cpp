#include <iostream>


using namespace std;

class Exception {
public:
	virtual string getMessage()=0;
};

class Exception_DivisionByZero : public Exception{
public:
	string getMessage() override {
		return "Divison by zero";
	}
};

class Exception_FileNotOpened : public Exception {
public:
	string getMessage() override {
		return "File not opened";
	}
};

class Exception_SqrtFromNegative : public Exception {
public:
	string getMessage() override {
		return "Sqrt from negative";
	}
};

void fun1() {
	throw Exception_FileNotOpened();
}

void test_exception() {
	int a = -13;
	int b = 0;
	try {
		if (b == 0)
			throw Exception_DivisionByZero();
		cout << a << " / " << b << " = " << a / b << endl;
		if (a < 0)
			throw Exception_SqrtFromNegative();
		cout << sqrt(a) << " = " << sqrt(a) << endl;
	}
	catch (Exception& e) {
		cout << e.getMessage() << endl;
	}

	try {
		fun1();
	}
	catch (Exception& e) {
		cout << e.getMessage() << endl;
	}
	/*
	catch (Exception_DivisionByZero e) {
		cout << e.message << endl;
	}
	catch (Exception_SqrtFromNegative e) {
		cout << e.message << endl;
	}
	*/
}

int convert(string s) {
	return 0;
}

namespace Space1 {
	int convert(string s) {
		return atoi(s.data());
	}
}

namespace Space2 {
	int convert(string s) {
		int d = ::convert(s);
		return s.length();		
	}
	int c = 0;
}


void main() {

	cout << convert("12") << endl;
	cout << Space2::convert("12") << endl;

}

