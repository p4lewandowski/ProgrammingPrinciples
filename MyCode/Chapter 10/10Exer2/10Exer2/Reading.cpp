#include "Reading.h"

using namespace std;

ifstream& operator>>(ifstream& is, Reading& r) {
	int h;
	double t;
	char c;
	is >> h >> t >> c;
	r = Reading(h, t, c);
	return is;
}

ofstream& operator<<(ofstream& os, const Reading& r) {
	os << r.hour << " " << r.temperature << " " << r.type << endl;
	return os;
}

ostream& operator<<(ostream& os, const vector<Reading> v) {
	for (auto &element : v)
		os << v;
	return os;
}