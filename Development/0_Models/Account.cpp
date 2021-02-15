#include "Account.h"

Account::Account():
	accountName{ "" }
{}

Account::Account(const std::string& accountNameForAdd):
	accountName{ accountNameForAdd }
{}

std::string Account::getAccountName() const
{
	return accountName;
}

void Account::setAccountName(const std::string& accountNameForUpdate)
{
	accountName = accountNameForUpdate;
}

bool operator<(const Account& leftAccount, const Account& rightAccount)
{
	return (leftAccount.getAccountName()) < (rightAccount.getAccountName());
}

std::ostream& operator<<(std::ostream& outputStream, const Account& account)
{
	return outputStream << account.getAccountName();
}