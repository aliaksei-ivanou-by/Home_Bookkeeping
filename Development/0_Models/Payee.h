#pragma once

#include "../include/stdafx.h"

class Payee
{
private:
	std::string payeeName;
public:
	Payee();
	Payee(std::string payeeNameForAdd);
	std::string getPayeeName() const;
	void setPayeeName(std::string&& payeeNameForUpdate);
	friend bool operator<(const Payee& leftPayee, const Payee& rightPayee);
	friend std::ostream& operator<<(std::ostream& outputStream, const Payee& payee);
};