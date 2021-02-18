#include "Account.h"

Account::Account():
	accountName{ "" },
	accountLastAmount{ 0 }
{}

Account::Account(const std::string& accountNameForAdd):
	accountName{ accountNameForAdd },
	accountLastAmount{ 0 }
{}

Account::Account(const std::string& accountNameForAdd, double accounAmountForAdd) :
	accountName{ accountNameForAdd },
	accountLastAmount{ accounAmountForAdd }
{}

std::string Account::getAccountName() const
{
	return accountName;
}

void Account::setAccountName(const std::string& accountNameForUpdate)
{
	accountName = accountNameForUpdate;
}

double Account::getAccountAmount() const
{
	return accountLastAmount;
}

void Account::setAccountAmount(double accountAmountForUpdate)
{
	accountLastAmount = accountAmountForUpdate;
}

void Account::updateAccountAmount(const double accountAmoutForUpdate)
{
	accountLastAmount += accountAmoutForUpdate;
}

bool operator<(const Account& leftAccount, const Account& rightAccount)
{
	return (leftAccount.getAccountName()) < (rightAccount.getAccountName());
}

std::ostream& operator<<(std::ostream& outputStream, const Account& account)
{
	return outputStream << account.getAccountName();
}