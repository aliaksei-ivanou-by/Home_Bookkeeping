cmake_minimum_required(VERSION 3.8)

project(graph)

add_library(graph STATIC
  FLTK.h
  Graph.cpp Graph.h
  Graph_Additional.cpp Graph_Additional.h
  GUI.cpp GUI.h
  Point.cpp Point.h
  Simple_window.cpp Simple_window.h
  Window.cpp Window.h
  )