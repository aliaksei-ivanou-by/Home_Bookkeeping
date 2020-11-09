#pragma once

#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Description
{
private:
	std::string name;
public:
	Description() : name{ "" } {}
	Description(std::string name) : name{ name } {}
	std::string get_name() const
	{
		return this->name;
	}
	void set_name(std::string& name)
	{
		this->name = name;
	}
};

bool operator<(const Description& lhs, const Description& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

std::ostream& operator<<(std::ostream& os, const Description& i)
{
	return os << i.get_name();
}

#endif