//  #include "home_bookkeeping/2_BusinessLogic/FinanceRepository.h"
#include "home_bookkeeping/3_GUI/Window_Main.h"
#include "home_bookkeeping/2_BusinessLogic/DatabaseManager.h"

int main()
{
  FinanceRepository a;
  Transaction tr({ "BYN Cash" }, { "Bills" }, 10);
  Transaction tr1({ "BYN VISA" }, { "Bills" }, 10);
  Transaction tr2({ "BYN VISA" }, { "BYN Cash" }, { "Transfer" }, 10);
  a.AddTransaction(std::move(tr));
  a.AddTransaction({{ "BYN Cash" }, { "Bills" }, 10});
  a.AddTransaction(std::move(tr));
  a.AddTransaction(std::move(tr));
  a.AddTransaction(std::move(tr));
  a.AddTransaction(std::move(tr1));
  a.AddTransaction(std::move(tr1));
  a.AddTransaction(std::move(tr2));
  a.AddTransaction(std::move(tr2));
  a.AddTransaction(std::move(tr2));
  Transaction tr3({ "USD Cash" }, { "Bills" }, 10);
  a.AddTransaction(std::move(tr3));
  Window_Main win(Point(100, 100), 600, 600, "Finance System", std::make_shared<FinanceRepository>(a));
  return gui_main();
}