#include "PayeeRepository.h"

PayeeRepository::PayeeRepository()
{}

void PayeeRepository::add(Payee payeeForAdd)
{
	repository.insert(payeeForAdd);
}

void PayeeRepository::remove(Payee payeeForRemove)
{
	repository.erase(payeeForRemove);
}

size_t PayeeRepository::size() const
{
	return repository.size();
}

void PayeeRepository::clear()
{
	repository.clear();
}

PayeeRepositoryIterator PayeeRepository::find(const Payee& payeeForFind) const
{
	return repository.find(payeeForFind);
}

PayeeRepositoryIterator PayeeRepository::begin() const
{
	return repository.begin();
}

PayeeRepositoryIterator PayeeRepository::end() const
{
	return repository.end();
}