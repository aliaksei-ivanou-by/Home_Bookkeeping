#include "include/stdafx.h"
#include "include/constants.h"
#include "include/2_BusinessLogic.h"

int main()
{
	FinanceRepository a;
	Transaction tr({ "BYN Cash" }, { "Bills" }, 10, { "BYN" });
	Transaction tr1({ "BYN VISA" }, { "Bills" }, 100, { "BYN" });
	a.addTransaction(tr);
	a.addTransaction(tr);
	a.addTransaction(tr);
	a.addTransaction(tr);
	a.addTransaction(tr);
	a.addTransaction(tr1);
	a.addTransaction(tr1);
	a.addTransaction(tr1);
	a.printTransactions();
	std::cout << '\n';
	std::cout << a.sumExpencesToday();
	std::cout << '\n';
	std::cout << a.sumExpencesThisMonth();
	std::cout << '\n';
	std::cout << a.sumExpencesAllTime();
	return 0;
}