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
	while (is.get(c)) {
		if (islower(c))
			c = toupper(c);
		cout << c;
	}



}