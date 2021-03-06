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

class Time
{
public:
  Time();
	void SetTime();
	int GetSecond() const;
	int GetMinute() const;
	int GetHour() const;
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	void SetSecond(const int secondForUpdate);
	void SetMinute(const int minuteForUpdate);
	void SetHour(const int hourForUpdate);
	void SetDay(const int dayForUpdate);
	void SetMonth(const int monthForUpdate);
	void SetYear(const int yearForUpdate);
	friend bool operator<(const Time& time_left, const Time& time_right);
	friend std::ostream& operator<<(std::ostream& outputStream, const Time& time);
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
