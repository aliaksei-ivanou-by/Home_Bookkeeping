#pragma once

#ifndef CATEGORYSUB_H
#define CATEGORYSUB_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class CategorySub
{
private:
	std::string name;
public:
	CategorySub() : name{ "" } {}
	CategorySub(std::string name) : name{ name } {}
	std::string get_name() const
	{
		return this->name;
	}
	void set_name(std::string&& name)
	{
		this->name = name;
	}
};

bool operator<(const CategorySub& lhs, const CategorySub& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

std::ostream& operator<<(std::ostream& os, const CategorySub& i)
{
	return os << i.get_name();
}

#endif