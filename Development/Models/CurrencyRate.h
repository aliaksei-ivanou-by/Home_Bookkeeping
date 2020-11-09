#pragma once

#ifndef CURRENCYRATES_H
#define CURRENCYRATES_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class CurrencyRate
{
private:
	std::string name;
public:
	CurrencyRate() : name{ "" } {}
	CurrencyRate(std::string name) : name{ name } {}
	std::string get_name() const
	{
		return this->name;
	}
	void set_name(std::string& name)
	{
		this->name = name;
	}
};

bool operator<(const CurrencyRate& lhs, const CurrencyRate& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

std::ostream& operator<<(std::ostream& os, const CurrencyRate& i)
{
	return os << i.get_name();
}

#endif