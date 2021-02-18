#pragma once

#include "../include/stdafx.h"

class Account
{
private:
	std::string accountName;
	double accountLastAmount;
public:
	Account();
	Account(const std::string& accountNameForAdd);
	Account(const std::string& accountNameForAdd, double accounAmountForAdd);
	std::string getAccountName() const;
	void setAccountName(const std::string& accountNameForUpdate);
	double getAccountAmount() const;
	void setAccountAmount(double accountAmountForUpdate);
	void updateAccountAmount(const double accountAmoutForUpdate);
	friend bool operator<(const Account& leftAccount, const Account& rightAccount);
	friend std::ostream& operator<<(std::ostream& outputStream, const Account& account);
};