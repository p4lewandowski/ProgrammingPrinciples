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
	int year;
	cout << "Write year:\n";
	cin >> year;
	int age;
	cout << "Write age:\n";
	cin >> age;

	cout << showbase;
	cout << "Year is: \ndec\t" << year << "\nhex\t" << hex << year << "\noct\t" << oct << year << endl;
	cout << "Age is: \ndec\t" << dec << age << "\nhex\t" << hex << age << "\noct\t" << oct << age << endl;


	int oc, he, de;
	cout << "Write some number three times:\n";
	cin >> de >> hex >> he >> oct >> oc;
	cout << de << endl << he << endl << oc << endl;

	cout << 1234567.89 << endl << defaultfloat << 1234567.89 << endl << fixed << 1234567.89 << endl 
		<< scientific << 1234567.89 << endl;


}