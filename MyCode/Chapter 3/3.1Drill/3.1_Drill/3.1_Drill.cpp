// 3.1_Drill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string us_name = "";
	string mention_name = "";
	char fr_sex = 0;
	int age = 0;

	cout << "Write to:\n";
	cin >> us_name;

	cout << "Mention:\n";
	cin >> mention_name;

	cout << "Gender (m or f):\n";
	cin >> fr_sex;

	cout << "Age:\n";
	cin >> age;

	cout << "Dear " + us_name + ",\n";
	cout << "\tHow are you? I am fine. I miss you. Never gonna give you up, never gonna let you down. "
		<< "Have you seen " + mention_name + " lately? ";
	if (fr_sex == 'm')
		cout << "If you see " + mention_name + " please ask him to call me. ";
	else if (fr_sex == 'f')
		cout << "If you see " + mention_name + " please ask her to call me. ";
	else
		cout << "What was his gender, again? ";

	char agee = (char) age ; // Must be larger than one! for narrowing, but it did not work char agee {age}
	cout << "I hear you just had a birthday and you are " << age << " years old! ";
	if (age < 0 || age >110)
		cout << "Are you kidding! ";
	else if (age < 12)
		cout << "Next year you will be " << ++age << "! ";
	else if (age == 17)
		cout << "Next year you will be able to vote! ";
	else if (age > 70)
		cout << "Hope you are enjoying retirement! ";

	cout << "\n\nYours sincerely,\n\n";



}
