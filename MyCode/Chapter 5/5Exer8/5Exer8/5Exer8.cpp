#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count_and_sum(vector<int> v, int N) {
	
	if (N < 0)
	{
		cerr << "Value smaller than 0!" << endl;
		throw invalid_argument("Elements to count lower than 0!\n");
	}
	if(v.at(N - 1));

	int sum = 0;

	cout << "All entered values: \n";
	for (int i : v)
		cout << i << " ";

	for (int i = 0; i < N; i++)
		sum += v[i];

	cout << "Sum of its " << N << " elements is: " << sum;

	return sum;

}

int main()
{
	int N;
	int val;
	vector<int> v;

	cout << "Enter number of values to sum:" << endl;
	cin >> N;
	cout << "Enter the values (terminate with |): " << endl;
	while (cin) {
		cin >> val;
		if(cin)
			v.push_back(val);
	}

	try {
		count_and_sum(v, N);
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << "\nNot enough values listed!" << endl;
	}



}
