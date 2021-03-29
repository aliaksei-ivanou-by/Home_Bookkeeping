//  #include "home_bookkeeping/2_BusinessLogic/FinanceRepository.h"
#include "home_bookkeeping/3_GUI/Window_Main.h"

int main()
{
  FinanceRepository a;
  Transaction tr({ "BYN Cash" }, { "Bills" }, 10);
  Transaction tr1({ "BYN VISA" }, { "Bills" }, 10);
  Transaction tr2({ "BYN VISA" }, { "BYN Cash" }, { "Transfer" }, 10);
  a.AddTransaction(tr);
  a.AddTransaction(tr);
  a.AddTransaction(tr);
  a.AddTransaction(tr1);
  a.AddTransaction(tr1);
  a.AddTransaction(tr1);
  a.AddTransaction(tr2);
  a.AddTransaction(tr2);
  a.AddTransaction(tr2);
  a.PrintTransactions();
  std::cout << '\n';
  std::cout << a.SumExpensesToday();
  std::cout << '\n';
  std::cout << a.SumExpensesThisMonth();
  std::cout << '\n';
  std::cout << a.SumExpensesAllTime();
  std::cout << '\n';

  Window_Main win(Point(100, 100), 600, 600, "Finance System", std::make_shared<FinanceRepository>(a));
  return gui_main();
}