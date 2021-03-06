#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

tuple<double, double, int> calc_zero(double a, double b, double c) // conve rts Ce lsius to Ke lvin
{
	double delta = pow(b, 2) - 4 * a*c;
	cout << "Delta was: " << delta << endl;
	if (delta < 0) throw domain_error("Delta ujemna!\n");
	tuple<double, double, int> result;

	if (delta == 0) {
		double x = -b / 2 * a;
		
		return make_tuple(x, 0 , 1);
	}
	else {
		double x1 = (-b + delta) / 2 * a;
		double x2 = (-b - delta) / 2 * a;
		tuple<double, double, int> result(x1, x2, 2);
		return result;
	}
}


int main()
{
	cout << "Enter a b c" << endl;
	double a, b, c;
	cin >> a >> b >>c;
	tuple<double, double, int> result;

	try
	{
		result = calc_zero(a, b, c);
		if (get<2>(result) == 1) {
			cout << "One zero-place found: " << get<0>(result) << endl;
		}
		else {
			cout << "Two zero-places found: " << get<0>(result) << " and "<< get<1>(result) << endl;
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << "\nError in main.\n";
	}
}