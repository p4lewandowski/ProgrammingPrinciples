#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <sstream>

using namespace std;


//------------------------------------------------------------------------------

template<class T>
char* as_bytes(T& i)    // treat a T as a sequence of bytes
{
	void* addr = &i;    // get the address of the first byte
	// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}

void to_bin() {
	ifstream ifs("in.txt");
	if (!ifs) throw exception("can't open input file ");

	ofstream ofs("out", ios_base::binary);
	if (!ofs) throw exception("can't open output file ");

	char c;
	while (ifs.get(c) && ifs)
		ofs.write(as_bytes(c), sizeof(char));
}

void to_txt() {
	ifstream ifs("out", ios_base::binary);
	if (!ifs) throw exception("can't open input file ");

	ofstream ofs("out.txt");
	if (!ofs) throw exception("can't open output file ");

	char c;
	while (ifs.read(as_bytes(c), sizeof(char)) && ifs) {
		ofs << c;
	}
}

bool compare_files() {
	ifstream ifb("out", ios_base::binary);
	if (!ifb) throw exception("can't open input file ");

	ifstream ift("in.txt");
	if (!ift) throw exception("can't open input file ");

	char c1, c2;
	while (ifb.read(as_bytes(c1), sizeof(char)) && ift.get(c2))
	{
		cout << c1 << c2;
		if (c1 != c2)
			return false;
	}
	cout << endl;
	return true;
}


int main()
try
{
	to_bin();
	to_txt();
	if (compare_files())
		cout << "Good copy\n";
	else
		cout << "Bad copy\n";

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}

//------------------------------------------------------------------------------
