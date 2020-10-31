#ifndef REPSUBCATEGORIES_H
#define REPSUBCATEGORIES_H

#include "stdafx.h"

class SubCategories
{
private:
	std::string SubCategory_Name;
public:
	SubCategories();
	SubCategories(std::string name);
	std::string get_name() const;
	void set_name(std::string name);
};

class Rep_SubCategories
{
private:
	SubCategories subcategories;
	std::set<SubCategories> repository;
public:
	Rep_SubCategories();
	void add(std::string tag);
	void remove(std::string tag);
	void print() const;
};

#endif