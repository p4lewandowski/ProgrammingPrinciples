#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>


struct Reading {
	int hour;
	double temperature;
	char type;
	Reading(int h, double t, char f) : hour(h), temperature(t), type(f) {}
	Reading() :hour{ -1 }, temperature{ -7777 } {}
};


std::ifstream& operator>>(std::ifstream& is, Reading& r);

std::ofstream& operator<<(std::ofstream& os, const Reading& r);

std::ostream& operator<<(std::ostream& os, const std::vector<Reading> v);

void createReadings(int n);
std::vector<Reading> readReadings();
