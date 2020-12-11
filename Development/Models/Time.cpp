#include "Time.h"

Time::Time():
	timeSecond{ setSecond() },
	timeMinute{ setMinute() },
	timeHour{ setHour() },
	timeDay{ setDay() },
	timeMonth{ setMonth() },
	timeYear{ setYear() }
{}

int Time::setSecond()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int seconds = newtime.tm_sec;
	return seconds;
}

int Time::setMinute()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int minute = newtime.tm_min;
	return minute;
}

int Time::setHour()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int hours = newtime.tm_hour;
	return hours;
}

int Time::setDay()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int days = newtime.tm_mday;
	return days;
}

int Time::setMonth()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int month = newtime.tm_mon;
	return month + 1;
}

int Time::setYear()
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	int year = newtime.tm_year + 1900;
	return year;
}

void Time::setTime()
{
	Time time;
	*this = time;
}

int Time::getSecond() const
{
	return timeSecond;
}

int Time::getMinute() const
{
	return timeMinute;
}

int Time::getHour() const
{
	return timeHour;
}

int Time::getDay() const
{
	return timeDay;
}

int Time::getMonth() const
{
	return timeMonth;
}

int Time::getYear() const
{
	return timeYear;
}

void Time::setSecond(int secondForUpdate)
{
	if (secondForUpdate > 60 || secondForUpdate < 1)
	{
		return;
	}
	timeSecond = secondForUpdate;
}

void Time::setMinute(int minuteForUpdate)
{
	if (minuteForUpdate > 60 || minuteForUpdate < 1)
	{
		return;
	}
	timeMinute = minuteForUpdate;
}

void Time::setHour(int hourForUpdate)
{
	if (hourForUpdate > 24 || hourForUpdate < 1)
	{
		return;
	}
	timeHour = hourForUpdate;
}

void Time::setDay(int dayForUpdate)
{
	if (dayForUpdate > 31 || dayForUpdate < 1)
	{
		return;
	}
	timeDay = dayForUpdate;
}

void Time::setMonth(int monthForUpdate)
{
	if (monthForUpdate > 12 || monthForUpdate < 1)
	{
		return;
	}
	timeMonth = monthForUpdate;
}

void Time::setYear(int yearForUpdate)
{
	timeYear = yearForUpdate;
}

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
	std::to_string(1);
}

std::ostream& operator<<(std::ostream& outputStream, const Time& time)
{
	return outputStream << time.getYear() << '.' <<
							time.getMonth() << '.' <<
							(time.getDay() < 10 ? "0" : "") << 
							time.getDay() << ' ' <<
							(time.getHour() < 10 ? "0" : "") <<
							time.getHour() << ':' <<
							(time.getMinute() < 10 ? "0" : "") <<
							time.getMinute() << ':' <<
							(time.getSecond() < 10 ? "0" : "") <<
							time.getSecond();
}