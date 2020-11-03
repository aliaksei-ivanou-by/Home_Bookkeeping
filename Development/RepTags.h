#ifndef REPTAGS_H
#define REPTAGS_H

#include "stdafx.h"

class Tags
{
private:
	std::string Tag_Name;
public:
	Tags();
	Tags(std::string name);
	std::string get_name() const;
	void set_name(std::string name);
};

class Rep_Tags
{
private:
	std::set<Tags> repository;
public:
	Rep_Tags();
	void add(std::string name);
	void remove(std::string name);
	void print() const;
};

#endif