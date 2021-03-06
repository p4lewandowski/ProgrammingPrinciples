#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void reverse_inplace(vector<int>& v) {
	for (int i = 0; i < v.size() / 2; i++) {
		swap(v[i], v[v.size() - 1 - i]);
	}
}
vector<int> reverse(vector<int> v) {
	vector<int> k;

	for (int i = v.size() - 1; i > -1; i--)
		k.push_back(v[i]);
	return k;
}


void fibonacci(int x,int y,vector<int>& v, int n) {
	v.push_back(x);
	v.push_back(y);

	for (int i = 0; i < n - 2; i++) {
		v.push_back(v[v.size() - 1] + v[v.size() - 2]);
		if (v[v.size() - 1] < v[v.size() - 2])
		{
			v.pop_back();
			break;
		}
	}
	cout << endl;
}

void print(string label, vector<int> v) {
	cout << "Vector " << label << " will be printed out:\n";
	for (int i : v) 
		cout << i << ' ';
	cout << endl;
}


void reverse_inplace_str(vector<string>& v) {
	for (int i = 0; i < v.size() / 2; i++) {
		swap(v[i], v[v.size() - 1 - i]);
	}
}
vector<string> reverse_str(vector<string> v) {
	vector<string> k;

	for (int i = v.size() - 1; i > -1; i--)
		k.push_back(v[i]);
	return k;
}

void print_str(string label, vector<string> v) {
	cout << "Vector " << label << " will be printed out:\n";
	for (string i : v)
		cout << i << ' ';
	cout << endl;
}


int main()
{
	vector<int> v = { 1, 2, 3, 6, 7, 8 };
	vector<int> v1;
	vector<int> v1r;

	print("MyUno", v);
	fibonacci(1, 1, v1, 10);
	print("fibonacci", v1);
	v1r = reverse(v1);
	print("fibonacci reversed new", v1r);
	v1r = reverse(v1);
	reverse_inplace(v1);
	print("fibonacci inplace", v1);

	vector<string> vs = { "moja", "mama", "chce", "psa" };
	vector<string> vsr;
	print_str("zdanie", vs);
	vsr = reverse_str(vs);
	print_str("nowe zdanie odwrócone", vsr);
	reverse_inplace_str(vs);
	print_str("odwrócone w miejscu", vs);

	vector<string> name = { "Pati", "Dziewan", "Dawid", "Kamil", "Ptemek" };
	vector<double> age;
	cout << endl << "Enter ages:\n";
	double a;
	for (int i = 0; i < name.size(); i++)
		if (cin >> a)
			age.push_back(a);
		else
		{
			cout << "INVALID CHARACTER, ABORT!\n";
			break;
		}
		
	for (int i = 0; i < name.size(); i++)
		cout << "Name: " << name[i] << " Age: " << age[i] << endl;


	vector<string> name_copy = name;
	vector<double> age_copy(name.size());
	sort(name.begin(), name.end());
	cout << endl << "ODWRÓCONE" << endl;

	for (int i = 0; i < name_copy.size(); i++) {
		for (int j = 0; j < name.size(); j++) {
			if (name_copy[i] == name[j]) {
				age_copy[j] = age[i];
				break;
			}
		}
	}

	for (int i = 0; i < name.size(); i++)
		cout << "Name: " << name[i] << " Age: " << age_copy[i] << endl;

}
