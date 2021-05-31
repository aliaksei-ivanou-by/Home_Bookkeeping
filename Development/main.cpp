#include "home_bookkeeping/3_GUI/Window_Main.h"

int main()
{
  FinanceRepository a;
  Tag tt;
  Comment cc;
  Payee pp;
  a.AddTag();
  a.AddTag();
  a.AddTag(std::move(tt));
  a.AddComment();
  a.AddComment();
  a.AddComment(std::move(cc));
  a.AddPayee();
  a.AddPayee();
  a.AddPayee(std::move(pp));
  // Window_Main win(Point(100, 100), 600, 600, "Finance System", std::make_shared<FinanceRepository>(a));
  // return gui_main();
}