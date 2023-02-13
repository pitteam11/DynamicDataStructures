#include <iostream>
#include <list>
#include <map>


using namespace std;

int sum(int a, int b) {
	return a + b;
}

int mult(int a, int b) {
	return a * b;
}

void show(int (*op)(int, int), int a, int b) {
	cout << "Function result is " << op(a, b) << endl;
}

// Предикаты
bool isPositive(int x) {
	return x >= 0;
}

bool isEven(int x) {
	return x % 2 == 0;
}

bool isAll(int x) {
	return true;
}

bool isNot_m5_m3(int x) {
	return (x != -3) && (x != -5);
}

void showArr(int arr[], int sz,
	bool (*condition)(int)) {
	for (int k = 0; k < sz; k++) {
		if (condition(arr[k])) {
			cout << arr[k] << " ";
		}
	}
	cout << endl;
}

void test_func_pointers() {
	char ch = '*';
	int (*op)(int, int) = sum;

	switch (ch) {
	case '+': op = sum; break;
	case '*': op = mult; break;
	}
	show(op, 3, 4);
}

void test_lambda() {
	int arr[]{ 1,2,-3,4,-5,-6,-7,8,-9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	showArr(arr, sz, isPositive);
	showArr(arr, sz, isEven);
	showArr(arr, sz, isAll);
	showArr(arr, sz, isNot_m5_m3); // 1,2,4,-6,-7,8,-9 
	showArr(arr, sz, [](int x) {return x % 2 != 0; });

	bool (*lambda)(int) = [](int x) {return x % 2 != 0; };
	cout << lambda(9) << endl;
}

void test_map() {
	map<string, string> my_map;
	my_map["one"] = "raz";
	my_map["two"] = "dva";
	my_map["three"] = "tree";

	map<string, string>::iterator it_map = my_map.begin();
	while (it_map != my_map.end()) {
		cout << (*it_map).first <<
			" " << (*it_map).second << endl;
		it_map++;
	}
}

void show_list(list<int> my_list) {
	cout << "My list: ";
	list<int>::iterator it = my_list.begin();
	while (it != my_list.end()) {
		cout << *(it++) << " ";
	}
	cout << endl;
}

int comp(int a, int b) {
	return a > b;
}

void test_sort() {
	list<int> my_list{ 3,5,6,2,1,5,9,5 };
	show_list(my_list);
	my_list.sort();
	show_list(my_list);
	my_list.sort(std::greater<int>());
	show_list(my_list);
	my_list.sort([](int a, int b) {return a < b; });
	show_list(my_list);
	my_list.sort(comp);
	show_list(my_list);
}

class Town {
public:
	string region;
	string name;
	double population;
	friend ostream& operator<<(ostream& out, const Town& town);
};

ostream& operator<<(ostream& out, const Town& town) {
	out << town.region << " " << town.name 
		<< " " << town.population << endl;
	return out;
}

void show_list(list<Town> my_list) {
	//cout << "My list: ";
	list<Town>::iterator it = my_list.begin();
	while (it != my_list.end()) {
		cout << *(it++);
	}
	cout << endl;
}

bool compare_by_population(Town a, Town b) {
	if (a.region == b.region)
	{
		return a.population > b.population;
	}
	else
	{
		return a.region < b.region;
	}
}

void main() {
	list<Town> towns;
	towns.push_back(Town{ "RostovReg", "Rostov", 2.0e6 });
	towns.push_back(Town{ "RostovReg", "Azov", 82.0e3 });
	towns.push_back(Town{ "RostovReg", "Taganrog", 0.2e6 });

	towns.push_back(Town{ "MoscowReg", "Moscow",  20.0e6 });
	towns.push_back(Town{ "MoscowReg", "Korolev", 183.0e3 });
	towns.push_back(Town{ "MoscowReg", "Podolsk", 187.0e3 });

	show_list(towns);
	towns.sort([](Town a, Town b) {
		if (a.region == b.region)
		{
			return a.name < b.name;
		}
		else
		{
			return a.region < b.region;
		}
		});
	show_list(towns);
	
	towns.sort(compare_by_population);
	cout << endl;
	show_list(towns);



}