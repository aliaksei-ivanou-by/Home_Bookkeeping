#pragma once

#ifndef PAYEE_H
#define PAYEE_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Payee
{
private:
	std::string name;
public:
	Payee() : name{ "" } {}
	Payee(std::string name) : name{ name } {}
	std::string get_name() const
	{
		return this->name;
	}
	void set_name(std::string&& name)
	{
		this->name = name;
	}
};

bool operator<(const Payee& lhs, const Payee& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

std::ostream& operator<<(std::ostream& os, const Payee& i)
{
	return os << i.get_name();
}

#endif