#ifndef HOMEBOOKKEEPING_LIB_GRAPH_WINDOW_H_
#define HOMEBOOKKEEPING_LIB_GRAPH_WINDOW_H_

#include "lib/graph/Point.h"
#include "lib/graph/FLTK.h"
#include "lib/graph/Graph.h"

namespace Graph_lib
{
  class Shape;

  class Widget;

  class Window : public Fl_Window
  {
  public:
    Window(int w, int h, const std::string& title);
    Window(Point xy, int w, int h, const std::string& title);
    virtual ~Window();
    int x_max() const;
    int y_max() const;
    void resize(int ww, int hh);
    void set_label(const std::string& s);
    void attach(Shape& s);
    void attach(Widget&);
    void detach(Shape& s);
    void detach(Widget& w);
    void put_on_top(Shape& p);
  protected:
    void draw();
  private:
    std::vector<Shape*> shapes;
    int w, h;
    void init();
  };
  int gui_main();
  inline int x_max();
  inline int y_max();
}

#endif  //  HOMEBOOKKEEPING_LIB_GRAPH_WINDOW_H_
