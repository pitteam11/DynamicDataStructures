#include "MyTime.h"

ostream& operator<<(ostream& out, const MyTime& t) {
	if (t.h < 10)
		out << '0' << t.h;
	else
		out << t.h;
	out << ":";
	if (t.m < 10)
		out << '0' << t.m;
	else
		out << t.m;
	out << ":";
	if (t.s < 10)
		out << '0' << t.s;
	else
		out << t.s;
	return out;
}