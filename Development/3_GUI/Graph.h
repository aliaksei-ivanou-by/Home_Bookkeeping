#pragma once

#include "Point.h"
#include "../include/stdafx.h"
#include "../include/FLTK.h"

namespace Graph_lib
{
#undef major
#undef minor
	struct Color
	{
		enum Color_type : unsigned char
		{
			red = FL_RED,
			blue = FL_BLUE,
			green = FL_GREEN,
			yellow = FL_YELLOW,
			white = FL_WHITE,
			black = FL_BLACK,
			magenta = FL_MAGENTA,
			cyan = FL_CYAN,
			dark_red = FL_DARK_RED,
			dark_green = FL_DARK_GREEN,
			dark_yellow = FL_DARK_YELLOW,
			dark_blue = FL_DARK_BLUE,
			dark_magenta = FL_DARK_MAGENTA,
			dark_cyan = FL_DARK_CYAN
		};
		enum Transparency : unsigned char
		{
			invisible = 0,
			visible = 255
		};
		Color(Color_type cc);
		Color(Color_type cc, Transparency vv);
		Color(int cc);
		Color(Transparency vv);
		int as_int() const;
		char visibility() const;
		void set_visibility(Transparency vv);
	private:
		unsigned char v;
		Fl_Color c;
	};

	struct Line_style
	{
		enum Line_style_type
		{
			solid = FL_SOLID, // -------
			dash = FL_DASH, // - - - -
			dot = FL_DOT, // ....... 
			dashdot = FL_DASHDOT, // - . - . 
			dashdotdot = FL_DASHDOTDOT, // -..-..
		};
		Line_style(Line_style_type ss);
		Line_style(Line_style_type lst, int ww);
		Line_style(int ss);
		int width() const;
		int style() const;
	private:
		int s;
		int w;
	};

	class Font
	{
	public:
		enum Font_type
		{
			helvetica = FL_HELVETICA,
			helvetica_bold = FL_HELVETICA_BOLD,
			helvetica_italic = FL_HELVETICA_ITALIC,
			helvetica_bold_italic = FL_HELVETICA_BOLD_ITALIC,
			courier = FL_COURIER,
			courier_bold = FL_COURIER_BOLD,
			courier_italic = FL_COURIER_ITALIC,
			courier_bold_italic = FL_COURIER_BOLD_ITALIC,
			times = FL_TIMES,
			times_bold = FL_TIMES_BOLD,
			times_italic = FL_TIMES_ITALIC,
			times_bold_italic = FL_TIMES_BOLD_ITALIC,
			symbol = FL_SYMBOL,
			screen = FL_SCREEN,
			screen_bold = FL_SCREEN_BOLD,
			zapf_dingbats = FL_ZAPF_DINGBATS
		};
		Font(Font_type ff);
		Font(int ff);
		int as_int() const;
	private:
		int f;
	};
	
	template<class T> class Vector_ref
	{
		std::vector<T*> v;
		std::vector<T*> owned;
	public:
		Vector_ref()
		{}
		Vector_ref(T& a)
		{
			push_back(a);
		}
		Vector_ref(T& a, T& b);
		Vector_ref(T& a, T& b, T& c);
		Vector_ref(T* a, T* b = 0, T* c = 0, T* d = 0)
		{
			if (a)
			{
				push_back(a);
			}
			if (b)
			{
				push_back(b);
			}
			if (c)
			{
				push_back(c);
			}
			if (d)
			{
				push_back(d);
			}
		}
		~Vector_ref()
		{
			for (int i = 0; i < owned.size(); ++i)
			{
				delete owned[i];
			}
		}
		void clear()
		{
			v.clear();
		}
		void push_back(T& s)
		{
			v.push_back(&s);
		}
		void push_back(T* p)
		{
			v.push_back(p);
			owned.push_back(p);
		}
		T& operator[](int i)
		{
			return *v[i];
		}
		const T& operator[](int i) const
		{
			return *v[i];
		}
		int size() const
		{
			return v.size();
		}
	private:
		Vector_ref(const std::vector<T>&);
		Vector_ref& operator=(const std::vector<T>&);
	};

	typedef double Fct(double);
	
	class Shape
	{
	public:
		void draw() const;
		virtual void move(int dx, int dy);
		void set_color(Color col);
		Color color() const;
		void set_style(Line_style sty);
		Line_style style() const;
		void set_fill_color(Color col);
		Color fill_color() const;
		Point point(int i) const;
		int number_of_points() const;
		virtual ~Shape();
	protected:
		Shape();
		virtual void draw_lines() const;
		void add(Point p);
		void set_point(int i, Point p);
		void clear_points();
	private:
		std::vector<Point> points;
		Color lcolor;
		Line_style ls;
		Color fcolor;
		Shape(const Shape&);
		// Shape& operator=(const Shape&);
	};
	
	struct Function : Shape
	{
		Function(Fct f, double r1, double r2, Point orig,
			int count = 100, double xscale = 25, double yscale = 25);
	};
	struct Line : Shape
	{
		Line(Point p1, Point p2);
	};

	struct Lines : Shape
	{
		void draw_lines() const;
		void add(Point p1, Point p2);
	};
	
	struct Rectangle : Shape
	{
		Rectangle(Point xy, int ww, int hh);
		Rectangle(Point x, Point y);
		void draw_lines() const;
		int height() const;
		int width() const;
	private:
		int h;
		int w;
	};

	struct Open_polyline : Shape
	{
		void add(Point p);
		void draw_lines() const;
	};

	struct Closed_polyline : Open_polyline
	{
		void draw_lines() const;
	};

	struct Polygon : Closed_polyline
	{
		void add(Point p);
		void draw_lines() const;
	};
	
	struct Text : Shape
	{
		Text(Point x, const std::string& s);
		void draw_lines() const;
		void set_label(const std::string& s);
		std::string label() const;
		void set_font(Font f);
		Font font() const;
		void set_font_size(int s);
		int font_size() const;
	private:
		std::string lab;
		Font fnt;
		int fnt_sz;
	};

	struct Axis : Shape
	{
		enum Orientation
		{
			x,
			y,
			z
		};
		Axis(Orientation d, Point xy, int length,
			int number_of_notches = 0, std::string label = "");
		void draw_lines() const;
		void move(int dx, int dy);
		void set_color(Color c);
		Text label;
		Lines notches;
	};
	
	struct Circle : Shape
	{
		Circle(Point p, int rr);
		void draw_lines() const;
		Point center() const;
		void set_radius(int rr);
		int radius() const;
	private:
		int r;
	};

	struct Ellipse : Shape
	{
		Ellipse(Point p, int ww, int hh);
		void draw_lines() const;
		Point center() const;
		Point focus1() const;
		Point focus2() const;
		void set_major(int ww);
		int major() const;
		void set_minor(int hh);
		int minor() const;
	private:
		int w;
		int h;
	};

	struct Marked_polyline : Open_polyline
	{
		Marked_polyline(const std::string& m);
		void draw_lines() const;
	private:
		std::string mark;
	};

	struct Marks : Marked_polyline
	{
		Marks(const std::string& m);
	};

	struct Mark : Marks
	{
		Mark(Point xy, char c);
	};

	struct Suffix
	{
		enum Encoding
		{
			none,
			jpg,
			gif
		};
	};

	Suffix::Encoding get_encoding(const std::string& s);

	struct Image : Shape
	{
		Image(Point xy, std::string file_name, Suffix::Encoding e = Suffix::none);
		~Image();
		void draw_lines() const;
		void set_mask(Point xy, int ww, int hh);
	private:
		int w, h;
		int cx, cy;
		Fl_Image* p;
		Text fn;
	};
	
	struct Bad_image : Fl_Image
	{
		Bad_image(int h, int w);
		void draw(int x, int y, int, int, int, int);
	};
}