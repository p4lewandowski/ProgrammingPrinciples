#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double ctok(double c) // conve rts Ce lsius to Ke lvin
{
	if (c < -273.15) throw invalid_argument("Received value below absolute zero in ctok!\n");

	double k = c + 273.15;
	return k;
}

double ktoc(double k) // conve rts Ce lsius to Ke lvin
{
	if (k < 0) throw invalid_argument("Received value below absolute zero in ktoc!\n");

	double c = k - 273.15;
	return c;
}

int main()
{
	double c = 0; // de clare input variable
	cout << "Entered: ";
	cin >> c; // re trie ve tempe rature to input variable
	try
	{
		double k = ctok(c); // conve rt tempe rature
		cout << k << "K" << endl; // print out tempe rature
		double r = ktoc(k); // conve rt tempe rature
		cout << r << "C" << endl; // print out tempe rature

	}
	catch (invalid_argument& e)
	{
		cout << e.what() << "\n in main\n";
	}
}