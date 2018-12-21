#pragma once
#include "Book.h"

Chrono::Date::Date(int dayy, Month monthh, int yearr)
	:day(dayy), month(monthh), year(yearr)
{
	if (year < 1970 || day >31 || day <1)
		throw std::exception();
}

Lib::ISBN::ISBN(std::string isbn) {
	std::stringstream isbn_stream(isbn);
	std::vector<std::string> seglist;
	std::string segment;

	while (std::getline(isbn_stream, segment, '-'))
		seglist.push_back(segment);

	if (seglist.size() != 4)
		throw std::exception();

	for (int i = 0; i < 4; i++) {
		if (i < 3) {
			if (!is_number(seglist[i]))
				throw std::exception();
		}
		else {
			if (seglist[i].size() != 1)
				throw std::exception();

			if (!(std::isdigit(seglist[i][0]) || std::isalpha(seglist[i][0])))
				throw std::exception();
		}
	}
}

bool Lib::ISBN::is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

Lib::Book::Book(std::string aut, std::string tit, bool isChecked, std::string isbn, Chrono::Date date, Genre gen)
	:author{ aut }, title{ tit }, isCheckedOut{ isChecked }, ISBN{ isbn }, copyr_date(date), genre(gen)
{
		Lib::ISBN check(isbn);
}
void Lib::Book::check_outorin() { isCheckedOut = isCheckedOut == true ? false : true; }

std::ostream& Lib::Book::print(std::ostream& os) const
{
	return os << title << "\n" << author << "\n" << ISBN << "\n\n" ;
}

bool Lib::Patron::hasfees() const {
	return !!(get_fees());
}

Lib::Patron::Patron(std::string a, int n, float f) 
	:name(a), cardnumber(n), fees(f)
{
	if (f < 0 || n < 0)
		throw std::exception();
}

Lib::Library::transaction::transaction(Book b, Patron p, Chrono::Date d)
	:book(b), patron(p), date(d)
{
}


void Lib::Library::add_book(Book b) { books.push_back(b);}
void Lib::Library::add_patron(Patron p) { patrons.push_back(p); }
void Lib::Library::checkout_book(Book& b, Patron p) {
	std::vector<Patron> debtors = get_debtors();
	if (
		(std::find(patrons.begin(), patrons.end(), p) != patrons.end()) 
		&&
		(std::find(debtors.begin(), debtors.end(), p) == debtors.end())
		&&
		(std::find(books.begin(), books.end(), b) != books.end())
		&&
		!b.isChecked()) {
		b.check_outorin();
		create_transaction(b, p);
	}
	else {
		throw std::exception("Cannot checkout a book!");
	}
}
void Lib::Library::create_transaction(Book b, Patron p) {
	transactions.push_back(transaction(b, p, Chrono::Date(12, Chrono::jan, 1999)));
}
std::vector<Lib::Patron> Lib::Library::get_debtors() {
	std::vector<Patron> debtors;
	for (auto &patron : patrons) {
		if (patron.get_fees() > 0)
			debtors.push_back(patron);
	}
	return debtors;
}

std::ostream& Lib::operator<<(std::ostream& os, const Lib::Book& b)
{
	return b.print(os);
}



bool Lib::operator==(const Book& b1, const Book& b2) {
	return (b1.get_ISBN() == b2.get_ISBN());
}
bool Lib::operator!=(const Book& b1, const Book& b2) {
	return !(b1==b2);
}

bool Lib::operator==(const Patron& p1, const Patron& p2){
	return (p1.get_cardnumber() == p2.get_cardnumber());
}