#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Payee.h"

using PayeeRepositoryIterator = std::set<Payee>::iterator;

class PayeeRepository
{
private:
	std::set<Payee> payeeRepository;
public:
	PayeeRepository();
	void addPayee(Payee payeeForAdd);
	void removePayee(Payee payeeForRemove);
	size_t sizePayeeRepository() const;
	void clearPayeeRepository();
	PayeeRepositoryIterator findPayeeRepository(Payee&& payeeForFind) const;
};