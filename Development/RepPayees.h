#ifndef REPPAYEES_H
#define REPPAYEES_H

#include "stdafx.h"

class Payees
{
private:
	std::string Payee_Name;
public:
	Payees();
	Payees(std::string name);
	std::string get_name() const;
	void set_name(std::string name);
};

class Rep_Payees
{
private:
	Payees payees;
	std::set<Payees> repository;
public:
	Rep_Payees();
	void add(std::string tag);
	void remove(std::string tag);
	void print() const;
};

#endif