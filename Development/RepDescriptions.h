#ifndef REPDESCRIPTIONS_H
#define REPDESCRIPTIONS_H

#include "stdafx.h"

class Descriptions
{
private:
	std::string Description_Name;
public:
	Descriptions();
	Descriptions(std::string name);
	std::string get_name() const;
	void set_name(std::string name);
};

class Rep_Descriptions
{
private:
	Descriptions descriptions;
	std::set<Descriptions> repository;
public:
	Rep_Descriptions();
	void add(std::string tag);
	void remove(std::string tag);
	void print() const;
};

#endif