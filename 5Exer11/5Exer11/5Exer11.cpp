#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	int val = 0;

	v.push_back(1);
	v.push_back(1);
	cout << "Fibonacci numbers: " << v[0] << " " << v[1] << " ";
	while (v[v.size() - 2] <= v[v.size() - 1]) {
		if (val) cout << val << " ";
		val = v[v.size() - 2] + v[v.size() - 1];
		v.push_back(val);
	}


}
