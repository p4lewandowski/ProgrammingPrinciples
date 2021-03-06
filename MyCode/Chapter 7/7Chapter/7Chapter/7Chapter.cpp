#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Token {
public:
		char kind;
		double value;
		string name;
		Token(char ch) :kind(ch), value(0) { }
		Token(char ch, double val) :kind(ch), value(val) { }
		Token(char ch, string n) : kind{ ch }, name{ n } { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = 'L';
const char quit = 'Q';
const char print = '=';
const char number = '8';
const char name = 'a';
const char term_char = ';';
const char square = 's';
const char power = 'p';

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
	case ';':
	case ',':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)) || ch=='_') s += ch;
			cin.unget();
			if (s == "let") return Token(let);
			if (s == "quit") return Token(quit);
			if (s == "sqrt") return Token(square);
			if (s == "pow") return Token(power);
			return Token(name, s);
		}
		throw runtime_error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	throw runtime_error("get: undefined name ");
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	throw runtime_error("set: undefined name ");
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

void find_and_change(string searched, double val) {
	for (int i = 0; i < names.size(); ++i)
	{
		if (names[i].name == searched) names[i].value = val;
		break;
	}
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	
		double d = expression();
		t = ts.get();
		if (t.kind != ')') throw runtime_error("')' expected");
		return d;
	}
	case '-':
		return -primary();
	case square:   // handle 'sqrt(' expression ')'
	{   
		t = ts.get();
		if (t.kind != '(')  throw runtime_error("'(' expected");
		double d = expression();
		if (d < 0)  throw runtime_error("Square roots of negative numbers!\n");
		t = ts.get();
		if (t.kind != ')')  throw runtime_error("')' expected");
		return sqrt(d);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '(')  throw runtime_error("'(' expected");
		double d = expression();

		t = ts.get();
		if (t.kind != ',')  throw runtime_error("')' expected comma!");
		int p = expression();

		t = ts.get();
		if (t.kind != ')')  throw runtime_error("')' expected");

		return pow(d, p);
	}
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		throw runtime_error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) throw runtime_error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') throw runtime_error("name expected in declaration");
	string name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') throw runtime_error("= missing in declaration of ");
	double d = expression();

	if (is_declared(name)) {
		cout << (" value will be rewritten");
		find_and_change(name, d);
	}
	else
		names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	cout << "Insert ; to proceed\n";
	ts.ignore(term_char);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
{
	
	names.push_back(Variable("k", 1000.0));

	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		cout << "Insert ; to proceed\n";
		while (cin >> c && c != term_char);
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		cout << "Insert ; to proceed\n";
		while (cin >> c && c != term_char);
		return 2;
	}
}