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
	//Book_Keeping();
	BookkkeepingMainWindow win(Point(100, 100), 600, 600, "Home Bookkeeping");
	Group table;
	int start = 10;
	int delta = 135;
	table.add(new Box_text(Point(start + delta * 0, 50), "logic error"));					// 1
	table.set_color(Color::black);
	table.set_fill_color(Color::blue);
	win.attach(table);
	win.wait_for_button();
	return 0;
}