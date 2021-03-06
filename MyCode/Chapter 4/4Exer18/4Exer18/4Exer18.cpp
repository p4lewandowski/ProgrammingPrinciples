#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c;
	cout << "Write a b and c for ax**2 + bx + c" << endl;
	cin >> a >> b >> c;

	double delta;
	double x1;
	double x2;

	delta = b * b - 4 * a*c;
	if (delta > 0) {
		x1 = (-b + sqrt(delta)) / 2 * a;
		x2 = (-b - sqrt(delta)) / 2 * a;
		cout << "First point: " << x1 << endl;
		cout << "Second point: " << x2 << endl;

	}
	else if (delta == 0) {
		x1 = -b / (2*a);
		cout << "one point: " << x1 << endl;
	}
	else cout << "Unable to calculate points!\n";

}

