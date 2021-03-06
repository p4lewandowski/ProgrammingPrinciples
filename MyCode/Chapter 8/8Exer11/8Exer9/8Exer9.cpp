#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct result {
	double mean = 0;
	double median = 0;
	double largest = numeric_limits<double>::lowest();
	double smallest = numeric_limits<double>::max();
};

void find(result& res, const vector<double>& v) {
	for (int i = 0; i < v.size(); i++) {
		res.mean += v[i];
		if (v[i] > res.largest) res.largest = v[i];
		if (v[i] < res.smallest) res.smallest= v[i];
	}
	res.mean /= v.size();

	vector<double> sorted = v;
	sort(sorted.begin(), sorted.end());
	if (sorted.size() % 2)
		res.median = sorted[sorted.size() / 2];
	else
		res.median = (sorted[sorted.size() / 2] + sorted[sorted.size() / 2 - 1]) / 2;

}

int main()
{
	result res;
	vector<double> v = { 23, 3, 4, 5, 6 , 7};

	find(res, v);

	cout << "min:" << res.smallest << endl << "max:" << res.largest << endl << "med:" << res.median << endl << "mean:" << res.mean << endl;

}
