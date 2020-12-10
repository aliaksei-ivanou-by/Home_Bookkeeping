#include "include/stdafx.h"
#include "include/constants.h"
#include "include/DataAccess.h"
#include "include/BusinessLogic.h"
#include "include/Graphics.h"

void Book_Keeping()
{
	FinanceRepository book_keeping;
	default_book_keeping(book_keeping);
	print_accounts(book_keeping);
	print_categories(book_keeping);
	book_keeping.addCurrency({ "RUB", "RUB", false });
	print_currencies(book_keeping);
	Transaction tr1({ "BYN Cash" }, { "Bills" }, { "" }, 5.5, { "BYN" });
	book_keeping.addTransaction(tr1);
	Transaction tr2({ "BYN Cash" }, { "Bills" }, { "" }, 10.5, { "BYN" });
	book_keeping.addTransaction(tr2);
	Transaction tr3({ "BYN Cash" }, { "Bills" }, { "" }, 8.5, { "BYN" });
	book_keeping.addTransaction(tr3);
	Transaction tr4({ "EUR Cash" }, { "Bills" }, { "" }, 6.5, { "EUR" });
	book_keeping.addTransaction(tr4);
	print_transactions(book_keeping);
}

int main()
{
	Book_Keeping();
	Window_Main win(Point(100, 100), Fl::w() - 200, Fl::h() - 200, "Home Bookkeeping");
	win.wait_for_button();
	return 0;
}