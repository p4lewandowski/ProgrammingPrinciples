#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum class Month {
	jan = 1, feb = 2, mar = 3, apr = 4, may = 5, jun = 6,
	jul = 7, aug = 8, sep = 9, oct = 10, nov = 11, dec = 12
};

enum month { // note : no “class”
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month int_to_month(int x)
{
	if (x<int(Month::jan) || int(Month::dec) < x) throw invalid_argument("bad month");
	return Month(x);
}

int main()
{

	Month m;
	m = Month::feb;
	//Month e = feb;//nope
	cout << int(m);

	//Month m2 = feb; // e rror: fe b is not in scope
	//m = 7; // e rror: can’t assign an int to a Month
	//int n = m; // e rror: can’t assign a Month to an int
	Month mm = Month(7); // convert int to Month (unchecked)

	try
	{
		Month ma = int_to_month(0);
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}



	month me = feb; // OK: feb in scope
	month m2 = month::feb; // also OK
	//m = 7; // e rror: can’t assign an int to a Month
	int n = me; // OK: we can assign a month to an int
	//month mm = month(7); // convert int to Month (unchecked)
}
