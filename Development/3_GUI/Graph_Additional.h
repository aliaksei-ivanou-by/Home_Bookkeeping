#pragma once

#include "Simple_window.h"
#include "Graph.h"
#include "../include/stdafx.h"
#include "../include/FLTK.h"

namespace Graph_lib
{
	class Arc : public Shape
	{
	public:
		Arc(Point center, int width, int height, double start, double end);
		void draw_lines() const;
	private:
		int width;
		int height;
		double start;
		double end;
	};

	class Box : public Shape
	{
	public:
		Box(Point p, int ww, int hh);
		void draw_lines() const;
	protected:
		Box();
	private:
		int w;
		int h;
	};

	class Arrow : public Shape
	{
	public:
		Arrow(Point p1, Point p2);
		Arrow(Point p1, Point p2, Color line_color);
		void draw_lines() const;
		void set_size(int s);
	private:
		int size = 10;
		int delta = 20;
	};

	Point n(const Graph_lib::Rectangle& r); // top
	Point s(const Graph_lib::Rectangle& r); // bottom
	Point e(const Graph_lib::Rectangle& r); // right
	Point w(const Graph_lib::Rectangle& r); // left
	Point center(const Graph_lib::Rectangle& r); // center
	Point ne(const Graph_lib::Rectangle& r); // top-right
	Point se(const Graph_lib::Rectangle& r); // bottom-right
	Point sw(const Graph_lib::Rectangle& r); // bottom-left
	Point nw(const Graph_lib::Rectangle& r); // top-left

	Point n(const Graph_lib::Circle& c); // top
	Point s(const Graph_lib::Circle& c); // bottom
	Point e(const Graph_lib::Circle& c); // right
	Point w(const Graph_lib::Circle& c); // left
	Point center(const Graph_lib::Circle& c); // center
	Point ne(const Graph_lib::Circle& c); // top-right
	Point se(const Graph_lib::Circle& c); // bottom-right
	Point sw(const Graph_lib::Circle& c); // bottom-left
	Point nw(const Graph_lib::Circle& c); // top-left
	
	Point n(const Graph_lib::Ellipse& e); // top
	Point s(const Graph_lib::Ellipse& e); // bottom
	Point e(const Graph_lib::Ellipse& e); // right
	Point w(const Graph_lib::Ellipse& e); // left
	Point center(const Graph_lib::Ellipse& e); // center
	Point ne(const Graph_lib::Ellipse& e); // top-right
	Point se(const Graph_lib::Ellipse& e); // bottom-right
	Point sw(const Graph_lib::Ellipse& e); // bottom-left
	Point nw(const Graph_lib::Ellipse& e); // top-left

	class Box_text : public Rectangle
	{
	public:
		Box_text(Point pp, std::string ss);
		Box_text(Point pp, std::string ss, int ww, int hh);
		void draw_lines() const;
	private:
		Text text;
	};

	class Regular_hexagon : public Polygon
	{
	public:
		Regular_hexagon(Point c, int d);
	private:
		Point c;
		int d;
		const int n = 6;
	};

	class Regular_polygon : public Polygon
	{
	public:
		Regular_polygon(Point c, int n, int d);
	private:
		Point c;
		int d;
		int n;
	};

	class Right_triangle : public Closed_polyline
	{
	public:
		Right_triangle(Point p, int side1, int side2, double angle = 0);
	private:
		int side1;
		int side2;
		double angle = 0;
		double alpha = 90;
	};

	class Poly : public Polygon
	{
	public:
		Poly(std::vector<Point> v_p);
		void add(Point p);
		void draw_lines() const;
	};

	class Star : public Polygon
	{
	public:
		Star(Point c, int n, int r);
		Point find_distance(Point p1, Point p2, int d);
	private:
		Point c; // center
		int n; // points
		int r; // radius
	};

	class Frowny : public Circle
	{
	public:
		Frowny(Point p, int rr);
		void draw_lines() const;
	private:
		Ellipse eye_L;
		Ellipse eye_R;
		Arc mouth;
	};

	class Frowny_Hat : public Frowny
	{
	public:
		Frowny_Hat(Point p, int rr);
		void draw_lines() const;
	private:
		Polygon hat;
	};

	class Smiley : public Circle
	{
	public:
		Smiley(Point p, int rr);
		void draw_lines() const;
	private:
		Ellipse eye_L;
		Ellipse eye_R;
		Arc mouth;
	};

	class Smiley_Hat : public Smiley
	{
	public:
		Smiley_Hat(Point p, int rr);
		void draw_lines() const;
	private:
		Polygon hat;
	};

	class Striped_rectangle : public Rectangle
	{
	public:
		Striped_rectangle(Point p, int rec_w, int rec_h);
		void draw_lines() const;
	private:
		Lines lines;
	};

	class Striped_circle : public Circle
	{
	public:
		Striped_circle(Point p, int r);
		void draw_lines() const;
	private:
		Lines lines;
	};

	class Striped_closed_polyline : public Closed_polyline
	{
	public:
		Striped_closed_polyline(int d);
		void draw_lines() const;
	private:
		int d;
	};

	bool on_line(Point p1, Point p2, Point point);

	bool intersection(Point p1, Point p2, Point p3, Point p4, Point& pp);

	class Octagon : public Polygon
	{
	public:
		Octagon(Point c, int d);
	private:
		Point cen;
		int d;
		const int n = 8;
	};

	class Group : public Shape
	{
	public:
		Group();
		void add(Shape* s);
		void set_color(Color color);
		void set_fill_color(Color color);
		void draw_lines() const;
	private:
		Vector_ref<Shape> v_r;
	};

	class Pseudo_window : public Box
	{
	public:
		Pseudo_window(Point pp, int ww, int hh, std::string str, std::string img_file);
		void draw_lines() const;
	private:
		Point p;
		int w;
		int h;
		Text s;
		Box window;
		Circle minimize;
		Circle maximize;
		Circle close;
		Image img;
		Line l;
	};

	class Binary_tree : public Shape
	{
	public:
		Binary_tree(Point pp, int ll, int rr);
		Binary_tree(Point pp, int ll, int rr, int line_type = 1, Color line_color = Color::black);
		void draw_lines() const;
	protected:
		int r;
		int l;
		Vector_ref<Shape> v_lines;
	};

	class Binary_tree_Rectangle : public Binary_tree
	{
	public:
		using Binary_tree::Binary_tree;
		void draw_lines() const;
	};

	class MyFunction : public Function
	{
	public:
		MyFunction(double (*f)(double), double r_min, double r_max, Point orig, int n_points = 100, double x_scale = 20, double y_scale = 20, double precision = 1);
		void update_points();
		void set_func(double (*func)(double));
		void set_range(double r_min, double r_max);
		void set_n_points(int n_points);
		void set_x_scale(double x_scale);
		void set_y_scale(double y_scale);
		void set_orig(Point orig);
		void set_precision(double precision);
	private:
		double (*func)(double);
		double r_min;
		double r_max;
		Point orig;
		int n_points;
		double x_scale;
		double y_scale;
		double precision;
		void validate_range();
		void validate_n_points();
		void validate_x_scale();
		void validate_y_scale();
	};

	class MyHist : public Shape
	{
	public:
		MyHist(Point orig, int xs, int ys);
		void add(double value);
		void set_bar_color(Color color, int bar);
		void set_bar_fill_color(Color color, int i);
		void set_bar_label(std::string l, int i);
		void draw_lines() const;
		double get_idata(int i);
		std::string set_x_label(std::string x_label);
		std::string set_y_label(std::string y_label);
	private:
		int x_size;
		int y_size;
		std::vector<double> data;
		Vector_ref<Rectangle> rectangles;
		Vector_ref<Text> labels;
		std::string x_label;
		std::string y_label;
	};

	class Scale
	{
	public:
		Scale(int b, int vb, double s);
		int operator()(int v) const;
	private:
		int cbase;
		int vbase;
		double scale;
	};

	class Lines_window : Window
	{
	public:
		Lines_window(Point xy, int w, int h, const std::string& title);
	private:
		Open_polyline lines;

		Button next_button;
		Button quit_button;
		In_box next_x;
		In_box next_y;
		Out_box xy_out;
		Menu color_menu;
		Button cmenu_button;
		Menu style_menu;
		Button smenu_button;

		void change(Color c);
		void change_style(Line_style ls);

		void hide_cmenu();
		void hide_smenu();

		void red_pressed();
		void blue_pressed();
		void black_pressed();
		void cmenu_pressed();
		void solid_pressed();
		void dot_pressed();
		void dash_pressed();
		void smenu_pressed();
		void next();
		void quit();

		static void cb_red(Address, Address);
		static void cb_blue(Address, Address);
		static void cb_black(Address, Address);
		static void cb_cmenu(Address, Address);
		static void cb_solid(Address, Address);
		static void cb_dot(Address, Address);
		static void cb_dash(Address, Address);
		static void cb_smenu(Address, Address);
		static void cb_next(Address, Address);
		static void cb_quit(Address, Address);
	};

	class My_window : public Simple_window
	{
	public:
		My_window(Point xy, int w, int h, const std::string& title);
	private:
		Button quit_button;
		static void cb_quit(Address, Address);
		void quit();
	};

	class Button_board : public My_window
	{
	public:
		Button_board(Point xy, int w, int h, const std::string& title, int table_row, int table_column);
	private:
		std::vector<std::vector<Button*>> buttons;
		int table_column;
		int table_row;
		Out_box xy_out;

		int i = 0;
		int j = 0;

		std::string select_button();
		void select_label(std::string);
	};

	class Image_Button : public My_window
	{
	public:
		Image_Button(Point xy, int w, int h, const std::string& title);
	private:
		Button image_btn;
		Image image;

		static void cb_move(Address, Address);;
		void move();
	};

	class MyMenu : public My_window
	{
	public:
		MyMenu(Point xy, int w, int h, const std::string& title);
	protected:
		int x;
		int y;
		Vector_ref<Shape> figures;
		void get_position();
	private:
		Button clear_btn;

		Menu mymenu;

		In_box x_pos;
		In_box y_pos;

		void draw_circle();
		void draw_square();
		void draw_triangle();
		void draw_hexagon();

		static void cb_circle(Address, Address);
		static void cb_square(Address, Address);
		static void cb_triangle(Address, Address);
		static void cb_hexagon(Address, Address);
		static void cb_clear(Address, Address);

		void clear();
	};

	class MyMenuMove : public MyMenu
	{
	public:
		MyMenuMove(Point xy, int w, int h, const std::string& title);
	private:
		Button next_btn;

		void next();

		static void cb_move(Address, Address);
	};

	class MyLine : public Shape
	{
	public:
		MyLine(Point p1, Point p2);
		void set_point(int i, Point p);
	};

	class Clock : public Window, public Shape
	{
	public:
		Clock(Point xy, int w, int h, const std::string& title);
		void run_clock();
		static void cb_run_clock(void* clock);
		int get_seconds();
		int get_minutes();
		int get_hours();
	private:
		int r;
		Circle clock;
		Circle center;
		MyLine seconds;
		MyLine minutes;
		MyLine hours;
		int w;
		int h;
	};
}