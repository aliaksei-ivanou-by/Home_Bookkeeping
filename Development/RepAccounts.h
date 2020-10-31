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
	Accounts accounts;
	std::set<Accounts> repository;
public:
	Rep_Accounts();
	void add(std::string tag);
	void remove(std::string tag);
	void print() const;
};

#endif