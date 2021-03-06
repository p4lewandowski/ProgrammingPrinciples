#include "Date.h"

int main()
try
{
	Chrono::Date today(1984, Chrono::Date::dec, 25); // initialization
	Chrono::Date tomorrow = today;
	tomorrow.add_day(4);
	Chrono::Date nextMonth = tomorrow;
	nextMonth.add_month(2);
	Chrono::Date nextYear = nextMonth;
	nextYear.add_year(3);
	cout << "holiday is " << today << " few days time is " << tomorrow << 
		" few months is " << nextMonth << " few years is " << nextYear << endl;
	const Chrono::Date check = nextYear;
	cout << Chrono::day_of_week(check) << endl;

	return 0;
}
catch (Chrono::Date::Invalid&) {
	cout << "error: Invalid date\n";
	return 1;
}
catch (...) {
	cout << "Oops: unknown exception!\n";
	return 2;
}