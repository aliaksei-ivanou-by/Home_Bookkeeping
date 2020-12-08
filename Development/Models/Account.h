#pragma once

#include "../include/stdafx.h"

class Account
{
private:
	std::string accountName;
public:
	Account();
	Account(std::string accountNameForAdd);
	std::string getAccountName() const;
	void setAccountName(std::string&& accountNameForUpdate);
	friend bool operator<(const Account& leftAccount, const Account& rightAccount);
	friend std::ostream& operator<<(std::ostream& outputStream, const Account& account);
};