#ifndef HOMEBOOKKEEPING_LIB_GRAPH_SIMPLEWINDOW_H_
#define HOMEBOOKKEEPING_LIB_GRAPH_SIMPLEWINDOW_H_

#include "lib/graph/GUI.h"
#include "lib/graph/Graph.h"

using namespace Graph_lib;

struct Simple_window : Graph_lib::Window
{
  Simple_window(Point xy, int w, int h, const std::string& title);
  bool wait_for_button();
private:
  Button next_button;
  bool button_pushed;
  static void cb_next(Address, Address);
  void next();
};

#endif  //  HOMEBOOKKEEPING_LIB_GRAPH_SIMPLEWINDOW_H_
