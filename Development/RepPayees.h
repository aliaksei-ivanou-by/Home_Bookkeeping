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
	std::set<Payees> repository;
public:
	Rep_Payees();
	void add(std::string name);
	void remove(std::string name);
	void print() const;
};

#endif