#ifndef HOMEBOOKKEEPING_3GUI_WINDOWADDACCOUNT_H_
#define HOMEBOOKKEEPING_3GUI_WINDOWADDACCOUNT_H_

#include "lib/graph/FLTK.h"
#include "lib/graph/Point.h"
#include "lib/graph/Graph.h"
#include "lib/graph/Graph_Additional.h"
#include "lib/graph/GUI.h"
#include "lib/graph/Simple_window.h"
#include "lib/graph/Window.h"

#include "include/2_BusinessLogic/FinanceRepository.h"
#include "include/3_GUI/Window_Main.h"

namespace Graph_lib
{
  class Window_AddAccount : public Window
  {
  public:
    Window_AddAccount(
      const std::string& title,
      std::shared_ptr<FinanceRepository> ptrFinanceRepository,
      Point xy = Point{ 150, 150 }, int w = 400, int h = 400);
    Button buttonOK;
    Button buttonCancel;
    bool wait_for_button();
    std::shared_ptr<FinanceRepository> ptrFinanceRepository;
  private:
    int elementSizeWidth = 200;
    int elementSizeHeight = 30;

    bool button_pushed;

    In_box textAccountForAdd;

    static void cbOK(Address, Address);
    static void cbCancel(Address, Address);

    void OK();
    void Cancel();
  };
}

#endif
