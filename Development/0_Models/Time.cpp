#include "home_bookkeeping/0_Models/Time.h"

//  Constructor
//  Default (current time and current date)
Time::Time():
  second_{ SetSecond() },
  minute_{ SetMinute() },
  hour_{ SetHour() },
  day_{ SetDay() },
  month_{ SetMonth() },
  year_{ SetYear() }
{}

//  Class member function
//  Set current second
int Time::SetSecond()
{
	struct tm time_new;
	time_t time_now = time(NULL);
	localtime_s(&time_new, &time_now);
	int seconds = time_new.tm_sec;
	return seconds;
}

//  Class member function
//  Set current minute
int Time::SetMinute()
{
  struct tm time_new;
  time_t time_now = time(NULL);
  localtime_s(&time_new, &time_now);
  int minute = time_new.tm_min;
  return minute;
}

//  Class member function
//  Set current hour
int Time::SetHour()
{
  struct tm time_new;
  time_t time_now = time(NULL);
  localtime_s(&time_new, &time_now);
  int hours = time_new.tm_hour;
  return hours;
}

//  Class member function
//  Set current day
int Time::SetDay()
{
  struct tm time_new;
  time_t time_now = time(NULL);
  localtime_s(&time_new, &time_now);
  int days = time_new.tm_mday;
  return days;
}

//  Class member function
//  Set current month
int Time::SetMonth()
{
  struct tm time_new;
  time_t time_now = time(NULL);
  localtime_s(&time_new, &time_now);
  int month = time_new.tm_mon;
  return month + 1;
}

//  Class member function
//  Set current year
int Time::SetYear()
{
  struct tm time_new;
  time_t time_now = time(NULL);
  localtime_s(&time_new, &time_now);
  int year = time_new.tm_year + 1900;
  return year;
}

//  Class member function
//  Set surrent time and current date
void Time::SetTime()
{
  Time time;
  *this = time;
}

//  Class member function
//  Get second
int Time::GetSecond() const
{
  return second_;
}

//  Class member function
//  Get minute
int Time::GetMinute() const
{
  return minute_;
}

//  Class member function
//  Get hour
int Time::GetHour() const
{
  return hour_;
}

//  Class member function
//  Get day
int Time::GetDay() const
{
  return day_;
}

//  Class member function
//  Get month
int Time::GetMonth() const
{
  return month_;
}

//  Class member function
//  Get year
int Time::GetYear() const
{
  return year_;
}

//  Class member function
//  Set second
void Time::SetSecond(const int second)
{
  if (second > 60 || second < 1)
  {
    return;
  }
  second_ = second;
}

//  Class member function
//  Set minute
void Time::SetMinute(const int minute)
{
  if (minute > 60 || minute < 1)
  {
    return;
  }
  minute_ = minute;
}

//  Class member function
//  Set hour
void Time::SetHour(const int hour)
{
  if (hour > 24 || hour < 1)
  {
    return;
  }
  hour_ = hour;
}

//  Class member function
//  Set day
void Time::SetDay(const int day)
{
  if (day > 31 || day < 1)
  {
    return;
  }
  day_ = day;
}

//  Class member function
//  Set month
void Time::SetMonth(const int month)
{
  if (month > 12 || month < 1)
  {
    return;
  }
  month_ = month;
}

//  Class member function
//  Set year
void Time::SetYear(const int year)
{
  year_ = year;
}

//  Class member function
//  Operator < for sorting times (by day and time)
bool operator<(const Time& time_left, const Time& time_right)
{
	if (time_left.year_ < time_right.year_)
	{
		return true;
	}
	else
	{
		if (time_left.year_ > time_right.year_)
		{
			return false;
		}
		else
		{
			if (time_left.month_ < time_right.month_)
			{
				return true;
			}
			else
			{
				if (time_left.month_ > time_right.month_)
				{
					return false;
				}
				else
				{
					if (time_left.day_ < time_right.day_)
					{
						return true;
					}
					else
					{
						if (time_left.day_ > time_right.day_)
						{
							return false;
						}
						else
						{
							if (time_left.hour_ < time_right.hour_)
							{
								return true;
							}
							else
							{
								if (time_left.hour_ > time_right.hour_)
								{
									return false;
								}
								else
								{
									if (time_left.minute_ < time_right.minute_)
									{
										return true;
									}
									else
									{
										if (time_left.minute_ > time_right.minute_)
										{
											return false;
										}
										else
										{
											if (time_left.second_ < time_right.second_)
											{
												return true;
											}
											else
											{
												return false;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}

//  Class member function
//  Output time (year, month, day, hour, minute, second -> "YYYY-MM-DD HH:MM:SS")
std::ostream& operator<<(std::ostream& outputStream, const Time& time)
{
  return outputStream <<
    time.year_ <<
    '-' <<
    (time.month_ < 10 ? "0" : "") << time.month_ <<
    '-' <<
    (time.day_ < 10 ? "0" : "") << time.day_ <<
    ' ' <<
    (time.hour_ < 10 ? "0" : "") << time.hour_ <<
    ':' <<
    (time.minute_ < 10 ? "0" : "") << time.minute_ <<
    ':' <<
    (time.second_ < 10 ? "0" : "") << time.second_;
}