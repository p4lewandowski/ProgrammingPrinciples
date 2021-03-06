#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
// Did not end ex 15;

class Money {
public:
	long int get_money() { return amount; }
	enum currency {
		USD, EUR
	};
	Money(string m) {
		std::stringstream m_stream(m);
		std::vector<std::string> parsed_str;
		string segment;

		while (getline(m_stream, segment, '.'))
			parsed_str.push_back(segment);
		if (parsed_str[0].at(0 == '$') && parsed_str[1].size() == 2) {
			try
			{
				parsed_str[0].erase(0, 1);
				amount += std::stoi(parsed_str[0])*100;
				amount += ((std::stoi(parsed_str[1]) + 4) / 5) * 5;
			}
			catch (const std::exception& e)
			{
				cerr << "Not a number!";
			}
		}
		else {
			cerr << "Wrong format!";
		}
	}
private:
	long int amount{ 0 };
	currency curr;
};



int main()
{
	Money m("$123.47");
	cout << m.get_money();
}