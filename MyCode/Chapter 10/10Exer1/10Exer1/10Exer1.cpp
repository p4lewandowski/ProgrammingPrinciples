#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int sum_file() {
	cout << "Enter file name:\n";
	string fname;
	int num;
	int sum = 0;

	cin >> fname;
	ifstream fin{ fname };
	if (!fin) throw exception("Cannot open file!");
	while (fin >> num) sum += num;
	return num;
}


int main()
{
	cout << "File summed: " << sum_file();
}