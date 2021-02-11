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