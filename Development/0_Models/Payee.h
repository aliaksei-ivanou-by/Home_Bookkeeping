#pragma once
#include "../include/stdafx.h"

/*
Class Payee
Includes payee name.

Constructors:
	Default (name of the payee is empty)
	With the setting of the name of the payee

Class member functions:
	Get the name of the payee
	Set the name of the payee
	Operator < for sorting payees
	Print payee
*/
class Payee
{
private:
	std::string payeeName;
public:
	Payee();
	Payee(const std::string& payeeNameForAdd);

	std::string getPayeeName() const;

	void setPayeeName(const std::string& payeeNameForUpdate);

	friend bool operator<(const Payee& leftPayee, const Payee& rightPayee);
	friend std::ostream& operator<<(std::ostream& outputStream, const Payee& payee);
};