#include "AccountRepository.h"

AccountRepository::AccountRepository()
{}

void AccountRepository::add(Account accountForAdd)
{
	repository.insert(std::make_shared<Account>(accountForAdd));
}

void AccountRepository::add(std::shared_ptr<Account> accountForAdd)
{
	repository.insert(accountForAdd);
}

void AccountRepository::remove(std::shared_ptr<Account> accountForRemove)
{
	repository.erase(accountForRemove);
}

size_t AccountRepository::size() const
{
	return repository.size();
}

void AccountRepository::clear()
{
	repository.clear();
}

AccountRepositoryIterator AccountRepository::find(std::shared_ptr<Account> accountForFind) const
{
	return repository.find(accountForFind);
}

AccountRepositoryIterator AccountRepository::begin() const
{
	return repository.begin();
}

AccountRepositoryIterator AccountRepository::end() const
{
	return repository.end();
}