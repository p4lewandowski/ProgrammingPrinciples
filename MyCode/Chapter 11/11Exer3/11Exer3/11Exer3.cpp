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
	cout << "File name:\n";
	string fn;
	cin >> fn;
	ifstream is{ fn };
	if (!is) throw exception("Cannot open file!\n");

	char c;
	string vowels{ "AEIOUaeiou" };
	while (is.get(c)) {
		for (char v : vowels)
			if (c == v)
				c = (char)0;
		if(c)
			cout << c;
	}


}

