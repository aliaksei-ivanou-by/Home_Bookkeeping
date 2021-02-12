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

size_t AccountRepository::sizeAccountRepository() const
{
	return accountRepository.size();
}

void AccountRepository::clearAccountRepository()
{
	accountRepository.clear();
}

AccountRepositoryIterator AccountRepository::findAccountRepository(Account&& accountForFind) const
{
	return accountRepository.find(std::move(accountForFind));
}