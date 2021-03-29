#include "home_bookkeeping/lib/graph/GUI.h"

namespace Graph_lib
{
  Widget::Widget(Point xy, int w, int h, const std::string& s, Callback cb):
    loc{ xy },
    width{ w },
    height{ h },
    label{ s },
    do_it{ cb }
  {}

  Widget::~Widget()
  {}

  void Widget::move(int dx, int dy)
  {
    hide();
    pw->position(loc.x += dx, loc.y += dy);
    show();
  }

  void Widget::hide()
  {
    pw->hide();
  }

  void Widget::show()
  {
    pw->show();
  }

  Button::Button(Point xy, int w, int h, const std::string& label, Callback cb):
    Widget{ xy, w, h, label, cb }
  {}

  void Button::attach(Graph_lib::Window& win)
  {
    pw = new Fl_Button(loc.x, loc.y, width, height, label.c_str());
    pw->callback(reinterpret_cast<Fl_Callback*>(do_it), &win);
    own = &win;
  }

  In_box::In_box(Point xy, int w, int h, const std::string& s):
    Widget{ xy, w, h, s, 0 }
  {}

  int In_box::get_int()
  {
    Fl_Input& pi = reference_to<Fl_Input>(pw);
    const char* p = pi.value();
    if (!isdigit(p[0]))
    {
      return -999999;
    }
    return atoi(p);
  }

  std::string In_box::get_string()
  {
    Fl_Input& pi = reference_to<Fl_Input>(pw);
    return std::string(pi.value());
  }

  void In_box::attach(Graph_lib::Window& win)
  {
    pw = new Fl_Input(loc.x, loc.y, width, height, label.c_str());
    own = &win;
  }

  Out_box::Out_box(Point xy, int w, int h, const std::string& s):
    Widget{ xy, w, h, s, 0 }
  {}

  void Out_box::put(const std::string& s)
  {
    reference_to<Fl_Output>(pw).value(s.c_str());
  }

  void Out_box::attach(Graph_lib::Window& win)
  {
    pw = new Fl_Output(loc.x, loc.y, width, height, label.c_str());
    own = &win;
  }

  Menu::Menu(Point xy, int w, int h, Kind kk, const std::string& label):
    Widget{ xy, w, h, label, 0 },
    k{ kk },
    offset{ 0 }
  {}

  int Menu::attach(Button& b)
  {
    b.width = width;
    b.height = height;
    switch (k)
    {
    case horizontal:
    {
      b.loc = Point(loc.x + offset, loc.y);
      offset += b.width;
      break;
    }
    case vertical:
    {
      b.loc = Point(loc.x, loc.y + offset);
      offset += b.height;
      break;
    }
    }
    selection.push_back(b);
    return int(selection.size() - 1);
  }

  int Menu::attach(Button* p)
  {
    Button& b = *p;
    b.width = width;
    b.height = height;
    switch (k)
    {
    case horizontal:
    {
      b.loc = Point(loc.x + offset, loc.y);
      offset += b.width;
      break;
    }
    case vertical:
    {
      b.loc = Point(loc.x, loc.y + offset);
      offset += b.height;
      break;
    }
    }
    selection.push_back(&b);
    return int(selection.size() - 1);
  }

  void Menu::show()
  {
    for (unsigned int i = 0; i < selection.size(); ++i)
    {
      selection[i].show();
    }
  }

  void Menu::hide()
  {
    for (unsigned int i = 0; i < selection.size(); ++i)
    {
      selection[i].hide();
    }
  }

  void Menu::move(int dx, int dy)
  {
    for (unsigned int i = 0; i < selection.size(); ++i)
    {
      selection[i].move(dx, dy);
    }
  }

  void Menu::attach(Window& win)
  {
    for (int i = 0; i < selection.size(); ++i) win.attach(selection[i]);
    {
      {
        own = &win;
      }
    }
  }
}
