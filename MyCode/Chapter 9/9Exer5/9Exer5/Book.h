#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cstring>

namespace Chrono {
	enum Day {
		mon = 1, tue, wed, thu, fri, sat, sun
	};
	enum Month {
		jan = 1, feb, mar, apr, may, jun, jul,
		sep, oct, nov, dec
	};

	class Date {
		int day;
		Month month;
		int year;
	public:
		Date(int, Month, int);
	};
}


namespace Lib {

	struct ISBN {
		ISBN(std::string);
		bool is_number(const std::string&);
	};

	class Book {
	public:
		enum Genre {
			fiction, nonfiction, periodical, biography, children
		};

		Book(std::string, std::string, bool, std::string, Chrono::Date, Genre);
		bool isChecked() { return isCheckedOut; }
		void check_outorin();
		std::string get_author() const { return author; }
		std::string get_title() const { return title; }
		std::string get_ISBN() const { return ISBN; }
		std::ostream& print(std::ostream& os) const;

	private:
		std::string author;
		std::string title;
		bool isCheckedOut;
		std::string ISBN;
		Chrono::Date copyr_date;
		Genre genre;
	};

	class Patron {
	public:
		Patron(std::string, int, float);
		std::string get_name() const { return name; }
		int get_cardnumber()const { return cardnumber; }
		float get_fees()const { return fees; }
		void set_fees(float new_fees) { fees = new_fees; }
		bool hasfees() const;
	private:
		std::string name;
		int cardnumber;
		float fees;
	};

	class Library {
	public:
		struct transaction {
			Book book;
			Patron patron;
			Chrono::Date date;
			transaction(Book, Patron, Chrono::Date);
		};
		void add_book(Book);
		void add_patron(Patron);
		void checkout_book(Book&, Patron);
		void create_transaction(Book, Patron);
		std::vector<Patron> get_debtors();
	private:
		std::vector<Book> books;
		std::vector<Patron> patrons;
		std::vector<transaction> transactions;
	};

	std::ostream& operator<<(std::ostream&, const Lib::Book&);

	bool operator==(const Book&, const Book&);
	bool operator!=(const Book&, const Book&);
	bool operator==(const Patron&, const Patron&);
}


