#pragma once
#include "../include/stdafx.h"
#include "Currency.h"

/*
Class Account
Includes account name, current account balance, account currency.

Constructors:
	With the assignment of the name of the account
	With the setting of the name of the account and the initial balance

Class member functions:
	Get the name of the account
	Get the current account balance
	Set the name of the account
	Set the current account balance
	Update the current account balance
	Operator < for sorting accounts
	Print account
*/

class Account
{
private:
	std::string accountName;
	double accountLastAmount;
	//Currency accountCurrency;
public:
	Account() = delete;
	Account(const std::string& accountNameForAdd);
	Account(const std::string& accountNameForAdd, double accounAmountForAdd);

	std::string getAccountName() const;
	double getAccountAmount() const;

	void setAccountName(const std::string& accountNameForUpdate);
	void setAccountAmount(const double accountAmountForUpdate);

	void updateAccountAmount(const double accountAmoutForUpdate);

	friend bool operator<(const Account& leftAccount, const Account& rightAccount);
	friend std::ostream& operator<<(std::ostream& outputStream, const Account& account);
};