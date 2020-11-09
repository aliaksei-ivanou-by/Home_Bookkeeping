#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Account
{
private:
	std::string name;
public:
	Account() : name{ "" } {}
	Account(std::string name) : name{ name } {}
	std::string get_name() const
	{
		return this->name;
	}
	void set_name(std::string&& name)
	{
		this->name = name;
	}
};

bool operator<(const Account& lhs, const Account& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

std::ostream& operator<<(std::ostream& os, const Account& i)
{
	return os << i.get_name();
}

#endif