#pragma once
#include "../include/stdafx.h"

/*
Class Time
Includes second, minute, hour, day, month, year.

Constructors:
	Default (current time and current date)

Class member functions:
	Set current second of the time
	Set current minute of the time
	Set current hour of the time
	Set current day of the time
	Set current month of the time
	Set current year of the time
	Set surrent time and current date of the time
	Get second of the time
	Get minute of the time
	Get hour of the time
	Get day of the time
	Get month of the time
	Get year of the time
	Set second of the time
	Set minute of the time
	Set hour of the time
	Set day of the time
	Set month of the time
	Set year of the time
	Operator < for sorting times
	Print time
Will be updated:
	Check the date for correctness
*/

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

	void setTime();

	int getSecond() const;
	int getMinute() const;
	int getHour() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void setSecond(const int secondForUpdate);
	void setMinute(const int minuteForUpdate);
	void setHour(const int hourForUpdate);
	void setDay(const int dayForUpdate);
	void setMonth(const int monthForUpdate);
	void setYear(const int yearForUpdate);

	friend bool operator<(const Time& leftTime, const Time& rightTime);
	friend std::ostream& operator<<(std::ostream& outputStream, const Time& time);
};