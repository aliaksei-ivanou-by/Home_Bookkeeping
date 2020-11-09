#pragma once

#ifndef CATEGORY_H
#define CATEGORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Category
{
private:
	std::string name;
public:
	Category() : name{ "" } {}
	Category(std::string name) : name{ name } {}
	std::string get_name() const
	{
		return this->name;
	}
	void set_name(std::string&& name)
	{
		this->name = name;
	}
};

bool operator<(const Category& lhs, const Category& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

std::ostream& operator<<(std::ostream& os, const Category& i)
{
	return os << i.get_name();
}

#endif