#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Payee.h"

class PayeeRepository
{
private:
	std::set<Payee> payeeRepository;
public:
	PayeeRepository();
	void addPayee(Payee payeeForAdd);
	void removePayee(Payee payeeForRemove);
};