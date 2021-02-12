#include "AccountRepository.h"

AccountRepository::AccountRepository()
{}

void AccountRepository::add(Account accountForAdd)
{
	repository.insert(accountForAdd);
}

void AccountRepository::remove(Account accountForRemove)
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

AccountRepositoryIterator AccountRepository::find(Account&& accountForFind) const
{
	return repository.find(std::move(accountForFind));
}