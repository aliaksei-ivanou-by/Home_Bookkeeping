#include "PayeeRepository.h"

PayeeRepository::PayeeRepository()
{}

void PayeeRepository::add(Payee payeeForAdd)
{
	repository.insert(std::make_shared<Payee>(payeeForAdd));
}

void PayeeRepository::remove(std::shared_ptr<Payee> payeeForRemove)
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

PayeeRepositoryIterator PayeeRepository::find(std::shared_ptr<Payee> payeeForFind) const
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