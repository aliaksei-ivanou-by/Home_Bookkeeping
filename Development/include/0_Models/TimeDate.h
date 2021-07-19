#ifndef HOMEBOOKKEEPING_0MODELS_TIMEDATE_H_
#define HOMEBOOKKEEPING_0MODELS_TIMEDATE_H_

#include <iostream>
#include <string>

#include "lib/logger/Log.h"
#include "lib/logger/Initializers/RollingFileInitializer.h"

class TimeDate
{
public:
  TimeDate();
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
  friend bool operator<(const TimeDate& time_left, const TimeDate& time_right);
  friend bool operator==(const TimeDate& time_left, const TimeDate& time_right);
  friend bool operator!=(const TimeDate& time_left, const TimeDate& time_right);
  friend std::ostream& operator<<(std::ostream& output_stream, const TimeDate& time);
  friend std::istream& operator>>(std::istream& input_stream, TimeDate& time);
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

#endif
