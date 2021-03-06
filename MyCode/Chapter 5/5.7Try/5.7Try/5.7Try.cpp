#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<double> temps; // tempe rature s
	for (double temp; cin >> temp; ) // re ad and put into temps
		temps.push_back(temp);
	double sum = 0;
	double high_temp = NAN;
	double low_temp = NAN;
	for (int x : temps)
	{
		if (high_temp == NAN && low_temp == NAN)
			high_temp = low_temp = x;
		else {
			if (x > high_temp) high_temp = x; // find high
			if (x < low_temp) low_temp = x; // find low
		}
		sum += x; // compute sum
	}
	cout << "High temperature: " << high_temp << '\n';
	cout << "Low temperature: " << low_temp << '\n';
	cout << "Average temperature: " << sum / temps.size() << '\n';
}
