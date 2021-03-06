#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct res {
	string first;
	string last;
};

vector<int> find_len(const vector<string>& vs) {
	vector<int> vi;

	for (string i : vs)
		vi.push_back(i.length());

	return vi;
}

struct res find_lexi(vector<string> vs) {
	sort(vs.begin(), vs.end());
	res r;
	r.first = vs[0];
	r.last = vs[vs.size() - 1];

	return r;
}

int main()
{
	vector<string> vs = {"one", "two", "three", "four", "fiveee"};

	vector<int> vi = find_len(vs);

	for (int i : vi)
		cout << i << ' ';
	cout << endl;

	res r = find_lexi(vs);

	cout << "first:" << r.first << endl << "last:" << r.last << endl;
}
