#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
	string fname;
	int num = 0;
	cout << "Enter fname:\n";
	cin >> fname;

	ifstream is{ fname };
	if (!is)
		throw exception("Cannot access file!");

	while (!is.eof()) {
		is >> fname;
		if (isdigit(fname[0])) {
			num += stoi(fname);
		}
	}

	//cout << setw(20) << "Kaśka" << setw(20) << "lodziak" << setw(20) << 20 << endl << setw(20) << "Przemyslaw" << setw(20) << "Lewandowski" << setw(20) << 20;
}