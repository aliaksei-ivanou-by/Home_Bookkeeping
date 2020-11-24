#pragma once

#ifndef PAYEE_H
#define PAYEE_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Payee
{
private:
	std::string payeeName;
public:
	Payee()
		: payeeName{ "" }
	{}
	Payee(std::string payeeName)
		: payeeName{ payeeName }
	{}
	std::string getPayeeName() const
	{
		return this->payeeName;
	}
	void setPayeeName(std::string&& payeeName)
	{
		this->payeeName = payeeName;
	}
	friend bool operator<(const Payee& leftPayee, const Payee& rightPayee)
	{
		return (leftPayee.getPayeeName()) < (rightPayee.getPayeeName());
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const Payee& payee)
	{
		return outputStream << payee.getPayeeName();
	}
};

#endif