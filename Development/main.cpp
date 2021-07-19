#include "include/3_GUI/Window_Main.h"

int main()
{
  FinanceRepository a;
  Window_Main win(Point(100, 100), 600, 600, "Finance System", std::make_shared<FinanceRepository>(a));
  return gui_main();
}