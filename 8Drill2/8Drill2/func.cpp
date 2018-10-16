#include "pch.h"
#include "dec.h"

void swap_v(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//void swap_cr(const int& a, const int& b) {
//	int temp = a;
//	a = b;
//	b = a;
//}