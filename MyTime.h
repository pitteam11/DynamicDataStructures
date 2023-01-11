#include <iostream>
using namespace std;
#pragma once
class MyTime{
	int h, m, s;

	int toSecond() const {
		return h * 3600 + 60 * m + s;
	}

public:
	//MyTime() : MyTime(0, 0, 0) {};
	MyTime(int h=0, int m=0, int s=0) {
		set_time(h, m, s);
	}

	void set_time(int h=0, int m=0, int s=0) {
		if(0 <= h < 24)
			this->h = h;
		else {
			this->h = 0;
			cout << "Error! Bad hours" << endl;
		}

		if (0 <= m < 60)
			this->m = m;
		else {
			this->m = 0;
			cout << "Error! Bad minutes" << endl;
		}
		
		if (0 <= s < 60)
			this->s = s;
		else {
			this->s = 0;
			cout << "Error! Bad secondes" << endl;
		}
	}

	int operator-(const MyTime& t) const {
		int res = toSecond() - t.toSecond();
		return (res < 0) ? res + 24 * 3600 : res;
	}

	friend ostream& operator<<(ostream& out, const MyTime& t);
};

