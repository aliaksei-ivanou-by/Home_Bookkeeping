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

std::set<Account> AccountRepository::getAccountRepository() const
{
	return accountRepository;
}

void AccountRepository::setAccountRepository(std::set<Account>&& accountsForAdd)
{
	accountRepository = accountsForAdd;
}