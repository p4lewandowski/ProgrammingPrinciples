#include "pch.h"
#include "test.h"


using namespace std;

void printo() {
	cout << "Hello";
}

void print(vector<double> v) // pass-by-value ; appropriate ?
{
	cout << "{ ";
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i != v.size()-1) cout << ", ";
	}
	cout << " }\n";
}

void printoo::print(vector<double> v)
{
	cout << "{ ";
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i != v.size() - 1) cout << ", ";
	}
	cout << " }\n";
}