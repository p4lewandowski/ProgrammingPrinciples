#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> grid;
	vector<int>prime;
	int count = 0;
	int isDiv = 0;
	int n = 0;
	cin >> n;

	for (int i = 2; i < 101; i++) {
		grid.push_back(i);
	}

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < prime.size(); j++) {
			if (grid[i] % prime[j] == 0)
				isDiv=1;
		}
		if (!isDiv) {
			prime.push_back(grid[i]);
			count++;
		}
		isDiv = 0;

		if (count == n)
			break;
	}

	for (int i : prime)
		cout << i << ' ';

}

