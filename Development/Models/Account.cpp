#include "Account.h"

Account::Account():
	accountName{ "" }
{}

Account::Account(std::string accountNameNew):
	accountName{ accountNameNew }
{}

std::string Account::getAccountName() const
{
	return accountName;
}

void Account::setAccountName(std::string&& accountNameNew)
{
	accountName = std::move(accountNameNew);
}

bool operator<(const Account& leftAccount, const Account& rightAccount)
{
	return (leftAccount.getAccountName()) < (rightAccount.getAccountName());
}

std::ostream& operator<<(std::ostream& outputStream, const Account& account)
{
	return outputStream << account.getAccountName();
}