#include "include/stdafx.h"
#include "include/constants.h"
//#include "include/1_DataAccess_Additional.h"
//#include "include/1_DataAccess_Main.h"
#include "include/2_BusinessLogic.h"
//#include "include/3_GUI.h"

int main()
{
	FinanceRepository a;
	a.addAccount({ "BYN Cash" });
	a.addAccount({ "BYN VISA" });
	a.printAccounts(", ");
	std::cout << '\n';
	a.addTransaction({{ "BYN Cash" }, { "Bills" }, 22, { "BYN" } });
	Transaction tr({ "BYN Cash" }, { "Bills" }, 12, { "BYN" });
	a.addTransaction(tr);
	a.printTransactions();
	std::cout << '\n';
	std::cout << a.sumExpencesToday();
	std::cout << '\n';
	std::cout << a.sumExpencesThisMonth();
	std::cout << '\n';
	std::cout << a.sumExpencesAllTime();
	return 0;
}