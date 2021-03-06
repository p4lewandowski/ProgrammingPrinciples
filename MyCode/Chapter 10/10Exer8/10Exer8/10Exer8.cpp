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
	try
	{
		string fname1;
		string fname2;

		cout << "Enter two filenames:\n";
		cin >> fname1 >> fname2;
		if (!cin)
			throw exception("Something went wrong when reading in the filenames!");

		ifstream is1{ fname1 };
		if (!is1)
			throw exception("Something went wrong when opening the file!");
		ifstream is2{ fname2 };
		if (!is2)
			throw exception("Something went wrong when opening the file!");

		ofstream os{ "concatenated.txt" };
		if (!os)
			throw exception("Cannot open output file!");

		is1 >> fname1;
		is2 >> fname2;
		if (!(is1 || is2))
			throw exception("Files not filled!\n");

		while (true) {
			if (fname1 < fname2)
			{
				os << fname1 << ' ';
				is1 >> fname1;
				if (is1.eof()) {
					while (true) {
						os << fname2 << ' ';;
						is2 >> fname2;
						if (is2.eof())
							break;
					}
					break;
				}
			}
			else {
				os << fname2 << ' ';;
				is2 >> fname2;
				if (is2.eof()) {
					while (true) {
						os << fname1 << ' ';;
						is1 >> fname1;
						if (is1.eof())
							break;
					}
					break;
				}
			}
		}

		cout << "Done\n";
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}

}