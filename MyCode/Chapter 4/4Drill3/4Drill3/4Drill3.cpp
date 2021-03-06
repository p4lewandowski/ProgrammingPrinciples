#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	double val;
	double sum_dist = 0;
	double max = -1;
	vector<double> dist;
	for (int i = 0; i < 6; i++) {
		cin >> val;
		dist.push_back(val);
	}

	for (double x : dist)
		sum_dist += x;

	for (double x : dist)
		x > max ? max = x : max = max;

	cout << "Distances were: \n";
	for (double x : dist)
		cout << x << ' ';
	cout << "\nLargest distance was: " << max << endl;
	cout << "Mean distance was: " << sum_dist / 6 <<endl;
		
}

