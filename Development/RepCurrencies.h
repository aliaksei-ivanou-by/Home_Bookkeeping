#ifndef REPCURRENCIES_H
#define REPCURRENCIES_H

#include "stdafx.h"

class Currencies
{
private:
	std::string Currency_Name;
	std::string Currency_Code;
	bool Currency_Active;
public:
	Currencies();
	Currencies(std::string name);
	Currencies(std::string name, std::string code);
	Currencies(std::string name, std::string code, bool state);
	std::string get_name() const;
	void set_name(std::string name);
};

class Rep_Currencies
{
private:
	Currencies currencies;
	std::set<Currencies> repository;
public:
	Rep_Currencies();
	void add(std::string currency);
	void remove(std::string currency);
	void print() const;
};

#endif