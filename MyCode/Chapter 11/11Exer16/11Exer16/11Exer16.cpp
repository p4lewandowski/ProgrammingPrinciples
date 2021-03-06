#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <sstream>

using namespace std;

void manage(vector<pair<int, int>>& vv, int val) {
	for (auto& v : vv) {
		if (v.first == val)
		{
			v.second += 1;
			return;
		}
	}
	vv.push_back(make_pair(val, 1));

	sort(vv.begin(), vv.end(),
		[](const pair<int, int>& r1, const pair<int, int>& r2) {
		return r1.first < r2.first;
	});
}

int main()
{
	cout << "File name:\n";
	string fn;
	cin >> fn;
	ifstream is{ fn };
	if (!is) throw exception("Cannot open file!\n");

	int i;
	vector<pair<int, int>> occur;
	while (is >> i) 
		manage(occur, i);
	
	for (auto& v : occur)
		cout << v.first << ' ' << v.second << endl;

}

