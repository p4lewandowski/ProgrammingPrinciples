#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> days;
	vector<int> values;
	int val;
	string day;
	int rej_count = 0;
	cout << "Write days and numbers until NoDay 0 entered: \n";

	while (true) {
		cin >> day;
		cin >> val;
		if (day == "NoDay" && val == 0) break;
		
		if (day == "Monday" || day == "Mon" || day == "mon")
		{
			days.push_back("Monday");
			values.push_back(val);
		}
		else if (day == "Tuesday" || day == "Tue" || day == "tuesday")
		{
			days.push_back("Tuesday");
			values.push_back(val);
		}
		else if (day == "Thursday" || day == "Thu" || day == "thursday") {
			days.push_back("Thursday");
			values.push_back(val);
		}
		else {
			rej_count++;
		}
	}

	cout << "Days and values where: \n";
	for (int i = 0; i < values.size(); i++) {
		cout << days[i] << " " << values[i] << endl;
	}
	cout << "Count of rejected vals equal to: " << rej_count;


}
