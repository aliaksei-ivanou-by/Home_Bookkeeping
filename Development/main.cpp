#include "include/includeDataAccess2.h"
#include "include/Functions.h"

#include "include/stdafx.h"
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
	using namespace Graph_lib;
	Point t1(100, 100);
	Simple_window win(t1, 600, 400, "Canvas");
	Graph_lib::Polygon poly;
	Graph_lib::Smiley sm({300, 300}, 20);
	win.attach(sm);
	poly.add(Point(300, 200));
	poly.add(Point(350, 100));
	poly.add(Point(400, 200));
	poly.set_color(Color::red);
	win.attach(poly);
	win.wait_for_button();
	return 0;
}