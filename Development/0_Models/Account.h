#pragma once

#include "../include/stdafx.h"

class Account
{
private:
	std::string accountName;
public:
	Account();
	Account(const std::string& accountNameForAdd);
	std::string getAccountName() const;
	void setAccountName(const std::string& accountNameForUpdate);
	friend bool operator<(const Account& leftAccount, const Account& rightAccount);
	friend std::ostream& operator<<(std::ostream& outputStream, const Account& account);
};