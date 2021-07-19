#ifndef HOMEBOOKKEEPING_LIB_GRAPH_POINT_H_
#define HOMEBOOKKEEPING_LIB_GRAPH_POINT_H_

struct Point
{
  int x;
  int y;
  Point();
  Point(int xx, int yy);
};

inline bool operator==(Point a, Point b);

bool operator!=(Point a, Point b);

#endif  //  HOMEBOOKKEEPING_LIB_GRAPH_POINT_H_
