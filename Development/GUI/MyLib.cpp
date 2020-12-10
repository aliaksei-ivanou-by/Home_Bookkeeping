#include "../include/stdafx.h"
#include "../include/FLTK.h"
#include "../include/Graphics.h"
#include "MyLib.h"
#include "../include/constants.h"

inline int randint(int max)
{
	return rand() % max;
}

inline int randint(int min, int max)
{
	return randint(max - min) + min;
}

namespace Graph_lib
{
	Arc::Arc(Point center, int width, int height, double start, double end):
		width{ width },
		height{ height },
		start{ start },
		end{ end }
	{
		add(center);
	}

	void Arc::draw_lines() const
	{
		if (color().visibility())
		{
			fl_arc(point(0).x - width / 2, point(0).y, width, height, start, end);
		}
	}
	Box::Box()
	{}
	
	Box::Box(Point p, int ww, int hh):
		w{ ww },
		h{ hh }
	{
		add(p);
		double wp = (double(w) / 100) * 10;
		double hp = (double(h) / 100) * 10;
		// Top
		add(Point(p.x + wp, p.y));
		add(Point((p.x + w) - wp, p.y));
		// Right
		add(Point(p.x + w, p.y + hp));
		add(Point(p.x + w, (p.y + h) - hp));
		// Bottom
		add(Point(p.x + wp, p.y + h));
		add(Point((p.x + w) - wp, p.y + h));
		// Left
		add(Point(p.x, p.y + hp));
		add(Point(p.x, (p.y + h) - hp));
	}

	void Box::draw_lines() const
	{
		for (int i = 2; i < number_of_points(); i += 2)
		{
			fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
		}
		double we = ((double(w) / 100) * 10) * 2;
		double he = ((double(h) / 100) * 10) * 2;
		fl_arc(point(0).x, point(0).y, we, he, 90, 180);
		fl_arc((point(0).x + w) - we, point(0).y, we, he, 0, 90);
		fl_arc((point(0).x + w) - we, (point(0).y + h) - he, we, he, 270, 360);
		fl_arc(point(0).x, (point(0).y + h) - he, we, he, 180, 270);
	}

	Arrow::Arrow(Point tail, Point tip)
	{
		add(tail);
		add(tip);
	}

	Arrow::Arrow(Point tail, Point tip, Color line_color)
	{
		add(tail);
		add(tip);
		set_color(line_color);
	}

	void Arrow::draw_lines() const
	{
		int diff_x = point(1).x - point(0).x;
		int diff_y = point(1).y - point(0).y;
		double angle = atan2(diff_y, diff_x) * 180 / PI();
		double x1 = point(1).x - cos((angle - delta) * PI() / 180) * size;
		double y1 = point(1).y - sin((angle - delta) * PI() / 180) * size;
		double x2 = point(1).x - cos((angle + delta) * PI() / 180) * size;
		double y2 = point(1).y - sin((angle + delta) * PI() / 180) * size;
		Graph_lib::Polygon head;
		head.add(point(1));
		head.add(Point(int(x1), int(y1)));
		head.add(Point(int(x2), int(y2)));
		head.set_fill_color(color());
		head.draw_lines();
		Shape::draw_lines();
	}

	void Arrow::set_size(int s)
	{
		size = s;
	}

	Point Graph_lib::n(const Graph_lib::Rectangle& r) // top
	{
		return Point(r.point(0).x + r.width() / 2,
			r.point(0).y);
	}

	Point Graph_lib::s(const Graph_lib::Rectangle& r) // bottom
	{
		return Point(r.point(0).x + r.width() / 2,
			r.point(0).y + r.height());
	}

	Point Graph_lib::e(const Graph_lib::Rectangle& r) // right
	{
		return Point(r.point(0).x + r.width(),
			r.point(0).y + r.height() / 2);
	}

	Point Graph_lib::w(const Graph_lib::Rectangle& r) // left
	{
		return Point(r.point(0).x,
			r.point(0).y + r.height() / 2);
	}

	Point Graph_lib::center(const Graph_lib::Rectangle& r) // center
	{
		return Point(r.point(0).x + r.width() / 2,
			r.point(0).y + r.height() / 2);
	}
	Point Graph_lib::ne(const Graph_lib::Rectangle& r) // top-right
	{
		return Point(r.point(0).x + r.width(),
			r.point(0).y);
	}

	Point Graph_lib::se(const Graph_lib::Rectangle& r) // bottom-right
	{
		return Point(r.point(0).x + r.width(),
			r.point(0).y + r.height());
	}

	Point Graph_lib::sw(const Graph_lib::Rectangle& r) // bottom-left
	{
		return Point(r.point(0).x,
			r.point(0).y + r.height());
	}

	Point Graph_lib::nw(const Graph_lib::Rectangle& r) // top-left
	{
		return Point(r.point(0).x,
			r.point(0).y);
	}

	Point Graph_lib::n(const Graph_lib::Circle& c) // top
	{
		return Point(c.point(0).x + c.radius(),
			c.point(0).y);
	}

	Point Graph_lib::s(const Graph_lib::Circle& c) // bottom
	{
		return Point(c.point(0).x + c.radius(),
			c.point(0).y + c.radius() * 2);
	}

	Point Graph_lib::e(const Graph_lib::Circle& c) // right
	{
		return Point(c.point(0).x + c.radius() * 2,
			c.point(0).y + c.radius());
	}

	Point Graph_lib::w(const Graph_lib::Circle& c) // left
	{
		return Point(c.point(0).x,
			c.point(0).y + c.radius());
	}

	Point Graph_lib::center(const Graph_lib::Circle& c) // center
	{
		return c.center();
	}
	Point Graph_lib::ne(const Graph_lib::Circle& c) // top-right
	{
		return Point(c.center().x + c.radius() * cos(315 * PI() / 180),
			c.center().y + c.radius() * sin(315 * PI() / 180));
	}

	Point Graph_lib::se(const Graph_lib::Circle& c) // bottom-right
	{
		return Point(c.center().x + c.radius() * cos(45 * PI() / 180),
			c.center().y + c.radius() * sin(45 * PI() / 180));
	}

	Point Graph_lib::sw(const Graph_lib::Circle& c) // bottom-left
	{
		return Point(c.center().x + c.radius() * cos(135 * PI() / 180),
			c.center().y + c.radius() * sin(135 * PI() / 180));
	}

	Point Graph_lib::nw(const Graph_lib::Circle& c) // top-left
	{
		return Point(c.center().x + c.radius() * cos(225 * PI() / 180),
			c.center().y + c.radius() * sin(225 * PI() / 180));
	}

	Point Graph_lib::n(const Graph_lib::Ellipse& e) // top
	{
		return Point(e.point(0).x + e.major(),
			e.point(0).y);
	}

	Point Graph_lib::s(const Graph_lib::Ellipse& e) // bottom
	{
		return Point(e.point(0).x + e.major(),
			e.point(0).y + e.minor() * 2);
	}

	Point Graph_lib::e(const Graph_lib::Ellipse& e) // right
	{
		return Point(e.point(0).x + e.major() * 2,
			e.point(0).y + e.minor());
	}

	Point Graph_lib::w(const Graph_lib::Ellipse& e) // left
	{
		return Point(e.point(0).x,
			e.point(0).y + e.minor());
	}

	Point Graph_lib::center(const Graph_lib::Ellipse& e) // center
	{
		return e.center();
	}
	Point Graph_lib::ne(const Graph_lib::Ellipse& e) // top-right
	{
		return Point(e.center().x + e.major() * cos((-45) * PI() / 180),
			e.center().y + e.minor() * sin((-45) * PI() / 180));
	}

	Point Graph_lib::se(const Graph_lib::Ellipse& e) // bottom-right
	{
		return Point(e.center().x + e.major() * cos(45 * PI() / 180),
			e.center().y + e.minor() * sin(45 * PI() / 180));
	}

	Point Graph_lib::sw(const Graph_lib::Ellipse& e) // bottom-left
	{
		return Point(e.center().x + e.major() * cos(135 * PI() / 180),
			e.center().y + e.minor() * sin(135 * PI() / 180));
	}

	Point Graph_lib::nw(const Graph_lib::Ellipse& e) // top-left
	{
		return Point(e.center().x + e.major() * cos(225 * PI() / 180),
			e.center().y + e.minor() * sin(225 * PI() / 180));
	}

	Box_text::Box_text(Point p, std::string ss)
		: Rectangle(p, ss.length() * 10, 40), text(Point(p.x + 5, p.y + 30), ss)
	{
		add(p);
		set_color(Color::black);
	}

	Box_text::Box_text(Point p, std::string ss, int ww, int hh)
		: Rectangle(p, ww, hh), text(Point(p.x + 5, p.y + hh/2), ss)
	{
		add(p);
		set_color(Color::black);
	}

	void Box_text::draw_lines() const
	{
		Rectangle::draw_lines();
		text.draw_lines();
	}

	Regular_hexagon::Regular_hexagon(Point cc, int dd):
		c{ cc },
		d{ dd }
	{
		add(Point(cc.x + dd, cc.y));
		for (int a = 360 / n; a < 360; a += 360 / n)
		{
			Point p((point(0).x - c.x) * cos(a * PI() / 180) - (point(0).y - c.y) * sin(a * PI() / 180) + c.x,
				(point(0).y - c.y) * cos(a * PI() / 180) + (point(0).x - c.x) * sin(a * PI() / 180) + c.y);
			add(p);
		}
	}

	Regular_polygon::Regular_polygon(Point cc, int nn, int dd):
		c{ cc },
		n{ nn },
		d{ dd }
	{
		if (n < 3)
		{
			throw("The figure must have at least 3 sides");
		}
		add(Point(cc.x + dd, cc.y));
		for (int a = 360 / n; a < 360; a += 360 / n)
		{
			Point p((point(0).x - c.x) * cos(a * PI() / 180) - (point(0).y - c.y) * sin(a * PI() / 180) + c.x,
				(point(0).y - c.y) * cos(a * PI() / 180) + (point(0).x - c.x) * sin(a * PI() / 180) + c.y);
			add(p);
		}
	}

	Right_triangle::Right_triangle(Point p, int s1, int s2, double a):
		side1{ s1 },
		side2{ s2 },
		angle{ a },
		alpha{ 90 - a }
	{
		add(p);

		int x = p.x + cos(angle * PI() / 180) * side1;
		int y = p.y - sin(angle * PI() / 180) * side1;
		add(Point(x, y));

		x = p.x - cos(alpha * PI() / 180) * side2;
		y = p.y - sin(alpha * PI() / 180) * side2;
		add(Point(x, y));
	}

	Poly::Poly(std::vector<Point> v_p)
	{
		for (int i = 0; i < v_p.size(); ++i)
		{
			add(v_p[i]);
		}
	}

	void Poly::add(Point p)
	{
		Polygon::add(p);
	}

	void Poly::draw_lines() const
	{
		Polygon::draw_lines();
	}

	Star::Star(Point cc, int nn, int rr):
		c{ cc },
		n{ nn },
		r{ rr }
	{
		add(Point(c.x, c.y - r));
		add(find_distance(
			Point((point(0).x - c.x)* cos((r* PI() / 180)) - (point(0).y - c.y) * sin((r * PI() / 180)) + c.x,
				(point(0).y - c.y)* cos((r* PI() / 180)) + (point(0).x - c.x) * sin((r * PI() / 180)) + c.y),
			c, r));
		for (int a = 360 / n; a < 360; a += 360 / n)
		{
			add(Point((point(0).x - c.x) * cos((a * PI() / 180)) - (point(0).y - c.y) * sin((a * PI() / 180)) + c.x,
				(point(0).y - c.y) * cos((a * PI() / 180)) + (point(0).x - c.x) * sin((a * PI() / 180)) + c.y));
			Point rp((point(number_of_points() - 1).x - c.x) * cos((180 / n * PI() / 180)) - (point(number_of_points() - 1).y - c.y) * sin((180 / n * PI() / 180)) + c.x,
				(point(number_of_points() - 1).y - c.y) * cos((180 / n * PI() / 180)) + (point(number_of_points() - 1).x - c.x) * sin((180 / n * PI() / 180)) + c.y);
			add(find_distance(rp, c, r));
		}
	}

	Point Star::find_distance(Point p1, Point p2, int d)
	{
		double dx = p1.x - p2.x;
		double dy = p1.y - p2.y;
		double delta = sqrt(dx * dx + dy * dy);
		return Point(int(double(p1.x) + (dx / delta) * (delta + double(d))),
			int(double(p1.y) + (dy / delta) * (delta + double(d))));
	}

	Frowny::Frowny(Point p, int rr):
		Circle(p, rr),
		eye_L(Point(p.x - rr / 5, p.y - rr / 2), rr / 10, rr / 5),
		eye_R(Point(p.x + rr / 5, p.y - rr / 2), rr / 10, rr / 5),
		mouth(p, rr / 2, rr / 2, 0, 180)
	{
		eye_L.set_color(Color::dark_red);
		eye_L.set_fill_color(Color::red);
		eye_R.set_color(Color::dark_red);
		eye_R.set_fill_color(Color::red);
		mouth.set_color(Color::dark_red);
	}

	void Frowny::draw_lines() const
	{
		Circle::draw_lines();
		eye_L.draw();
		eye_R.draw();
		mouth.draw();
	}

	Frowny_Hat::Frowny_Hat(Point p, int rr):
		Frowny(p, rr)
	{
		hat.add(Point(p.x - 0.7 * rr, p.y - 0.7 * rr));
		hat.add(Point(p.x - 0.8 * rr, p.y - 0.9 * rr));
		hat.add(Point(p.x - 0.6 * rr, p.y - 0.9 * rr));
		hat.add(Point(p.x - 0.6 * rr, p.y - 1.9 * rr));
		hat.add(Point(p.x + 0.6 * rr, p.y - 1.9 * rr));
		hat.add(Point(p.x + 0.6 * rr, p.y - 0.9 * rr));
		hat.add(Point(p.x + 0.8 * rr, p.y - 0.9 * rr));
		hat.add(Point(p.x + 0.7 * rr, p.y - 0.7 * rr));
		hat.set_fill_color(Color::dark_magenta);
	}

	void Frowny_Hat::draw_lines() const
	{
		Frowny::draw_lines();
		hat.draw_lines();
	}

	Smiley::Smiley(Point p, int rr):
		Circle(p, rr),
		eye_L(Point(p.x - rr / 5, p.y - rr / 2), rr / 10, rr / 5),
		eye_R(Point(p.x + rr / 5, p.y - rr / 2), rr / 10, rr / 5),
		mouth(p, rr / 2, rr / 2, 180, 360)
	{
		eye_L.set_color(Color::dark_green);
		eye_L.set_fill_color(Color::green);
		eye_R.set_color(Color::dark_green);
		eye_R.set_fill_color(Color::green);
		mouth.set_color(Color::dark_green);
	}

	void Smiley::draw_lines() const
	{
		Circle::draw_lines();
		eye_L.draw();
		eye_R.draw();
		mouth.draw();
	}

	Smiley_Hat::Smiley_Hat(Point p, int rr):
		Smiley(p, rr)
	{
		hat.add(Point(p.x - 0.7 * rr, p.y - 0.7 * rr));
		hat.add(Point(p.x - 0.8 * rr, p.y - 0.9 * rr));
		hat.add(Point(p.x - 0.6 * rr, p.y - 0.9 * rr));
		hat.add(Point(p.x - 0.6 * rr, p.y - 1.9 * rr));
		hat.add(Point(p.x + 0.6 * rr, p.y - 1.9 * rr));
		hat.add(Point(p.x + 0.6 * rr, p.y - 0.9 * rr));
		hat.add(Point(p.x + 0.8 * rr, p.y - 0.9 * rr));
		hat.add(Point(p.x + 0.7 * rr, p.y - 0.7 * rr));
		hat.set_fill_color(Color::dark_magenta);
	}

	void Smiley_Hat::draw_lines() const
	{
		Smiley::draw_lines();
		hat.draw_lines();
	}

	Striped_rectangle::Striped_rectangle(Point p, int rec_w, int rec_h):
		Rectangle{ p, rec_w, rec_h }
	{
		for (int i = p.y + 2; i < p.y + rec_h; i += 2)
		{
			lines.add(Point(p.x, i), Point(p.x + rec_w - 1, i));
			lines.set_color(Color::black);
		}
	}

	void Striped_rectangle::draw_lines() const
	{
		lines.draw();
		Rectangle::draw_lines();
	}

	Striped_circle::Striped_circle(Point p, int r):
		Circle{ p, r }
	{
		for (int i = p.y - r; i < p.y + r; i += 2)
		{
			int temp = sqrt(pow(r, 2) - pow(p.y - i, 2));
			lines.add(Point(p.x - temp, i), Point(p.x + temp, i));
			lines.set_color(Color::black);
		}
	}

	void Striped_circle::draw_lines() const
	{
		lines.draw();
		Circle::draw_lines();
	}

	Graph_lib::Striped_closed_polyline::Striped_closed_polyline(int dd):
		d{ dd }
	{}

	bool Graph_lib::on_line(Point p1, Point p2,
		Point pp)
	{
		int dx = p2.x - p1.x;
		int dy = p2.y - p1.y;
		int dx_p = pp.x - p1.x;
		int dy_p = pp.y - p1.y;
		if (!(dx_p * dy - dx * dy_p))
		{
			if (abs(dx) > abs(dy))
			{
				if (dx > 0)
				{
					return (p1.x <= pp.x && pp.x <= p2.x);
				}
				else
				{
					return (p2.x <= pp.x && pp.x <= p1.x);
				}
			}
			else
			{
				if (dy > 0)
				{
					return (p1.y <= pp.y && pp.y <= p2.y);
				}
				else
				{
					return (p2.y <= pp.y && pp.y <= p1.y);
				}
			}
		}
		return false;
	}

	bool intersection(Point p1, Point p2,
		Point p3, Point p4,
		Point& pp)
	{
		double x1 = p1.x;
		double x2 = p2.x;
		double x3 = p3.x;
		double x4 = p4.x;
		double y1 = p1.y;
		double y2 = p2.y;
		double y3 = p3.y;
		double y4 = p4.y;
		double d1 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
		double d2 = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);
		if (((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1)) == 0 && d1 != 0 && d2 != 0)
		{
			return false;
		}
		d1 = d1 / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
		d2 = d2 / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
		if (d1 < 0 || d1 > 1 || d2 < 0 || d2 > 1)
		{
			return false;
		}
		pp.x = x1 + d1 * (x2 - x1);
		pp.y = y1 + d1 * (y2 - y1);
		return true;
	}

	void Graph_lib::Striped_closed_polyline::draw_lines() const
	{
		Closed_polyline::draw_lines();
		int x_min = point(0).x;
		int y_min = point(0).y;
		int x_max = point(0).x;
		int y_max = point(0).y;
		std::vector<Point> v_lines;
		for (int i = 1; i < number_of_points(); ++i)
		{
			if (point(i).x < x_min)
			{
				x_min = point(i).x;
			}
			if (point(i).y < x_min)
			{
				y_min = point(i).y;
			}
			if (point(i).x > x_max)
			{
				x_max = point(i).x;
			}
			if (point(i).y > y_max)
			{
				y_max = point(i).y;
			}
		}
		for (int y = y_min + d; y < y_max; y += d)
		{
			Point pp;
			Point pp_back(0, 0);
			for (int i = 1; i < number_of_points(); ++i)
			{
				if (intersection(Point(x_min, y), Point(x_max, y),
					point(i - 1), point(i),
					pp))
				{
					if (pp != pp_back)
					{
						v_lines.push_back(pp);
						pp_back.x = pp.x;
						pp_back.y = pp.y;
					}
				}
			}
			if (intersection(Point(x_min, y), Point(x_max, y),
				point(number_of_points() - 1), point(0),
				pp))

			{
				if (pp != pp_back)
				{
					v_lines.push_back(pp);
					pp_back.x = pp.x;
					pp_back.y = pp.y;
				}
			}
		}
		for (int i = 1; i < v_lines.size(); i += 2)
		{
			Line l(v_lines[i], v_lines[i - 1]);
			l.draw();
		}
	}

	Octagon::Octagon(Point cc, int dd):
		cen{ cc },
		d{ dd }
	{
		add(Point(cc.x + dd, cc.y));
		for (int a = 360 / n; a < 360; a += 360 / n)
		{
			Point p((point(0).x - cen.x) * cos(a * PI() / 180) - (point(0).y - cen.y) * sin(a * PI() / 180) + cen.x,
				(point(0).y - cen.y) * cos(a * PI() / 180) + (point(0).x - cen.x) * sin(a * PI() / 180) + cen.y);
			add(p);
		}
	}
	Group::Group()
	{}

	void Group::add(Shape* s)
	{
		v_r.push_back(s);
	}

	void Group::set_color(Color color)
	{
		for (int i = 0; i < v_r.size(); ++i)
		{
			v_r[i].set_color(color);
		}
	}

	void Group::set_fill_color(Color color)
	{
		for (int i = 0; i < v_r.size(); ++i)
		{
			v_r[i].set_fill_color(color);
		}
	}

	void Group::draw_lines() const
	{
		for (int i = 0; i < v_r.size(); ++i)
		{
			v_r[i].draw();
		}
	}

	Pseudo_window::Pseudo_window(
		Point pp, int ww, int hh, std::string ss, std::string imgimg):
		p{ pp },
		w{ ww },
		h{ hh },
		s{ Point(p.x + w * 0.4, p.y + w * 0.04), ss },
		window{ p, w, h },
		close{ Point(p.x + w * 0.1, p.y + h * 0.05), (w + h) / 2 * 0.02 },
		maximize{ Point(p.x + w * 0.15, p.y + h * 0.05), (w + h) / 2 * 0.02 },
		minimize{ Point(p.x + w * 0.2, p.y + h * 0.05), (w + h) / 2 * 0.02 },
		img{ window.point(7), imgimg },
		l{ Point(p.x, window.point(7).y), Point(p.x + w, window.point(7).y) }
	{
		img.set_mask(Point(0, 0), w, window.point(6).y - 140);
		s.set_font_size(15);
		s.set_font(Font::courier_bold);
		s.set_color(Color::black);
		window.set_color(Color::black);
		window.set_fill_color(Color::white);
		close.set_color(Color::dark_red);
		close.set_fill_color(Color::dark_red);
		maximize.set_color(Color::red);
		maximize.set_fill_color(Color::red);
		minimize.set_color(Color::green);
		minimize.set_fill_color(Color::green);
		l.set_color(Color::black);
	}

	void Pseudo_window::draw_lines() const
	{
		window.draw();
		s.draw();
		minimize.draw();
		maximize.draw();
		close.draw();
		img.draw();
		l.draw();
	}

	Binary_tree::Binary_tree(Point pp, int ll, int rr):
		l{ ll },
		r{ rr }
	{
		if (l == 0)
		{
			throw("The minimum level value must be greater than zero.");
		}
		int dx = 40 * r;
		int dy = dx / 10;
		for (int i = 0; i < l; ++i)
		{
			if (i == 0)
			{
				add(pp);
			}
			else
			{
				dx /= 2;
				std::vector<Point> points;
				for (int j = pow(2, i - 1) - 1; j < pow(2, i) - 1; ++j)
				{
					points.push_back(Point(point(j).x - dx, point(j).y + dy));
					points.push_back(Point(point(j).x + dx, point(j).y + dy));
				}
				for (Point s : points)
				{
					add(s);
				}
			}
		}
		for (int i = 0; i < number_of_points(); ++i)
		{
			if (i < pow(2, l - 1) - 1)
			{
				v_lines.push_back(new Line(point(i), point(2 * i + 1)));
				v_lines.push_back(new Line(point(i), point(2 * i + 2)));
			}
		}
	}

	void Binary_tree::draw_lines() const
	{
		for (int i = 0; i < v_lines.size(); ++i)
		{
			v_lines[i].draw();
		}
		for (int i = 0; i < number_of_points(); ++i)
		{
			Circle c(point(i), r);
			c.set_fill_color(Color::blue);
			c.draw();
		}
	}

	Binary_tree::Binary_tree(
		Point pp, int ll, int rr, int line_type, Color line_color):
		l{ ll },
		r{ rr }
	{
		if (l == 0)
		{
			throw("The minimum level value must be greater than zero.");
		}
		int dx = 40 * r;
		int dy = dx / 10;
		for (int i = 0; i < l; ++i)
		{
			if (i == 0)
			{
				add(pp);
			}
			else
			{
				dx /= 2;
				std::vector<Point> points;
				for (int j = pow(2, i - 1) - 1; j < pow(2, i) - 1; ++j)
				{
					points.push_back(Point(point(j).x - dx, point(j).y + dy));
					points.push_back(Point(point(j).x + dx, point(j).y + dy));
				}
				for (Point s : points)
				{
					add(s);
				}
			}
		}
		for (int i = 0; i < number_of_points(); ++i)
		{
			if (i < pow(2, l - 1) - 1)
			{
				switch (line_type)
				{
				case 1: // line
					v_lines.push_back(new Line(point(i), point(2 * i + 1)));
					v_lines.push_back(new Line(point(i), point(2 * i + 2)));
					break;
				case 2: // line with arrow 1
					v_lines.push_back(new Arrow(point(i), point(2 * i + 1), line_color));
					v_lines.push_back(new Arrow(point(i), point(2 * i + 2), line_color));
					break;
				case 3: // line with arrow 2
					v_lines.push_back(new Arrow(point(2 * i + 1), point(i), line_color));
					v_lines.push_back(new Arrow(point(2 * i + 2), point(i), line_color));
					break;
				default: // line
					v_lines.push_back(new Line(point(i), point(2 * i + 1)));
					v_lines.push_back(new Line(point(i), point(2 * i + 2)));
					break;
				}
			}
		}
	}

	void Binary_tree_Rectangle::draw_lines() const
	{
		for (int i = 0; i < number_of_points(); ++i)
		{
			Graph_lib::Rectangle rec(point(i), r, r);
			rec.set_fill_color(Color::blue);
			rec.draw();
		}
		for (int i = 0; i < v_lines.size(); ++i)
		{
			v_lines[i].draw();
		}
	}

	MyFunction::MyFunction(
		double (*f)(double), double r1, double r2, 
		Point o, int n, double xsc, double ysc, double pr):
		Function(f, r1, r2, o, n, xsc, ysc),
		func{ f },
		r_min{ r1 },
		r_max{ r2 },
		orig{ o },
		n_points{ n },
		x_scale{ xsc },
		y_scale{ ysc },
		precision{ pr }
	{
		validate_range();
		validate_n_points();
		validate_x_scale();
		validate_y_scale();
		update_points();
	}

	void MyFunction::update_points()
	{
		double d = (r_max - r_min) / n_points;
		clear_points();

		double r_current = r_min;
		for (int i = 0; i < n_points; ++i)
		{
			add(Point(orig.x + static_cast<int>(static_cast<int>(r_current * x_scale) / precision) * precision,
				orig.y - static_cast<int>(static_cast<int>(func(r_current) * y_scale) / precision) * precision));
			r_current += d;
		}
	}

	void MyFunction::set_func(double (*f)(double))
	{
		func = f;
		update_points();
	}

	void MyFunction::set_range(double r1, double r2)
	{
		r_min = r1;
		r_max = r2;
		validate_range();
		update_points();
	}

	void MyFunction::set_n_points(int n)
	{
		n_points = n;
		validate_n_points();
		update_points();
	}

	void MyFunction::set_x_scale(double xsc)
	{
		x_scale = xsc;
		validate_x_scale();
		update_points();
	}

	void MyFunction::set_y_scale(double ysc)
	{
		y_scale = ysc;
		validate_y_scale();
		update_points();
	}

	void MyFunction::set_orig(Point o)
	{
		orig = o;
		update_points();
	}

	void MyFunction::set_precision(double pr)
	{
		precision = pr;
		update_points();
	}

	void MyFunction::validate_range()
	{
		if (r_max <= r_min)
		{
			throw("Wrong range");
		}
	}

	void MyFunction::validate_n_points()
	{
		if (n_points <= 0)
		{
			throw("Wrong n points");
		}
	}

	void MyFunction::validate_x_scale()
	{
		if (x_scale == 0)
		{
			throw("Wrong scale for X");
		}
	}

	void MyFunction::validate_y_scale()
	{
		if (y_scale == 0)
		{
			throw("Wrong scale for Y");
		}
	}

	MyHist::MyHist(Point orig, int xs, int ys)
		: x_size{ xs }, y_size{ ys }
	{
		Shape::add(orig);
	}

	void MyHist::add(double v)
	{
		data.push_back(v);
		labels.push_back(new Text(Point(0, 0), ""));
		int bar_width = x_size / data.size();
		Vector_ref<Text> labels_;
		for (int i = 0; i < labels.size(); ++i)
		{
			labels_.push_back(labels[i]);
		}
		std::vector<Color> colors;
		std::vector<Color> colors_fill;
		double data_max = 0;
		for (int i = 0; i <= rectangles.size(); ++i)
		{
			if (i != rectangles.size())
			{
				colors.push_back(rectangles[i].color());
				colors_fill.push_back(rectangles[i].fill_color());
			}
			if (data[i] > data_max)
			{
				data_max = data[i];
			}
		}
		rectangles.clear();
		labels.clear();
		for (int i = 0; i < data.size(); ++i)
		{
			rectangles.push_back(new Rectangle(Point(point(0).x + bar_width * i,
				point(0).y - data[i] / data_max * y_size),
				0.9 * bar_width,
				data[i] / data_max * y_size));
			if ((i == 0) || (i % 6 == 0))
			{
				labels.push_back(new Text(Point(rectangles[i].point(0).x,
					point(0).y + y_size * 0.6),
					labels_[i].label()));
			}
			else
			{
				if ((i + 5) % 6 == 0)
				{
					labels.push_back(new Text(Point(rectangles[i].point(0).x + 2,
						point(0).y + y_size * 0.5),
						labels_[i].label()));
				}
				else
				{
					if ((i + 4) % 6 == 0)
					{
						labels.push_back(new Text(Point(rectangles[i].point(0).x + 2,
							point(0).y + y_size * 0.4),
							labels_[i].label()));
					}
					else
					{
						if ((i + 3) % 6 == 0)
						{
							labels.push_back(new Text(Point(rectangles[i].point(0).x + 2,
								point(0).y + y_size * 0.3),
								labels_[i].label()));
						}
						else
						{
							if ((i + 2) % 6 == 0)
							{
								labels.push_back(new Text(Point(rectangles[i].point(0).x + 2,
									point(0).y + y_size * 0.2),
									labels_[i].label()));
							}
							else
							{
								labels.push_back(new Text(Point(rectangles[i].point(0).x + 2,
									point(0).y + y_size * 0.1),
									labels_[i].label()));
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < colors.size(); ++i)
		{
			rectangles[i].set_color(colors[i]);
			rectangles[i].set_fill_color(colors_fill[i]);
		}
	}

	void MyHist::set_bar_color(Color c, int i)
	{
		rectangles[i].set_color(c);
	}

	void MyHist::set_bar_fill_color(Color c, int i)
	{
		rectangles[i].set_fill_color(c);
	}

	void MyHist::set_bar_label(std::string l, int i)
	{
		labels[i].set_label(l);
	}

	void MyHist::draw_lines() const
	{
		for (int i = 0; i < rectangles.size(); ++i)
		{
			rectangles[i].draw_lines();
			if (labels[i].label() != "")
			{
				Line l(Point(rectangles[i].point(0).x, rectangles[i].point(0).y),
					Point(rectangles[i].point(0).x, labels[i].point(0).y));
				l.set_style(Line_style::dash);
				l.draw();
				labels[i].draw();
			}
		}
		Axis x(Axis::x, point(0), x_size, 0, x_label);
		x.label.move(3 * y_size / 4, 0);
		Axis y(Axis::y, point(0), y_size, 0, y_label);
		x.draw_lines();
		y.draw_lines();
	}

	double MyHist::get_idata(int i)
	{
		return data[i];
	}

	std::string MyHist::set_x_label(std::string xl)
	{
		x_label = xl;
		return x_label;
	}

	std::string MyHist::set_y_label(std::string yl)
	{
		y_label = yl;
		return y_label;
	}

	Scale::Scale(int b, int vb, double s)
		: cbase{ b }, vbase{ vb }, scale{ s }
	{
	}

	int Scale::operator()(int v) const
	{
		return cbase + (v - vbase) * scale;
	}

	Lines_window::Lines_window(Point xy, int w, int h, const std::string& title):
		Window{ xy, w, h, title },
		next_button{ Point(x_max() - 150, 0), 70, 20, "Next point",
					[](Address, Address pw) {reference_to<Lines_window>(pw).next(); } },
		quit_button{ Point(x_max() - 70, 0), 70, 20, "Quit",
					[](Address, Address pw) {reference_to<Lines_window>(pw).quit(); } },
		next_x{ Point(x_max() - 310, 0), 50, 20, "next_x:" },
		next_y{ Point(x_max() - 210, 0), 50, 20, "next_y:" },
		xy_out{ Point(100, 0), 100, 20, "current (x, y):" },
		color_menu{ Point(x_max() - 100, 40), 70, 20, Menu::vertical, "color" },
		cmenu_button{ Point(x_max() - 100, 30), 80, 20, "color_menu", cb_cmenu },
		style_menu{ Point(x_max() - 200, 40), 70, 20, Menu::vertical, "style" },
		smenu_button{ Point(x_max() - 200, 30), 80, 20, "style_menu", cb_smenu }
	{
		attach(next_button);
		attach(quit_button);
		attach(next_x);
		attach(next_y);
		attach(xy_out);
		xy_out.put("no point");
		color_menu.attach(new Button(Point(0, 0), 0, 0, "red", cb_red));
		color_menu.attach(new Button(Point(0, 0), 0, 0, "blue", cb_blue));
		color_menu.attach(new Button(Point(0, 0), 0, 0, "black", cb_black));
		attach(color_menu);
		color_menu.hide();
		attach(cmenu_button);
		style_menu.attach(new Button(Point(0, 0), 0, 0, "solid", cb_solid));
		style_menu.attach(new Button(Point(0, 0), 0, 0, "dot", cb_dot));
		style_menu.attach(new Button(Point(0, 0), 0, 0, "dash", cb_dash));
		attach(style_menu);
		style_menu.hide();
		attach(smenu_button);
		attach(lines);
	}

	void Lines_window::cb_red(Address, Address pw)
	{
		reference_to<Lines_window>(pw).red_pressed();
	}

	void Lines_window::cb_blue(Address, Address pw)
	{
		reference_to<Lines_window>(pw).blue_pressed();
	}

	void Lines_window::cb_black(Address, Address pw)
	{
		reference_to<Lines_window>(pw).black_pressed();
	}

	void Lines_window::cb_cmenu(Address, Address pw)
	{
		reference_to<Lines_window>(pw).cmenu_pressed();
	}

	void Lines_window::cb_solid(Address, Address pw)
	{
		reference_to<Lines_window>(pw).solid_pressed();
	}

	void Lines_window::cb_dot(Address, Address pw)
	{
		reference_to<Lines_window>(pw).dot_pressed();
	}

	void Lines_window::cb_dash(Address, Address pw)
	{
		reference_to<Lines_window>(pw).dash_pressed();
	}

	void Lines_window::cb_smenu(Address, Address pw)
	{
		reference_to<Lines_window>(pw).smenu_pressed();
	}

	void Lines_window::cb_next(Address, Address pw)
	{
		reference_to<Lines_window>(pw).next();
	}

	void Lines_window::cb_quit(Address, Address pw)
	{
		reference_to<Lines_window>(pw).quit();
	}

	void Lines_window::red_pressed()
	{
		change(Color::red);
		hide_cmenu();
	}

	void Lines_window::blue_pressed()
	{
		change(Color::blue);
		hide_cmenu();
	}

	void Lines_window::black_pressed()
	{
		change(Color::black);
		hide_cmenu();
	}

	void Lines_window::solid_pressed()
	{
		change_style(Line_style(Line_style::solid));
		hide_smenu();
	}

	void Lines_window::dot_pressed()
	{
		change_style(Line_style(Line_style::dot));
		hide_smenu();
	}

	void Lines_window::dash_pressed()
	{
		change_style(Line_style(Line_style::dash));
		hide_smenu();
	}

	void Lines_window::smenu_pressed()
	{
		smenu_button.hide();
		style_menu.show();
	}

	void Lines_window::cmenu_pressed()
	{
		cmenu_button.hide();
		color_menu.show();
	}

	void Lines_window::change(Color c)
	{
		lines.set_color(c);
	}

	void Lines_window::change_style(Line_style ls)
	{
		lines.set_style(ls);
	}

	void Lines_window::hide_cmenu()
	{
		color_menu.hide();
		cmenu_button.show();
	}

	void Lines_window::hide_smenu()
	{
		style_menu.hide();
		smenu_button.show();
	}

	void Lines_window::next()
	{
		int x = next_x.get_int();
		int y = next_y.get_int();
		lines.add(Point(x, y));
		std::ostringstream ss;
		ss << '(' << x << ',' << y << ')';
		xy_out.put(ss.str());
		redraw();
	}

	void Lines_window::quit()
	{
		hide();
	}

	My_window::My_window(Point xy, int w, int h, const std::string& title):
		Simple_window{ xy, w, h, title },
		quit_button{ Point(x_max() - 70, 30), 70, 20, "Quit", cb_quit }
	{
		attach(quit_button);
	}

	void My_window::cb_quit(Address, Address pw)
	{
		reference_to<My_window>(pw).quit();
	}

	void My_window::quit()
	{
		hide();
	}

	Button_board::Button_board(Point xy, int w, int h, const std::string& title, int t_r, int t_c):
		My_window{ xy, w, h, title },
		table_row{ t_r },
		table_column{ t_c },
		xy_out{ Point(x_max() - 70, 60), 70, 20, "(x, y)" }
	{
		buttons.resize(table_row);
		for (int i = 0; i < table_row; ++i)
		{
			buttons[i].resize(table_column);
		}
		for (i = 0; i < table_column; ++i)
		{
			Menu* m = new Menu(Point(i * 50, 0), 50, 50, Menu::vertical, "menu");
			for (j = 0; j < table_row; ++j)
			{
				Button* b = new Button(Point(0, 0), 0, 0, std::to_string(j + 1) + "-" + std::to_string(i + 1),
					[](Address b, Address pw)
					{
						std::string str = reference_to<Button_board>(b).select_button();
						reference_to<Button_board>(pw).select_label(str);
					}
				);
				buttons[j].push_back(b);
				m->attach(*b);
			}
			attach(*m);
		}
		attach(xy_out);
		xy_out.put("no point");
	}

	std::string Button_board::select_button()
	{
		std::cout << "button address = " << this << '\n';
		std::string str = '(' + std::to_string((*this).x()) + ',' + std::to_string((*this).y()) + ')';
		return str;
	}

	void Button_board::select_label(std::string str)
	{
		std::cout << "label address = " << this << '\n';
		xy_out.put(str);
	}

	Image_Button::Image_Button(Point xy, int w, int h, const std::string& title):
		My_window{ xy, w, h, title },
		image_btn{ Point(randint(0, x_max() - 100), randint(0, y_max() - 100)), 100, 100, "", cb_move },
		image{ image_btn.loc, "snow_cpp.gif" }
	{
		attach(image_btn);
		image.set_mask(Point(100, 100), 100, 100);
		attach(image);
	}

	void Image_Button::cb_move(Address, Address pw)
	{
		reference_to<Image_Button>(pw).move();
	}

	void Image_Button::move()
	{
		int dx = randint(0, x_max() - 100) - image_btn.loc.x;
		int dy = randint(0, y_max() - 100) - image_btn.loc.y;
		image.move(dx, dy);
		image_btn.move(dx, dy);
	}

	MyMenu::MyMenu(Point xy, int w, int h, const std::string& title):
		My_window{ xy, w, h, title },
		mymenu{ Point(x_max() - 70, 70), 70, 30, Menu::vertical, "figures" },
		clear_btn{ Point(x_max() - 70, 260), 70, 30, "Clear", cb_clear },
		x_pos{ Point(x_max() - 70, 200), 70, 30, "x: " },
		y_pos{ Point(x_max() - 70, 230), 70, 30, "y: " },
		x{ 0 },
		y{ 0 }
	{
		mymenu.attach(new Button(Point(0, 0), 0, 0, "Circle", cb_circle));
		mymenu.attach(new Button(Point(0, 0), 0, 0, "Square", cb_square));
		mymenu.attach(new Button(Point(0, 0), 0, 0, "Triangle", cb_triangle));
		mymenu.attach(new Button(Point(0, 0), 0, 0, "Hexagon", cb_hexagon));
		attach(mymenu);
		attach(x_pos);
		attach(y_pos);
		attach(clear_btn);
	}

	void MyMenu::get_position()
	{
		x = x_pos.get_int();
		y = y_pos.get_int();
	}

	void MyMenu::draw_circle()
	{
		get_position();
		figures.push_back(new Circle(Point(x, y), 150));
		attach(figures[figures.size() - 1]);
		redraw();
	}

	void MyMenu::draw_square()
	{
		get_position();
		figures.push_back(new Rectangle(Point(x - 150, y - 150), 300, 300));
		attach(figures[figures.size() - 1]);
		redraw();
	}

	void MyMenu::draw_triangle()
	{
		get_position();
		figures.push_back(new Regular_polygon(Point(x, y), 3, 150));
		attach(figures[figures.size() - 1]);
		redraw();
	}

	void MyMenu::draw_hexagon()
	{
		get_position();
		figures.push_back(new Regular_polygon(Point(x, y), 6, 150));
		attach(figures[figures.size() - 1]);
		redraw();
	}

	void MyMenu::cb_circle(Address, Address pw)
	{
		reference_to<MyMenu>(pw).draw_circle();
	}

	void MyMenu::cb_square(Address, Address pw)
	{
		reference_to<MyMenu>(pw).draw_square();
	}

	void MyMenu::cb_triangle(Address, Address pw)
	{
		reference_to<MyMenu>(pw).draw_triangle();
	}

	void MyMenu::cb_hexagon(Address, Address pw)
	{
		reference_to<MyMenu>(pw).draw_hexagon();
	}

	void MyMenu::cb_clear(Address, Address pw)
	{
		reference_to<MyMenu>(pw).clear();
	}

	void MyMenu::clear()
	{
		for (int i = 0; i < figures.size(); ++i)
		{
			detach(figures[figures.size() - i - 1]);
		}
		redraw();
	}

	MyMenuMove::MyMenuMove(Point xy, int w, int h, const std::string& title):
		MyMenu{ xy, w, h, title },
		next_btn{ Point(x_max() - 70, 0), 70, 20, "Next", cb_move }
	{
		attach(next_btn);
	}

	void MyMenuMove::next()
	{
		if (figures.size() == 0)
		{
			throw("No figures");
		}
		int x_old = x;
		int y_old = y;
		///////////////
		// 1
		std::cout << "Enter new coordinates (x y): \n";
		std::cin >> x >> y;
		///////////////
		// 2
		//get_position();
		///////////////
		int dx = x - x_old;
		int dy = y - y_old;
		figures[figures.size() - 1].move(dx, dy);
		redraw();
	}

	void MyMenuMove::cb_move(Address, Address pw)
	{
		reference_to<MyMenuMove>(pw).next();
	}

	Clock::Clock(Point xy, int w, int h, const std::string& title):
		Window{ xy, w, h, title },
		w{ w },
		h{ h },
		r{ w / 2 },
		clock{ Point(r, r), w * 0.3 },
		center{ Point(r, r), w * 0.015 },
		seconds{ Point(w / 2, h / 2),
			Point(w / 2 + static_cast<int>(sin(get_seconds() * 6 * PI() / 180) * w / 4),
				h / 2 - static_cast<int>(cos(get_seconds() * 6 * PI() / 180) * w / 4)) },
		minutes{ Point(w / 2, h / 2),
			Point(w / 2 + static_cast<int>(sin(get_minutes() * 6 * PI() / 180) * w / 5),
				h / 2 - static_cast<int>(cos(get_minutes() * 6 * PI() / 180) * w / 5)) },
		hours{ Point(w / 2, h / 2),
			Point(w / 2 + static_cast<int>(sin(get_hours() * 30 * PI() / 180) * w / 6),
				h / 2 - static_cast<int>(cos(get_hours() * 30 * PI() / 180) * w / 6)) }
	{
		Point pcenter(w / 2, h / 2);
		clock.set_style(Line_style(Line_style::Line_style_type::solid, 4));
		clock.set_fill_color(Color::white);
		attach(clock);

		center.set_fill_color(Color::black);
		attach(center);

		seconds.set_style(Line_style(Line_style::dot, 4));
		seconds.set_color(Color::red);
		attach(seconds);

		minutes.set_style(Line_style(Line_style::dash, 6));
		minutes.set_color(Color::blue);
		attach(minutes);
		hours.set_style(Line_style(Line_style::solid, 8));
		hours.set_color(Color::green);
		attach(hours);
	}

	void Clock::run_clock()
	{
		std::cout << get_hours() << ' ' << get_minutes() << ' ' << get_seconds() << '\n';
		seconds.set_point(1, Point(w / 2 + static_cast<int>(sin(get_seconds() * 6 * PI() / 180) * w / 4),
			h / 2 - static_cast<int>(cos(get_seconds() * 6 * PI() / 180) * w / 4)));
		minutes.set_point(1, Point(w / 2 + static_cast<int>(sin(get_minutes() * 6 * PI() / 180) * w / 5),
			h / 2 - static_cast<int>(cos(get_minutes() * 6 * PI() / 180) * w / 5)));
		hours.set_point(1, Point(w / 2 + static_cast<int>(sin(get_hours() * 30 * PI() / 180) * w / 6),
			h / 2 - static_cast<int>(cos(get_hours() * 30 * PI() / 180) * w / 6)));
		redraw();
	}

	void Clock::cb_run_clock(void* clock)
	{
		Clock* c = (Clock*)clock;
		c->run_clock();
		Fl::repeat_timeout(1.0, Clock::cb_run_clock, clock);
	}

	int Clock::get_seconds()
	{
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);
		int seconds = newtime.tm_sec;
		return seconds;
	}

	int Clock::get_minutes()
	{
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);
		int minutes = newtime.tm_min;
		return minutes;
	}

	int Clock::get_hours()
	{
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);
		int hours = newtime.tm_hour;
		return hours;
	}

	MyLine::MyLine(Point p1, Point p2)
	{
		add(p1);
		add(p2);
	}

	void MyLine::set_point(int i, Point p)
	{
		Shape::set_point(i, p);
	}
}
