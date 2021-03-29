#include "home_bookkeeping/lib/graph/Window.h"
#include "home_bookkeeping/lib/graph/GUI.h"

namespace Graph_lib
{
  Window::Window(int ww, int hh, const std::string& title):
    Fl_Window{ ww, hh, title.c_str() },
    w{ ww },
    h{ hh }
  {
    init();
  }

  Window::Window(Point xy, int ww, int hh, const std::string& title):
    Fl_Window{ xy.x, xy.y, ww, hh, title.c_str() },
    w{ ww },
    h{ hh }
  {
    init();
  }

  void Window::init()
  {
    resizable(this);
    show();
  }

  Window::~Window()
  {}

  int Window::x_max() const
  {
    return w;
  }
  int Window::y_max() const
  {
    return h;
  }

  void Window::set_label(const std::string& s)
  {
    copy_label(s.c_str());
  }

  void Window::resize(int ww, int hh)
  {
    w = ww;
    h = hh;
    size(ww, hh);
  }

  void Window::attach(Shape& s)
  {
    shapes.push_back(&s);
  }

  void Window::attach(Widget& w)
  {
    begin();
    w.attach(*this);
    end();
  }

  void Window::detach(Widget& b)
  {
    b.hide();
  }

  void Window::detach(Shape& s)
  {
    for (std::vector<Shape*>::size_type i = shapes.size(); 0 < i; --i)
    {
      if (shapes[i - 1] == &s)
      {
        shapes.erase(shapes.begin() + (i - 1));
      }
    }
  }

  void Window::put_on_top(Shape& p)
  {
    for (int i = 0; i < shapes.size(); ++i)
    {
      if (&p == shapes[i])
      {
        for (++i; i < shapes.size(); ++i)
        {
          shapes[i - 1] = shapes[i];
        }
        shapes[shapes.size() - 1] = &p;
        return;
      }
    }
  }

  void Window::draw()
  {
    Fl_Window::draw();
    for (unsigned int i = 0; i < shapes.size(); ++i)
    {
      shapes[i]->draw();
    }
  }

  int gui_main()
  {
    return Fl::run();
  }

  int x_max()
  {
    return Fl::w();
  }
  int y_max()
  {
    return Fl::h();
  }
}
