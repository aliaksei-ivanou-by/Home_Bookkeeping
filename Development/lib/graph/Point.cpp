#include "home_bookkeeping/lib/graph/Point.h"

Point::Point():
  x{ 0 },
  y{ 0 }
{}

Point::Point(int xx, int yy):
  x{ xx },
  y{ yy }
{}

bool operator==(Point a, Point b)
{
  return a.x == b.x && a.y == b.y;
}

bool operator!=(Point a, Point b)
{
  return !(a == b);
}
