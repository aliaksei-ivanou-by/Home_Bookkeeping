#ifndef HOMEBOOKKEEPING_0MODELS_TIME_H_
#define HOMEBOOKKEEPING_0MODELS_TIME_H_

//  Class Time
//
//  Constructors:
//    Default (current time and current date)
//
//  Class member functions:
//    Set current second
//    Set current minute
//    Set current hour
//    Set current day
//    Set current month
//    Set current year
//    Set surrent time and current date
//    Get second
//    Get minute
//    Get hour
//    Get day
//    Get month
//    Get year
//    Set second
//    Set minute
//    Set hour
//    Set day
//    Set month
//    Set year
//    Set date (year, month, day, hour, minute, second)
//    Check date for correctness
//    Get current time in string format
//    Operator < for sorting times (by day and time)
//    Output time (year, month, day, hour, minute, second -> "YYYY-MM-DD HH:MM:SS")
//    Input time (year, month, day, hour, minute, second -> "YYYY-MM-DD HH:MM:SS")
//
//  Variables:
//    second
//    minute
//    hour
//    day
//    month
//    year

#include <iostream>
#include <string>
#include <sstream>

#include "home_bookkeeping/lib/logger/Log.h"
#include "home_bookkeeping/lib/logger/Initializers/RollingFileInitializer.h"

class Time
{
public:
  Time();
  friend bool CheckDate(int year, int month, int day, int hour, int minute, int second);
  void SetTime();
  int GetSecond() const;
  int GetMinute() const;
  int GetHour() const;
  int GetDay() const;
  int GetMonth() const;
  int GetYear() const;
  void SetSecond(const int second);
  void SetMinute(const int minute);
  void SetHour(const int hour);
  void SetDay(const int day);
  void SetMonth(const int month);
  void SetYear(const int year);
  void SetDate(const int year, const int month, const int day, const int hour, const int minute, const int second);
  std::string GetStringTime() const;
  friend bool operator<(const Time& time_left, const Time& time_right);
  friend std::ostream& operator<<(std::ostream& output_stream, const Time& time);
  friend std::istream& operator>>(std::istream& input_stream, Time& time);
private:
  int SetSecond();
  int SetMinute();
  int SetHour();
  int SetDay();
  int SetMonth();
  int SetYear();
private:
  int second_;
  int minute_;
  int hour_;
  int day_;
  int month_;
  int year_;
};

#endif  //  HOMEBOOKKEEPING_0MODELS_TIME_H_
