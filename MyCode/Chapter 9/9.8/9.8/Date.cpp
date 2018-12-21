#include "Date.h"

namespace Chrono {

	// member function definitions:

	//------------------------------------------------------------------------------

	Date::Date(int yy, Month mm, int dd)
		: y(yy), m(mm), d(dd)
	{
		if (!is_date(yy, mm, dd)) throw Invalid();
	}

	//------------------------------------------------------------------------------

	const Date& default_date()
	{
		static const Date dd(2001, Date::jan, 1); // start of 21st century
		return dd;
	}

	//------------------------------------------------------------------------------

	Date::Date()
		:y(default_date().year()),
		m(default_date().month()),
		d(default_date().day())
	{
	}

	// helper functions:

	bool is_date(int y, Date::Month  m, int d)
	{
		// assume that y is valid

		if (d <= 0) return false;            // d must be positive

		int days_in_month = 31;            // most months have 31 days

		switch (m) {
		case Date::feb:                        // the length of February varies
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Date::apr: case Date::jun: case Date::sep: case Date::nov:
			days_in_month = 30;                // the rest have 30 days
			break;
		}

		if (days_in_month < d) return false;

		return true;
	}

	//------------------------------------------------------------------------------

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}

	//------------------------------------------------------------------------------

	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}

	//------------------------------------------------------------------------------

	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << d.month()
			<< ',' << d.day()
			<< ')';
	}

	//------------------------------------------------------------------------------

	istream& operator>>(istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // oops: format error
			is.clear(ios_base::failbit);                    // set the fail bit
			return is;
		}
		dd = Date(y, Date::Month(m), d);     // update dd
		return is;
	}

	//------------------------------------------------------------------------------


	//------------------------------------------------------------------------------
	// Starting from day one = since 1970
	const Date first_date(1970, Date::jan, 1);
	const Day first_day = thursday;

	Day day_of_week(const Date& d)
	{
		if (d.year() < first_date.year())
			throw invalid_argument("Year below 1970 not supported!");

		int count_leap = 0;
		for (int i = first_date.year(); i <= d.year(); i++)
			count_leap += (leapyear(i) ? 1 : 0);

		int count_months = 0;
		switch (d.month())
		{
		case Date::jan:	count_months = 0;
		case Date::feb:	count_months = 31;
		case Date::mar:	count_months = 31 + 28;
		case Date::apr:	count_months = 31 + 28 + 31;
		case Date::may:	count_months = 31 + 28 + 31 + 30;
		case Date::jun:	count_months = 31 + 28 + 31 + 30 + 31;
		case Date::jul:	count_months = 31 + 28 + 31 + 30 + 31 + 30;
		case Date::aug:	count_months = 31 + 28 + 31 + 30 + 31 + 30 + 31;
		case Date::sep:	count_months = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
		case Date::oct:	count_months = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
		case Date::nov:	count_months = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		case Date::dec:	count_months = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
		}

		int days = (d.year() - first_date.year()) * 365 + count_leap +
			count_months + d.day();

		days %= 7;

		switch (days) {
		case 0:
			return thursday;
		case 1:
			return friday;
		case 2:
			return saturday;
		case 3:
			return sunday;
		case 4:
			return monday;
		case 5:
			return tuesday;
		case 6:
			return wednesday;
		
		}
	}

	//------------------------------------------------------------------------------

	Date next_Sunday(const Date& d)
	{
		// ...
		return d;
	}

	//------------------------------------------------------------------------------

	Date next_weekday(const Date& d)
	{
		// ...
		return d;
	}

	//------------------------------------------------------------------------------

	void Date::add_day(int n)
	{
		switch (m) {
		case jan:
		case mar:
		case may:
		case jul:
		case aug:
		case oct:
		case dec:
			if (d+n > 31) {
				d = d+n-31;
				m = Month(int(m) + 1);
			}
			else
				d += n;
			break;
		case apr:
		case jun:
		case sep:
		case nov:
			if (d == 30) {
				d = 1;
				m = Month(int(m) + 1);
			}
			else
				d += n;
			break;
		case feb:
			if (d + n > 28) {
				d = d + n - 29;
				m = Month(int(m) + 1);
			}
			else
				d += n;
			break;
		}
	}

	//------------------------------------------------------------------------------

	void Date::add_month(int n)
	{
		if (int(m) + n > 12)
			m = Month(int(m) + n - 12);
		else
			m = Month(int(m) + n);
	}

	//------------------------------------------------------------------------------

	void Date::add_year(int n)
	{
		if (m == feb && d == 29 && !leapyear(y + n)) { // beware of leap years!
			m = mar;        // use March 1 instead of February 29
			d = 1;
		}
		y += n;
	}

	//------------------------------------------------------------------------------

	bool leapyear(int y)
	{
		if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
			return true;

		return false;
	}



	//------------------------------------------------------------------------------


	//------------------------------------------------------------------------------

} // Chrono

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
