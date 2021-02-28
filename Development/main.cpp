#include "include/stdafx.h"
#include "include/constants.h"
//#include "include/2_BusinessLogic.h"
#include "include/3_GUI.h"

int main()
{
	FinanceRepository a;
	Transaction tr({ "BYN Cash" }, { "Bills" }, 10);
	Transaction tr1({ "BYN VISA" }, { "Bills" }, 10);
	Transaction tr2({ "BYN VISA" }, { "BYN Cash" }, { "Transfer" }, 10);
	a.addTransaction(tr);
	a.addTransaction(tr);
	a.addTransaction(tr);
	a.addTransaction(tr1);
	a.addTransaction(tr1);
	a.addTransaction(tr1);
	a.addTransaction(tr2);
	a.addTransaction(tr2);
	a.addTransaction(tr2);
	a.printTransactions();
	std::cout << '\n';
	std::cout << a.sumExpensesToday();
	std::cout << '\n';
	std::cout << a.sumExpensesThisMonth();
	std::cout << '\n';
	std::cout << a.sumExpensesAllTime();
	std::cout << '\n';

	Window_Main win(Point(100, 100), 600, 600, "Finance System", std::make_shared<FinanceRepository>(a));
	return gui_main();
}