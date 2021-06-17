#include "home_bookkeeping/3_GUI/Window_Main.h"

int main()
{
  FinanceRepository a;
  a.AddTransaction(Transaction(Account("BYN"), Category(), 10));
  a.AddTransaction(Transaction(Account("BYN"), Category(), 10));
  a.AddTransaction(Transaction(Account("BYN"), Category(), 10));
  a.AddTransaction(Transaction(Account("USD"), Category(), 20));
  a.AddTransaction(Transaction(Account("USD"), Category(), 20));
  a.AddTransaction(Transaction(Account("BYN"), Account("USD"), Category(), 10));
  //Window_Main win(Point(100, 100), 600, 600, "Finance System", std::make_shared<FinanceRepository>(a));
  //return gui_main();
}