#pragma once

#ifndef CURRENCY_H
#define CURRENCY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Currency
{
private:
	std::string name;
	std::string code;
	bool active;
public:
	Currency() : name{ "" }, code{ "" }, active{ true } {}
	Currency(std::string name) : name{ name }, code{ "" }, active{ true } {}
	Currency(std::string name, std::string code) : name{ name }, code{ code }, active{ true } {}
	Currency(std::string name, std::string code, bool state) : name{ name }, code{ code }, active{ state } {}
	std::string get_name() const
	{
		return this->name;
	}
	std::string get_code() const
	{
		return this->code;
	}
	bool get_active() const
	{
		return this->active;
	}
	void set_name(std::string&& name)
	{
		this->name = name;
	}
};

bool operator<(const Currency& lhs, const Currency& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

std::ostream& operator<<(std::ostream& os, const Currency& i)
{
	return os << i.get_name() << '\t' << i.get_code() << '\t' << i.get_active();
}

#endif