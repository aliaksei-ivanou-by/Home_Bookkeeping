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

std::set<Payee> PayeeRepository::getPayeeRepository() const
{
	return payeeRepository;
}

void PayeeRepository::setPayeeRepository(std::set<Payee>&& payeesForAdd)
{
	payeeRepository = payeesForAdd;
}