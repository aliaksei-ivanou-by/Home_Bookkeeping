#include "include/stdafx.h"
#include "include/constants.h"
//#include "include/2_BusinessLogic.h"
#include "include/3_GUI.h"

int main()
{
	FinanceRepository a;
	Transaction tr({ "BYN Cash" }, { "Bills" }, 10, { "BYN" });
	Transaction tr1({ "BYN VISA" }, { "Bills" }, 10, { "BYN" });
	Transaction tr2({ "BYN VISA" }, { "BYN Cash" }, { "Transfer" }, 10, { "BYN" });
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
	std::cout << a.sumExpencesToday();
	std::cout << '\n';
	std::cout << a.sumExpencesThisMonth();
	std::cout << '\n';
	std::cout << a.sumExpencesAllTime();
	std::cout << '\n';

	Window_Main win(Point(100, 100), 600, 600, "Finance System", std::make_shared<FinanceRepository>(a));
	return gui_main();
}