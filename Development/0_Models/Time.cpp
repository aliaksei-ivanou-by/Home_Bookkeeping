#include "Time.h"

// Default constructor
Time::Time():
	timeSecond{ setSecond() },
	timeMinute{ setMinute() },
	timeHour{ setHour() },
	timeDay{ setDay() },
	timeMonth{ setMonth() },
	timeYear{ setYear() }
{}

// Class member function. Set current second of the time
int Time::setSecond()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int seconds = newtime.tm_sec;
	return seconds;
}

// Class member function. Set current minute of the time
int Time::setMinute()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int minute = newtime.tm_min;
	return minute;
}

// Class member function. Set current hour of the time
int Time::setHour()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int hours = newtime.tm_hour;
	return hours;
}

// Class member function. Set current day of the time
int Time::setDay()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int days = newtime.tm_mday;
	return days;
}

// Class member function. Set current month of the time
int Time::setMonth()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int month = newtime.tm_mon;
	return month + 1;
}

// Class member function. Set current year of the time
int Time::setYear()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int year = newtime.tm_year + 1900;
	return year;
}

// Class member function. Set surrent time and current date of the time
void Time::setTime()
{
	Time time;
	*this = time;
}

// Class member function. Get second of the time
int Time::getSecond() const
{
	return timeSecond;
}

// Class member function. Get minute of the time
int Time::getMinute() const
{
	return timeMinute;
}

// Class member function. Get hour of the time
int Time::getHour() const
{
	return timeHour;
}

// Class member function. Get day of the time
int Time::getDay() const
{
	return timeDay;
}

// Class member function. Get month of the time
int Time::getMonth() const
{
	return timeMonth;
}

// Class member function. Get year of the time
int Time::getYear() const
{
	return timeYear;
}

// Class member function. Set second of the time
void Time::setSecond(const int secondForUpdate)
{
	if (secondForUpdate > 60 || secondForUpdate < 1)
	{
		return;
	}
	timeSecond = secondForUpdate;
}

// Class member function. Set minute of the time
void Time::setMinute(const int minuteForUpdate)
{
	if (minuteForUpdate > 60 || minuteForUpdate < 1)
	{
		return;
	}
	timeMinute = minuteForUpdate;
}

// Class member function. Set hour of the time
void Time::setHour(const int hourForUpdate)
{
	if (hourForUpdate > 24 || hourForUpdate < 1)
	{
		return;
	}
	timeHour = hourForUpdate;
}

// Class member function. Set day of the time
void Time::setDay(const int dayForUpdate)
{
	if (dayForUpdate > 31 || dayForUpdate < 1)
	{
		return;
	}
	timeDay = dayForUpdate;
}

// Class member function. Set month of the time
void Time::setMonth(const int monthForUpdate)
{
	if (monthForUpdate > 12 || monthForUpdate < 1)
	{
		return;
	}
	timeMonth = monthForUpdate;
}

// Class member function. Set year of the time
void Time::setYear(const int yearForUpdate)
{
	timeYear = yearForUpdate;
}

// Class member function. Operator < for sorting times
bool operator<(const Time& leftTime, const Time& rightTime)
{
	if (leftTime.getYear() < rightTime.getYear())
	{
		return true;
	}
	else
	{
		if (leftTime.getYear() > rightTime.getYear())
		{
			return false;
		}
		else
		{
			if (leftTime.getMonth() < rightTime.getMonth())
			{
				return true;
			}
			else
			{
				if (leftTime.getMonth() > rightTime.getMonth())
				{
					return false;
				}
				else
				{
					if (leftTime.getDay() < rightTime.getDay())
					{
						return true;
					}
					else
					{
						if (leftTime.getDay() > rightTime.getDay())
						{
							return false;
						}
						else
						{
							if (leftTime.getHour() < rightTime.getHour())
							{
								return true;
							}
							else
							{
								if (leftTime.getHour() > rightTime.getHour())
								{
									return false;
								}
								else
								{
									if (leftTime.getMinute() < rightTime.getMinute())
									{
										return true;
									}
									else
									{
										if (leftTime.getMinute() > rightTime.getMinute())
										{
											return false;
										}
										else
										{
											if (leftTime.getSecond() < rightTime.getSecond())
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

// Class member function. Print time
std::ostream& operator<<(std::ostream& outputStream, const Time& time)
{
	return outputStream << time.timeYear << '.' <<
							(time.timeMonth < 10 ? "0" : "") <<
							time.timeMonth << '.' <<
							(time.timeDay < 10 ? "0" : "") << 
							time.timeDay << ' ' <<
							(time.timeHour < 10 ? "0" : "") <<
							time.timeHour << ':' <<
							(time.timeMinute < 10 ? "0" : "") <<
							time.timeMinute << ':' <<
							(time.timeSecond < 10 ? "0" : "") <<
							time.timeSecond;
}