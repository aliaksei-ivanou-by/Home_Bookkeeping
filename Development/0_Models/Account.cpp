#include "Account.h"

// Constructors with the assignment of the name of the account
Account::Account(const std::string& accountNameForAdd):
	accountName{ accountNameForAdd },
	accountLastAmount{ 0 }
{}

// Constructor with the setting of the name of the account and the initial balance
Account::Account(const std::string& accountNameForAdd, double accounAmountForAdd):
	accountName{ accountNameForAdd },
	accountLastAmount{ accounAmountForAdd }
{}

// Class member function. Get the name of the account
std::string Account::getAccountName() const
{
	return accountName;
}

// Class member function. Get the current account balance
double Account::getAccountAmount() const
{
	return accountLastAmount;
}

// Class member function. Set the name of the account
void Account::setAccountName(const std::string& accountNameForUpdate)
{
	accountName = accountNameForUpdate;
}

// Class member function. Set the current account balance
void Account::setAccountAmount(const double accountAmountForUpdate)
{
	accountLastAmount = accountAmountForUpdate;
}

// Class member function. Update the current account balance
void Account::updateAccountAmount(const double accountAmoutForUpdate)
{
	accountLastAmount += accountAmoutForUpdate;
}

// Class member function. Operator < for sorting accounts
bool operator<(const Account& leftAccount, const Account& rightAccount)
{
	return (leftAccount.getAccountName()) < (rightAccount.getAccountName());
}

// Class member function. Print account
std::ostream& operator<<(std::ostream& outputStream, const Account& account)
{
	return outputStream << account.getAccountName();
}