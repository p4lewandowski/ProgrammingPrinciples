#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


namespace X {
	int var;
	void print() {
		std::cout << var << std::endl;
	}
}

namespace Y {
	int var;
	void print() {
		std::cout << var << std::endl;
	}
}

namespace Z {
	int var;
	void print() {
		std::cout << var << std::endl;
	}
}

class B {
private:
	int var;
public:
	void setvar() {
		var = 5;
	}
	int getvar() {
		return var;
	}
};


int main()
{
	X::var = 7;
	X::print(); // print X’s var
	using namespace Y;
	var = 9;
	print(); // print Y’s var
	{ 
		using Z::var;
		using Z::print;
		var = 11;
		print(); // print Z’s var
	}
	print(); // print Y’s var
	X::print(); // print X’s var

	B b;
	std::cout << b.getvar() << std::endl;
	b.setvar();
	std::cout << b.getvar() << std::endl;
}