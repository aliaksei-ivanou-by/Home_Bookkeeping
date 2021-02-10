#include "../include/stdafx.h"
#include "../include/FLTK.h"
#include "Graph.h"

namespace Graph_lib
{
	inline std::pair<double, double> line_intersect(
		Point p1, Point p2, Point p3, Point p4, bool& parallel)
	{
		double x1 = p1.x;
		double x2 = p2.x;
		double x3 = p3.x;
		double x4 = p4.x;
		double y1 = p1.y;
		double y2 = p2.y;
		double y3 = p3.y;
		double y4 = p4.y;
		double denom = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
		if (denom == 0)
		{
			parallel = true;
			return std::pair<double, double>(0, 0);
		}
		parallel = false;
		return std::pair<double, double>(((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom,
			((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom);
	}

	bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection)
	{
		bool parallel;
		std::pair<double, double> u = line_intersect(p1, p2, p3, p4, parallel);
		if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1)
		{
			return false;
		}
		intersection.x = p1.x + u.first * (p2.x - p1.x);
		intersection.y = p1.y + u.first * (p2.y - p1.y);
		return true;
	}

	void draw_mark(Point xy, char c)
	{
		static const int dx = 4;
		static const int dy = 4;

		std::string m(1, c);
		fl_draw(m.c_str(), xy.x - dx, xy.y + dy);
	}

	Color::Color(Color_type cc):
		v(Color::Transparency::visible),
		c(Fl_Color(cc))
	{}

	Color::Color(Color_type cc, Transparency vv):
		v(vv),
		c(Fl_Color(cc))
	{}

	Color::Color(int cc):
		v(Color::Transparency::visible),
		c(Fl_Color(cc))
	{}

	Color::Color(Transparency vv):
		v(vv),
		c(Fl_Color())
	{}

	int Color::as_int() const
	{
		return c;
	}

	char Color::visibility() const
	{
		return v;
	}

	void Color::set_visibility(Transparency vv)
	{
		v = vv;
	}

	Line_style::Line_style(Line_style_type ss):
		s(ss),
		w(0)
	{}

	Line_style::Line_style(Line_style_type lst, int ww):
		s(lst),
		w(ww)
	{}

	Line_style::Line_style(int ss):
		s(ss),
		w(0)
	{}

	int Line_style::width() const
	{
		return w;
	}

	int Line_style::style() const
	{
		return s;
	}

	Font::Font(Font_type ff):
		f(ff)
	{}

	Font::Font(int ff):
		f(ff)
	{}

	int Font::as_int() const
	{
		return f;
	}

	Shape::Shape():
		lcolor(fl_color()),
		ls(0),
		fcolor(Color::invisible)
	{}

	void Shape::add(Point p)
	{
		points.push_back(p);
	}

	void Shape::set_point(int i, Point p)
	{
		points[i] = p;
	}

	void Shape::clear_points()
	{
		points.clear();
	}

	void Shape::set_color(Color col)
	{
		lcolor = col;
	}

	Color Shape::color() const
	{
		return lcolor;
	}

	void Shape::set_style(Line_style sty)
	{
		ls = sty;
	}

	Line_style Shape::style() const
	{
		return ls;
	}

	void Shape::set_fill_color(Color col)
	{
		fcolor = col;
	}

	Color Shape::fill_color() const
	{
		return fcolor;
	}

	Shape::~Shape()
	{}

	int Shape::number_of_points() const
	{
		return int(points.size());
	}

	Point Shape::point(int i) const
	{
		return points[i];
	}

	void Shape::draw_lines() const
	{
		if (color().visibility() && 1 < points.size())
		{
			for (unsigned int i = 1; i < points.size(); ++i)
			{
				fl_line(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);
			}
		}
	}
	
	void Shape::draw() const
	{
		Fl_Color oldc = fl_color();
		fl_color(lcolor.as_int());
		fl_line_style(ls.style(), ls.width());
		draw_lines();
		fl_color(oldc);
		fl_line_style(0);
	}

	void Shape::move(int dx, int dy)
	{
		for (int i = 0; i < points.size(); ++i)
		{
			points[i].x += dx;
			points[i].y += dy;
		}
	}
	
	Function::Function(Fct f, double r1, double r2, Point xy,
		int count, double xscale, double yscale)
	{
		if (r2 - r1 <= 0)
		{
			throw("bad graphing range");
		}
		if (count <= 0)
		{
			throw("non-positive graphing count");
		}
		double dist = (r2 - r1) / count;
		double r = r1;
		for (int i = 0; i < count; ++i)
		{
			add(Point(xy.x + int(r * xscale), xy.y - int(f(r) * yscale)));
			r += dist;
		}
	}

	Line::Line(Point p1, Point p2)
	{
		add(p1);
		add(p2);
	}

	void Lines::add(Point p1, Point p2)
	{
		Shape::add(p1);
		Shape::add(p2);
	}
	
	void Lines::draw_lines() const
	{
		if (color().visibility())
		{
			for (int i = 1; i < number_of_points(); i += 2)
			{
				fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
			}
		}
	}
	
	Rectangle::Rectangle(Point xy, int ww, int hh):
		h(hh),
		w(ww)
	{
		add(xy);
		if (h <= 0 || w <= 0)
		{
			throw("Bad rectangle: non-positive side");
		}
	}

	Rectangle::Rectangle(Point x, Point y):
		h(y.y - x.y),
		w(y.x - x.x)
	{
		add(x);
		if (h <= 0 || w <= 0)
		{
			throw("Bad rectangle: non-positive width or height");
		}
	}

	void Rectangle::draw_lines() const
	{
		if (fill_color().visibility())
		{
			fl_color(fill_color().as_int());
			fl_rectf(point(0).x, point(0).y, w, h);
			fl_color(color().as_int());
		}
		if (color().visibility())
		{
			fl_color(color().as_int());
			fl_rect(point(0).x, point(0).y, w, h);
		}
	}

	int Rectangle::height() const
	{
		return h;
	}
	int Rectangle::width() const
	{
		return w;
	}

	void Open_polyline::add(Point p)
	{
		Shape::add(p);
	}

	void Open_polyline::draw_lines() const
	{
		if (fill_color().visibility())
		{
			fl_color(fill_color().as_int());
			fl_begin_complex_polygon();
			for (int i = 0; i < number_of_points(); ++i)
			{
				fl_vertex(point(i).x, point(i).y);
			}
			fl_end_complex_polygon();
			fl_color(color().as_int());
		}
		if (color().visibility())
		{
			Shape::draw_lines();
		}
	}

	void Closed_polyline::draw_lines() const
	{
		Open_polyline::draw_lines();
		if (color().visibility())
		{
			fl_line(point(number_of_points() - 1).x,
				point(number_of_points() - 1).y,
				point(0).x,
				point(0).y);
		}
	}

	void Polygon::add(Point p)
	{
		int np = number_of_points();
		if (1 < np)
		{
			if (p == point(np - 1))
			{
				throw("polygon point equal to previous point");
			}
			bool parallel;
			line_intersect(point(np - 1), p, point(np - 2), point(np - 1), parallel);
			if (parallel)
			{
				throw("two polygon points lie in a straight line");
			}
		}
		for (int i = 1; i < np - 1; ++i)
		{
			Point ignore(0, 0);
			if (line_segment_intersect(point(np - 1), p, point(i - 1), point(i), ignore))
			{
				throw("intersect in polygon");
			}
		}
		Closed_polyline::add(p);
	}

	void Polygon::draw_lines() const
	{
		if (number_of_points() < 3)
		{
			throw("less than 3 points in a Polygon");
		}
		Closed_polyline::draw_lines();
	}

	Text::Text(Point x, const std::string& s):
		lab(s),
		fnt(fl_font()),
		fnt_sz{ (fl_size() < 14) ? 14 : fl_size() }
	{
		add(x);
	}

	void Text::draw_lines() const
	{
		int ofnt = fl_font();
		int osz = fl_size();
		fl_font(fnt.as_int(), fnt_sz);
		fl_draw(lab.c_str(), point(0).x, point(0).y);
		fl_font(ofnt, osz);
	}

	void Text::set_label(const std::string& s)
	{
		lab = s;
	}

	std::string Text::label() const
	{
		return lab;
	}

	void Text::set_font(Font f)
	{
		fnt = f;
	}

	Font Text::font() const
	{
		return Font(fnt);
	}

	void Text::set_font_size(int s)
	{
		fnt_sz = s;
	}

	int Text::font_size() const
	{
		return fnt_sz;
	}

	Axis::Axis(Orientation d, Point xy, int length, int n, std::string lab):
		label(Point(0, 0), lab)
	{
		if (length < 0)
		{
			throw("bad axis length");
		}
		switch (d)
		{
		case Axis::x:
		{
			Shape::add(xy);
			Shape::add(Point(xy.x + length, xy.y));
			if (0 < n)
			{
				int dist = length / n;
				int x = xy.x + dist;
				for (int i = 0; i < n; ++i)
				{
					notches.add(Point(x, xy.y), Point(x, xy.y - 5));
					x += dist;
				}
			}
			label.move(xy.x + length / 3, xy.y + 20);
			break;
		}
		case Axis::y:
		{
			Shape::add(xy);
			Shape::add(Point(xy.x, xy.y - length));
			if (0 < n)
			{
				int dist = length / n;
				int y = xy.y - dist;
				for (int i = 0; i < n; ++i)
				{
					notches.add(Point(xy.x, y), Point(xy.x + 5, y));
					y -= dist;
				}
			}
			label.move(xy.x - 10, xy.y - length - 10);
			break;
		}
		case Axis::z:
		{
			throw("z axis not implemented");
		}
		}
	}

	void Axis::draw_lines() const
	{
		Shape::draw_lines();
		notches.draw();
		label.draw();
	}

	void Axis::move(int dx, int dy)
	{
		Shape::move(dx, dy);
		notches.move(dx, dy);
		label.move(dx, dy);
	}

	void Axis::set_color(Color c)
	{
		Shape::set_color(c);
		notches.set_color(c);
		label.set_color(c);
	}

	Circle::Circle(Point p, int rr):
		r(rr)
	{
		add(Point(p.x - r, p.y - r));
	}

	void Circle::draw_lines() const
	{
		if (fill_color().visibility())
		{
			fl_color(fill_color().as_int());
			fl_pie(point(0).x, point(0).y, r + r - 1, r + r - 1, 0, 360);
			fl_color(color().as_int());
		}
		if (color().visibility())
		{
			fl_color(color().as_int());
			fl_arc(point(0).x, point(0).y, r + r, r + r, 0, 360);
		}
	}

	Point Circle::center() const
	{
		return Point(point(0).x + r, point(0).y + r);
	}

	void Circle::set_radius(int rr)
	{
		set_point(0, Point(center().x - rr, center().y - rr));
		r = rr;
	}
	int Circle::radius() const
	{
		return r;
	}

	Ellipse::Ellipse(Point p, int ww, int hh):
		w(ww),
		h(hh)
	{
		add(Point(p.x - ww, p.y - hh));
	}

	void Ellipse::draw_lines() const
	{
		if (fill_color().visibility())
		{
			fl_color(fill_color().as_int());
			fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, 0, 360);
			fl_color(color().as_int());
		}
		if (color().visibility())
		{
			fl_color(color().as_int());
			fl_arc(point(0).x, point(0).y, w + w, h + h, 0, 360);
		}
	}

	Point Ellipse::center() const
	{
		return Point(point(0).x + w, point(0).y + h);
	}

	Point Ellipse::focus1() const
	{
		if (h <= w)
		{
			return Point(center().x + int(sqrt(double(w * w - h * h))), center().y);
		}
		else
		{
			return Point(center().x, center().y + int(sqrt(double(h * h - w * w))));
		}
	}

	Point Ellipse::focus2() const
	{
		if (h <= w)
		{
			return Point(center().x - int(sqrt(double(w * w - h * h))), center().y);
		}
		else
		{
			return Point(center().x, center().y - int(sqrt(double(h * h - w * w))));
		}
	}

	void Ellipse::set_major(int ww)
	{
		set_point(0, Point(center().x - ww, center().y - h));
		w = ww;
	}

	int Ellipse::major() const
	{
		return w;
	}
	void Ellipse::set_minor(int hh)
	{
		set_point(0, Point(center().x - w, center().y - hh));
		h = hh;
	}

	int Ellipse::minor() const
	{
		return h;
	}

	Marked_polyline::Marked_polyline(const std::string& m):
		mark(m)
	{}

	void Marked_polyline::draw_lines() const
	{
		Open_polyline::draw_lines();
		for (int i = 0; i < number_of_points(); ++i)
		{
			draw_mark(point(i), mark[i % mark.size()]);
		}
	}

	Marks::Marks(const std::string& m):
		Marked_polyline(m)
	{
		set_color(Color(Color::invisible));
	}

	Mark::Mark(Point xy, char c):
		Marks(std::string(1, c))
	{
		add(xy);
	}

	bool can_open(const std::string& s)
	{
		std::ifstream ff(s.c_str());
		return bool(ff);
	}

#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))

	Suffix::Encoding get_encoding(const std::string& s)
	{
		struct SuffixMap
		{
			const char* extension;
			Suffix::Encoding suffix;
		};
		static SuffixMap smap[] =
		{
			{".jpg",  Suffix::jpg},
			{".jpeg", Suffix::jpg},
			{".gif",  Suffix::gif},
		};
		for (int i = 0, n = ARRAY_SIZE(smap); i < n; i++)
		{
			int len = strlen(smap[i].extension);
			if (s.length() >= len && s.substr(s.length() - len, len) == smap[i].extension)
			{
				return smap[i].suffix;
			}
		}
		return Suffix::none;
	}

	Bad_image::Bad_image(int h, int w):
		Fl_Image(h, w, 0)
	{}

	void Bad_image::draw(int x, int y, int, int, int, int)
	{
		draw_empty(x, y);
	}

	Image::Image(Point xy, std::string s, Suffix::Encoding e):
		w(0),
		h(0),
		fn(xy, "")
	{
		add(xy);
		if (!can_open(s))
		{
			fn.set_label("cannot open \"" + s + '\"');
			p = new Bad_image(30, 20);
			return;
		}
		if (e == Suffix::none)
		{
			e = get_encoding(s);
		}
		switch (e)
		{
		case Suffix::jpg:
		{
			p = new Fl_JPEG_Image(s.c_str());
			break;
		}
		case Suffix::gif:
		{
			p = new Fl_GIF_Image(s.c_str());
			break;
		}
		default:
		{
			fn.set_label("unsupported file type \"" + s + '\"');
			p = new Bad_image(30, 20);
		}
		}
	}

	Image::~Image()
	{
		delete p;
	}

	void Image::draw_lines() const
	{
		if (fn.label() != "")
		{
			fn.draw_lines();
		}
		if (w && h)
		{
			p->draw(point(0).x, point(0).y, w, h, cx, cy);
		}
		else
		{
			p->draw(point(0).x, point(0).y);
		}
	}

	void Image::set_mask(Point xy, int ww, int hh)
	{
		w = ww;
		h = hh;
		cx = xy.x;
		cy = xy.y;
	}
}
