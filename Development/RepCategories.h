#ifndef REPCATEGORIES_H
#define REPCATEGORIES_H

#include "stdafx.h"

class Categories
{
private:
	std::string Category_Name;
public:
	Categories();
	Categories(std::string name);
	std::string get_name() const;
	void set_name(std::string name);
};

class Rep_Categories
{
private:
	Categories categories;
	std::set<Categories> repository;
public:
	Rep_Categories();
	void add(std::string tag);
	void remove(std::string tag);
	void print() const;
};

#endif