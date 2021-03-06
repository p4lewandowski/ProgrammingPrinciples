#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
	string str;
	vector<char> seen;
	while (cin >> str && cin) {
		seen.clear();
		for (char& c : str) {
			if (!(find(seen.begin(), seen.end(), c) != seen.end())) {
				cout << c;
				if (isspace(c)) cout << " isspace";
				if (isalpha(c)) cout << " isalpha";
				if (isdigit(c)) cout << " isdigit";
				if (isxdigit(c)) cout << " isxdigit";
				if (isupper(c)) cout << " isupper";
				if (islower(c)) cout << " islower";
				if (isalnum(c)) cout << " isalnum";
				if (iscntrl(c)) cout << " iscntrl";
				if (ispunct(c)) cout << " ispunct";
				if (isprint(c)) cout << " isprint";
				if (isgraph(c)) cout << " isgraph";
				cout << endl;
				seen.push_back(c);
			}
		}
	}


}

