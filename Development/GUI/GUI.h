#pragma once

#include "Window.h"
#include "Graph.h"

namespace Graph_lib
{
	typedef void* Address;
	typedef void(*Callback)(Address, Address);
	template<class W> W& reference_to(Address pw)
	{
		return *static_cast<W*>(pw);
	}
	class Widget
	{
	public:
		Widget(Point xy, int w, int h, const std::string& s, Callback cb);
		virtual void move(int dx, int dy);
		virtual void hide();
		virtual void show();
		virtual void attach(Window&) = 0;
		Point loc;
		int width;
		int height;
		std::string label;
		Callback do_it;
		virtual ~Widget()
		{}
	protected:
		Window* own;
		Fl_Widget* pw;
	private:
		// Widget& operator=(const Widget&);
		Widget(const Widget&);
	};

	struct Button : Widget
	{
		Button(Point xy, int w, int h, const std::string& label, Callback cb);
		void attach(Window&);
	};

	struct In_box : Widget
	{
		In_box(Point xy, int w, int h, const std::string& s);
		int get_int();
		std::string get_string();
		void attach(Window& win);
	};

	struct Out_box : Widget
	{
		Out_box(Point xy, int w, int h, const std::string& s);
		// void put(int);
		void put(const std::string&);
		void attach(Window& win);
	};

	struct Menu : Widget
	{
		enum Kind
		{
			horizontal, vertical
		};
		Menu(Point xy, int w, int h, Kind kk, const std::string& label);
		Vector_ref<Button> selection;
		Kind k;
		int offset;
		int attach(Button& b);
		int attach(Button* p);
		void show();
		void hide();
		void move(int dx, int dy);
		void attach(Window& win);
	};
}