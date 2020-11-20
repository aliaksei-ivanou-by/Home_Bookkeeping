#ifndef BOOKKEEPINGREPOSITORY_H
#include "include/DataAccess2.h"
#endif

#ifndef FUNCTIONS_H
#include "include/Functions.h"
#endif

void Book_Keeping()
{
	BookKeepingRepository book_keeping;
	default_book_keeping(book_keeping);
	print_accounts(book_keeping);
	print_categories(book_keeping);
	book_keeping.add_currency({ "RUB", "RUB", false });
	print_currencies(book_keeping);
	Transaction tr1({ "BYN Cash" }, { "Bills" }, { "" }, 5.5, { "BYN" });
	book_keeping.add_transaction(tr1);
	Transaction tr2({ "BYN Cash" }, { "Bills" }, { "" }, 10.5, { "BYN" });
	book_keeping.add_transaction(tr2);
	Transaction tr3({ "BYN Cash" }, { "Bills" }, { "" }, 8.5, { "BYN" });
	book_keeping.add_transaction(tr3);
	Transaction tr4({ "EUR Cash" }, { "Bills" }, { "" }, 6.5, { "EUR" });
	book_keeping.add_transaction(tr4);
	print_transactions(book_keeping);
}

int main()
{
	Book_Keeping();
	return 0;
}