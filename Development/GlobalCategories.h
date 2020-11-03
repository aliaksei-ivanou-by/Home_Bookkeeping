#ifndef GLOBALCATEGORIES_H
#define GLOBALCATEGORIES_H

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
	//void add_subcategory();
};

class Rep_Categories
{
private:
	std::set<Categories> repository;
public:
	Rep_Categories();
	void add(std::string name);
	void remove(std::string name);
	void print() const;
};

#endif