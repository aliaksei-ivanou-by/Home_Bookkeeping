#ifndef REPACCOUNTS_H
#define REPACCOUNTS_H

#include "stdafx.h"

class Accounts
{
private:
	std::string Account_Name;
public:
	Accounts();
	Accounts(std::string name);
	std::string get_name() const;
	void set_name(std::string name);
};

class Rep_Accounts
{
private:
	std::set<Accounts> repository;
public:
	Rep_Accounts();
	void add(std::string name);
	void remove(std::string name);
	void print() const;
};

#endif