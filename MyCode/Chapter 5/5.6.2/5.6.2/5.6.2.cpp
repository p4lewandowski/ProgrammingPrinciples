#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dothings(vector<int> v);

int main() {
	
	vector<int> v; // a ve ctor of ints
	for (int x; cin >> x; )
		v.push_back(x); // se t value s
	try
	{
		dothings(v);
	}
	catch (const std::exception&)
	{
		cout << "Something went wrong while using dothings!\n";
	}

	cout << "But still printing!\n";
		
}

int dothings(vector<int> v) {
	try {
		for (int i = 0; i <= v.size(); ++i) // print value s
			cout << "v[" << i << "] == " << v.at(i) << '\n';
	}
	catch (out_of_range) {
		cerr << "Oops! Range error\n";
		throw std::invalid_argument("received negative value");
		//return 1;
	}
	catch (...) { // catch all othe r e xce ptions
		cerr << "Exception: something went wrong\n";
		return 2;
	}
}