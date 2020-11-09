#pragma once

#ifndef TAG_H
#define TAG_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Tag
{
private:
	std::string name;
public:
	Tag() : name{ "" } {}
	Tag(std::string name) : name{ name } {}
	std::string get_name() const
	{
		return this->name;
	}
	void set_name(std::string& name)
	{
		this->name = name;
	}
};

bool operator<(const Tag& lhs, const Tag& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

std::ostream& operator<<(std::ostream& os, const Tag& i)
{
	return os << i.get_name();
}

#endif