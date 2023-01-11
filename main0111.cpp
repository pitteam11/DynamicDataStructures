#include <iostream>
#include "MyTime.h"
#include <vector>
#include "MyStack.h"

using namespace std;

template <typename T>
T getAverage(int size, T* arr) {
	T res = 0;
	for (int k = 0; k < size; ++k)
		res += arr[k];
	return res / size;
}


template <typename T>
class MyArray {
	int size;
	T* arr;

public:
	MyArray() {
		size = 0;
		arr = new T[size];
	}

	~MyArray() {
		size = 0;
		delete[] arr;
	}

	MyArray& add(const T val) {
		T* buff = new T[size + 1];
		for (int k = 0; k < size; ++k)
			buff[k] = arr[k];
		buff[size] = val;
		delete[] arr;
		++size;
		arr = buff;
		return *this;
	}

	void show() {
		for (int k = 0; k < size; ++k)
			cout << arr[k] << " ";
		cout << endl;
	}

	T operator[](const int id) const{
		if (0 <= id < size)
			return arr[id];
		return 0;
	}

	template <typename T2>
	friend ostream& operator<<(ostream& out, const MyArray<T2>& myarr);
};

template <typename T2>
ostream& operator<<(ostream& out, const MyArray<T2>& myarr) {
	for (int k = 0; k < myarr.size; k++)
		cout << myarr.arr[k] << " ";
	return out;
}


void test_MyTime() {
	MyTime t1;
	t1.set_time(12, 34, 30);
	cout << t1 << endl; // 12:34:30

	cout << MyTime(12, 34, 30) << endl; // 12:34:30

	MyTime t2(13, 35, 42);
	cout << t2 - t1 << " sec" << endl; // 3672 sec
}

void test_template_class() {
	cout << "Hello" << endl;
	int arr[]{ 1,2,3,4 };
	cout << getAverage(4, arr) << endl;

	//MyArray<MyArray<int>> myarr1;
	MyArray<int> arr2;
	arr2.add(5).add(7);
	cout << arr2 << endl;

	MyArray<string> arr3;
	arr3.add("first");
	arr3.add("second");
	arr3.add("seventh");
	cout << arr3 << endl;
	cout << arr3[1] << endl;

	//myarr1.add(arr2);
	//myarr1.add(arr2);

	/*
	vector<double> vect1;
	vect1.push_back(12);
	cout << vect1[0];
	*/
	//myarr1.show();
}

void main() {
}
