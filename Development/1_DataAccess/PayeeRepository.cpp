#include "PayeeRepository.h"

PayeeRepository::PayeeRepository()
{}

void PayeeRepository::addPayee(Payee payeeForAdd)
{
	payeeRepository.insert(payeeForAdd);
}

void PayeeRepository::removePayee(Payee payeeForRemove)
{
	payeeRepository.erase(payeeForRemove);
}

size_t PayeeRepository::sizePayeeRepository() const
{
	return payeeRepository.size();
}

void PayeeRepository::clearPayeeRepository()
{
	payeeRepository.clear();
}

PayeeRepositoryIterator PayeeRepository::findPayeeRepository(Payee&& payeeForFind) const
{
	return payeeRepository.find(std::move(payeeForFind));
}