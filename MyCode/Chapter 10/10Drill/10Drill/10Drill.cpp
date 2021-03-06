#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Point {
	int x, y;
	Point() :x{ 0 }, y{ 0 } {}
	Point(int xx, int yy) :x(xx), y(yy) {}
};

ifstream& operator>>(ifstream& is, Point& p) {
	is.exceptions(is.exceptions() | ios_base::badbit);
	int x, y;
	string s1, s2;

	is >> s1 >> x >> s2 >> y;
	if (!is || s1 != "X:" || s2 != "Y:")
	{
		is.clear(ios_base::failbit);
		return is;
	}
	p = Point(x, y);

	return is;
}

istream& operator>>(istream& is, Point& p) {
	is.exceptions(is.exceptions() | ios_base::badbit);
	int x, y;
	char c1, c2, c3;

	is >> c1 >> x >> c2 >> y >> c3;
	if (!is || c1 !='(' || c2 !=',' || c3 !=')')
	{
		is.clear(ios_base::failbit);
		return is;
	}
	p = Point(x, y);
	
	return is;
}

istream& operator>>(istream& is, vector<Point>& v) {
	for (auto &element : v) {
		is >> element;
		if(!is) throw exception("Wrong format!");
	}
	return is;
}

ostream& operator<<(ostream& os, const Point& p) {
	os << "X: " << p.x << " Y: " << p.y << endl;
	return os;
}

ostream& operator<<(ostream& os, const vector<Point>& v) {
	for (auto &element : v) {
		os << element;
	}
	return os;
}

void save2file(const vector<Point>& v) {
	string fname;
	cout << "Please enter filename:\n";
	if (cin >> fname && !cin) throw exception("Couldnt read filename!");

	ofstream ost{ fname };
	if (!ost) throw exception("Can't open output file!");

	ost << v;
}

ifstream& operator>>(ifstream& is, vector<Point>& v) {
	for (auto &element : v) {
		is >> element;
		if (!is) throw exception("Wrong format!");
	}
	return is;
}

void loadfromfile(vector<Point>& v) {
	string fname;
	cout << "Please enter filename:\n";
	if (cin >> fname && !cin) throw exception("Couldnt read filename!");

	ifstream ist{ fname };
	if(!ist) throw exception("Couldnt open input file!");
	ist >> v;
}

bool operator==(const Point& p1, const Point& p2) {
	return (p1.x == p2.x && p1.y == p2.y);
}

bool operator==(const vector<Point>& v1, const vector<Point>& v2) {
	return equal(v1.begin(), v1.begin(), v2.begin());
}


int main()
{
	try
	{
		unsigned int n = 3;
		vector<Point> original_points(n);
		string fname;
		cout << "Please enter 3 pairs of coordinates separeted with comma:\n";
		cin >> original_points;
		save2file(original_points);

		vector<Point> processed_points(n);
		loadfromfile(processed_points);

		cout << original_points;
		cout << processed_points;
		if (original_points == processed_points)
			cout << "Copy successful!";
		else
			cout << "Something's wrong!";
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}

}