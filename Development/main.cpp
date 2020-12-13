#include "include/stdafx.h"
#include "include/constants.h"
#include "include/DataAccess.h"
#include "include/BusinessLogic.h"
#include "include/Graphics.h"

void Book_Keeping()
{
	FinanceRepository book_keeping;

	setDefaultAccounts(book_keeping);
	setDefaultCategories(book_keeping);
	setDefaultCurrencies(book_keeping);

	printAccounts(book_keeping);
	printCategories(book_keeping);

	book_keeping.addCurrency({ "RUB", "RUB", false });
	printCurrencies(book_keeping);
	Transaction tr1({ "BYN Cash" }, { "Bills" }, { "" }, 5.5, { "BYN" });
	book_keeping.addTransaction(tr1);
	Transaction tr2({ "BYN Cash" }, { "Bills" }, { "" }, 10.5, { "BYN" });
	book_keeping.addTransaction(tr2);
	Transaction tr3({ "BYN Cash" }, { "Bills" }, { "" }, 8.5, { "BYN" });
	book_keeping.addTransaction(tr3);
	Transaction tr4({ "EUR Cash" }, { "Bills" }, { "" }, 6.5, { "EUR" });
	book_keeping.addTransaction(tr4);
	printTransactions(book_keeping);
}

int main()
{
	Book_Keeping();
	FinanceRepository financeRepository;
	Transaction tr1({ "BYN Cash" }, { "Bills" }, { "" }, 5.5, { "BYN" });
	financeRepository.addTransaction(tr1);
	Transaction tr2({ "BYN Cash" }, { "Bills" }, { "" }, 10.5, { "BYN" });
	financeRepository.addTransaction(tr2);
	Transaction tr3({ "BYN Cash" }, { "Bills" }, { "" }, 8.5, { "BYN" });
	financeRepository.addTransaction(tr3);
	Transaction tr4({ "EUR Cash" }, { "Bills" }, { "" }, 6.5, { "EUR" });
	financeRepository.addTransaction(tr4);
	auto ptrFinanceRepository = std::make_shared<FinanceRepository>(financeRepository);
	Window_Main win(Point(100, 100) , Fl::w() - 200, Fl::h() - 200, "Home Bookkeeping", ptrFinanceRepository);
	win.wait_for_button();
	printTransactions(financeRepository);
	TransactionType tt(TransactionTypeEnum::Expence);
	sumTransactionsByTransactionType(financeRepository, tt);
	return 0;
}