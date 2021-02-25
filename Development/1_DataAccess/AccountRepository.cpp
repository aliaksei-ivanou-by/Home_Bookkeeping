#include "AccountRepository.h"

// Default constructor
AccountRepository::AccountRepository()
{}

// Class member function. Add account to repository
void AccountRepository::add(Account accountForAdd)
{
	repository.insert(std::make_shared<Account>(accountForAdd));
}

// Class member function. Add shared pointer to account to repository
void AccountRepository::add(std::shared_ptr<Account> accountForAdd)
{
	repository.insert(accountForAdd);
}

// Class member function. Remove shared pointer to account from repository
void AccountRepository::remove(std::shared_ptr<Account> accountForRemove)
{
	repository.erase(accountForRemove);
}

// Class member function. Calculate size of repository
size_t AccountRepository::size() const
{
	return repository.size();
}

// Class member function. Clear repository
void AccountRepository::clear()
{
	repository.clear();
}

// Class member function. Find shared pointer to account in repository
AccountRepositoryIterator AccountRepository::find(std::shared_ptr<Account> accountForFind) const
{
	return repository.find(accountForFind);
}

// Class member function. Find begin iterator of repository
AccountRepositoryIterator AccountRepository::begin() const
{
	return repository.begin();
}

// Class member function. Find end iterator of repository
AccountRepositoryIterator AccountRepository::end() const
{
	return repository.end();
}