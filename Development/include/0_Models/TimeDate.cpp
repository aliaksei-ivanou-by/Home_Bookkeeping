#include "include/0_Models/TimeDate.h"

TimeDate::TimeDate():
  second_{ SetSecond() },
  minute_{ SetMinute() },
  hour_{ SetHour() },
  day_{ SetDay() },
  month_{ SetMonth() },
  year_{ SetYear() }
{}

bool CheckDate(int year, int month, int day, int hour, int minute, int second)
{
  if (second > 60 || second < 1)
  {
    return false;
  }
  if (minute > 60 || minute < 1)
  {
    return false;
  }
  if (hour > 24 || hour < 1)
  {
    return false;
  }
  if (day > 31 || day < 1)
  {
    return false;
  }
  if (month > 12 || month < 1)
  {
    return false;
  }
  if (year <= 0)
  {
    return false;
  }
  if (month == 2)
  {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
      return (day <= 29);
    }
    else
    {
      return (day <= 28);
    }
  }
  if (month == 4 || month == 6 || month == 9 || month == 11)
  {
    return (day <= 30);
  }
  return true;
}

int TimeDate::SetSecond()
{
  std::time_t result = std::time(nullptr);
  struct tm time_new;
  time_t time_now = time(NULL);
  localtime_s(&time_new, &time_now);
  int seconds = time_new.tm_sec;
  return seconds;
}

int TimeDate::SetMinute()
{
  struct tm time_new;
  time_t time_now = time(NULL);
  localtime_s(&time_new, &time_now);
  int minute = time_new.tm_min;
  return minute;
}

int TimeDate::SetHour()
{
  struct tm time_new;
  time_t time_now = time(NULL);
  localtime_s(&time_new, &time_now);
  int hours = time_new.tm_hour;
  return hours;
}

int TimeDate::SetDay()
{
  struct tm time_new;
  time_t time_now = time(NULL);
  localtime_s(&time_new, &time_now);
  int days = time_new.tm_mday;
  return days;
}

int TimeDate::SetMonth()
{
  struct tm time_new;
  time_t time_now = time(NULL);
  localtime_s(&time_new, &time_now);
  int month = time_new.tm_mon;
  return month + 1;
}

int TimeDate::SetYear()
{
  struct tm time_new;
  time_t time_now = time(NULL);
  localtime_s(&time_new, &time_now);
  int year = time_new.tm_year + 1900;
  return year;
}

void TimeDate::SetTime()
{
  TimeDate time;
  *this = time;
  PLOG_INFO << "Set new daytime";
}

int TimeDate::GetSecond() const
{
  return second_;
}

int TimeDate::GetMinute() const
{
  return minute_;
}

int TimeDate::GetHour() const
{
  return hour_;
}

int TimeDate::GetDay() const
{
  return day_;
}

int TimeDate::GetMonth() const
{
  return month_;
}

int TimeDate::GetYear() const
{
  return year_;
}

void TimeDate::SetSecond(const int second)
{
  if (CheckDate(year_, month_, day_, hour_, minute_, second))
  {
    second_ = second;
  }
  PLOG_INFO << "Set new second";
}

void TimeDate::SetMinute(const int minute)
{
  if (CheckDate(year_, month_, day_, hour_, minute, second_))
  {
    minute_ = minute;
  }
}

void TimeDate::SetHour(const int hour)
{
  if (CheckDate(year_, month_, day_, hour, minute_, second_))
  {
    hour_ = hour;
  }
  PLOG_INFO << "Set new hour";
}

void TimeDate::SetDay(const int day)
{
  if (CheckDate(year_, month_, day, hour_, minute_, second_))
  {
    day_ = day;
  }
  PLOG_INFO << "Set new day";
}

void TimeDate::SetMonth(const int month)
{
  if (CheckDate(year_, month, day_, hour_, minute_, second_))
  {
    month_ = month;
  }
  PLOG_INFO << "Set new month";
}

void TimeDate::SetYear(const int year)
{
  if (CheckDate(year, month_, day_, hour_, minute_, second_))
  {
    year_ = year;
  }
  PLOG_INFO << "Set new year";
}

void TimeDate::SetDate(const int year, const int month, const int day, const int hour, const int minute, const int second)
{
  if (CheckDate(year, month, day, hour, minute, second))
  {
    year_ = year;
    month_ = month;
    day_ = day;
    hour_ = hour;
    minute_ = minute;
    second_ = second;
  }
  PLOG_INFO << "Set new daytime";
}

std::string TimeDate::GetStringTime() const
{
  std::stringstream string_stream;
  string_stream << *this;
  return string_stream.str();
}

bool operator<(const TimeDate& time_left, const TimeDate& time_right)
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
                      return time_left.second_ < time_right.second_;
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

bool operator==(const TimeDate& time_left, const TimeDate& time_right)
{
  return ((time_left.year_ == time_right.year_) && 
    (time_left.month_ == time_right.month_) &&
    (time_left.day_ == time_right.day_) &&
    (time_left.hour_ == time_right.hour_) &&
    (time_left.minute_ == time_right.minute_) &&
    (time_left.second_ == time_right.second_));
}

bool operator!=(const TimeDate& time_left, const TimeDate& time_right)
{
  return (!(time_left == time_right));
}

std::ostream& operator<<(std::ostream& outputStream, const TimeDate& time)
{
  // "YYYY-MM-DD HH:MM:SS"
  return outputStream <<
    time.year_ <<
    '-' <<
    (time.month_ < 10 ? "0" : "") << time.month_ <<
    '-' <<
    (time.day_ < 10 ? "0" : "") << time.day_ <<
    '_' <<
    (time.hour_ < 10 ? "0" : "") << time.hour_ <<
    '-' <<
    (time.minute_ < 10 ? "0" : "") << time.minute_ <<
    '-' <<
    (time.second_ < 10 ? "0" : "") << time.second_;
}

std::istream& operator>>(std::istream& input_stream, TimeDate& time)
{
  // "YYYY-MM-DD HH:MM:SS"
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
  char delimeter_day_1;
  char delimeter_day_2;
  char delimeter_time_1;
  char delimeter_time_2;
  constexpr char kDelimeterDay = ':';
  constexpr char kDelimeterTime = ':';
  if (!input_stream)
  {
    return input_stream;
  }
  input_stream >> year >> delimeter_day_1 >> month >> delimeter_day_2 >> day;
  if (!input_stream)
  {
    return input_stream;
  }
  if (delimeter_day_1 != kDelimeterDay || delimeter_day_2 != kDelimeterDay)
  {
    return input_stream;
  }
  input_stream >> hour >> delimeter_time_1 >> minute >> delimeter_time_2 >> second;
  if (!input_stream)
  {
    return input_stream;
  }
  if (delimeter_time_1 != kDelimeterTime || delimeter_time_2 != kDelimeterTime)
  {
    return input_stream;
  }
  if (CheckDate(year, month, day, hour, minute, second))
  {
    time.SetDate(year, month, day, hour, minute, second);
  }
}
