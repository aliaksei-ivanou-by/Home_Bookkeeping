#pragma once

#include "../include/stdafx.h"
#include "../Models/Payee.h"

class PayeeRepository
{
private:
	std::set<Payee> payeeRepository;
public:
	PayeeRepository();
	void addPayee(Payee payeeForAdd);
	void removePayee(Payee payeeForRemove);
	std::set<Payee> getPayeeRepository() const;
	void setPayeeRepository(std::set<Payee>&& payeesForAdd);
};