#pragma once

struct Point
{
	int x;
	int y;
	Point();
	Point(int xx, int yy);
};

inline bool operator==(Point a, Point b);

bool operator!=(Point a, Point b);