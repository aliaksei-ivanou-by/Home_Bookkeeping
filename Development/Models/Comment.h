#pragma once

#ifndef COMMENT_H
#define COMMENT_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Comment
{
private:
	std::string name;
public:
	Comment() : name{ "" } {}
	Comment(std::string name) : name{ name } {}
	std::string get_name() const
	{
		return this->name;
	}
	void set_name(std::string&& name)
	{
		this->name = name;
	}
};

bool operator<(const Comment& lhs, const Comment& rhs)
{
	return (lhs.get_name()) < (rhs.get_name());
}

std::ostream& operator<<(std::ostream& os, const Comment& i)
{
	return os << i.get_name();
}

#endif