#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Account
{
private:
	std::string accountName;
public:
	Account()
		: accountName{ "" }
	{}
	Account(std::string accountName)
		: accountName{ accountName }
	{}
	std::string getAccountName() const
	{
		return this->accountName;
	}
	void setAccountName(std::string&& accountName)
	{
		this->accountName = accountName;
	}
	friend bool operator<(const Account& leftAccount, const Account& rightAccount)
	{
		return (leftAccount.getAccountName()) < (rightAccount.getAccountName());
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const Account& account)
	{
		return outputStream << account.getAccountName();
	}
};

#endif