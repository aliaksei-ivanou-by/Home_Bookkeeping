#include "PayeeRepository.h"

// Default constructor
PayeeRepository::PayeeRepository()
{}

// Class member function. Add payee to repository
void PayeeRepository::add(Payee payeeForAdd)
{
	repository.insert(std::make_shared<Payee>(payeeForAdd));
}

// Class member function. Add shared pointer to payee to repository
void PayeeRepository::add(std::shared_ptr<Payee> payeeForAdd)
{
	repository.insert(payeeForAdd);
}

// Class member function. Remove shared pointer to payee from repository
void PayeeRepository::remove(std::shared_ptr<Payee> payeeForRemove)
{
	repository.erase(payeeForRemove);
}

// Class member function. Calculate size of repository
size_t PayeeRepository::size() const
{
	return repository.size();
}

// Class member function. Clear repository
void PayeeRepository::clear()
{
	repository.clear();
}

// Class member function. Find shared pointer to payee in repository
PayeeRepositoryIterator PayeeRepository::find(std::shared_ptr<Payee> payeeForFind) const
{
	return repository.find(payeeForFind);
}

// Class member function. Find begin iterator of repository
PayeeRepositoryIterator PayeeRepository::begin() const
{
	return repository.begin();
}

// Class member function. Find end iterator of repository
PayeeRepositoryIterator PayeeRepository::end() const
{
	return repository.end();
}