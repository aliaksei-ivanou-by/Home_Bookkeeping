#pragma once

#include "../include/stdafx.h"

class Time
{
private:
	int timeSecond;
	int timeMinute;
	int timeHour;
	int timeDay;
	int timeMonth;
	int timeYear;

	int setSecond();
	int setMinute();
	int setHour();
	int setDay();
	int setMonth();
	int setYear();
public:
	Time();
	int getSecond() const;
	int getMinute() const;
	int getHour() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void updateSecond(int secondForUpdate);
	void updateMinute(int minuteForUpdate);
	void updateHour(int hourForUpdate);
	void updateDay(int dayForUpdate);
	void updateMonth(int monthForUpdate);
	void updateYear(int yearForUpdate);
	friend bool operator<(const Time& leftTime, const Time& rightTime);
	friend std::ostream& operator<<(std::ostream& outputStream, const Time& time);
};