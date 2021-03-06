#include "Book.h"

using namespace std;


int main()
{
	try
	{
		Lib::Book book_uno("Ziom", "Mamma mia!", true, "12-43-65-d",
			Chrono::Date(12, Chrono::jan, 1999), Lib::Book::nonfiction);
		cout << book_uno;
		Lib::Book book_duo("Panna", "Komu kija!", false, "1122-473-675-1",
			Chrono::Date(11, Chrono::mar, 2020), Lib::Book::fiction);
		cout << book_duo << endl << (book_uno == book_duo) << endl << !(book_uno == book_duo) << endl;

		Lib::Patron p1 ("Maciek", 123, 1.5);
		cout << p1.hasfees() << endl;
		Lib::Patron p2("Krzysiek", 1254, 0);

		Lib::Library lib;
		lib.add_book(book_uno);
		lib.add_book(book_duo);
		lib.add_patron(p1);
		lib.add_patron(p2);
		lib.checkout_book(book_duo, p2);
		book_uno.check_outorin();
		lib.checkout_book(book_uno, p1);

	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}


	
}