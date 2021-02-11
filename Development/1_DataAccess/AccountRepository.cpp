#include "AccountRepository.h"

AccountRepository::AccountRepository()
{}

void AccountRepository::addAccount(Account accountForAdd)
{
	accountRepository.insert(accountForAdd);
}

void AccountRepository::removeAccount(Account accountForRemove)
{
	accountRepository.erase(accountForRemove);
}

size_t AccountRepository::sizeAccountRepository()
{
	return accountRepository.size();
}