#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cout << "Plea se enter a n integer in the ra nge 1 to 10 (inclusive):\n";
	int n = 0;
	while (true) {
		cin >> n;
		if (cin) { // we got an inte ge r; now che ck it
			if (1 <= n && n <= 10) break;
			cout << "Sorry "
				<< n << " is not in the [1:10] ra nge; plea se try a ga in\n";
		}
		else if (cin.fail()) { // we found some thing that wasn’t an inte ge r
			cin.clear(); // se t the state back to good();
			// we want to look at the characte rs
			cout << "Sorry, tha t wa s not a number; plea se try a ga in\n";
			for (char ch; cin >> ch && !isdigit(ch); ) // throw away non-digits
				/* nothing */;
			if (!cin) throw exception("no input"); // we didn’t find a digit: give up
			cin.unget(); // put the digit back, so that we can re ad the numbe r
		}
		else {
			throw exception("no input"); // e of or bad: give up
		}
	}
	// if we ge t he re n is in [1:10]


}