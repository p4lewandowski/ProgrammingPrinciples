#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	string unit;
	double val = 0;
	double largest = 0;
	double smallest = 0;
	int count=0;
	double sum=0;
	vector<double> vals;

	while (1) {
		cin.clear();
		cin >> val >> unit;

		//Testing for unit
		if (unit != "cm" && unit != "m" && unit != "in" && unit != "ft")
		{
			cout << "Wrong unit entered!\n";
			break;
		}
		else {
			if (unit == "cm") val *= 0.01;
			if (unit == "in") val *= 0.01*2.54;
			if (unit == "ft") val *= 12*2.54*0.01;

			if (val == largest && val == smallest);
			else if (val > largest) {
				cout << "This value: " << val << "m was the largest!\n";
				largest = val;
			}
			else if (val < smallest) {
				cout << "This value: " << val << "m was the smallest!\n";
				smallest = val;
			}
			sum += val;
			count++;
			vals.push_back(val);
		}
	}
	cout << "Value: " << largest << "m was the largest!\n";
	cout << "Value: " << smallest << "m was the smallest!\n";
	cout << "Sum: " << sum << "m!\n";
	cout << "Count of entered numbers: " << count << "!\n";
	sort(vals.begin(), vals.end());
	cout << "The numbers were:\n";
	for (double x : vals)
		cout << x << " ";
}

