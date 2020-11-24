#pragma once

#ifndef PAYEEREPOSITORY_H
#define PAYEEREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef PAYEE_H
#include "../Models/Payee.h"
#endif

class PayeeRepository
{
private:
	std::set<Payee> payeeRepository;
public:
	PayeeRepository()
	{}
	void addPayee(Payee payee)
	{
		payeeRepository.insert(payee);
	}
	void removePayee(Payee payee)
	{
		payeeRepository.erase(payee);
	}
	std::set<Payee> getPayeeRepository() const
	{
		return payeeRepository;
	}
	void setPayeeRepository(std::set<Payee>&& payees)
	{
		payeeRepository = payees;
	}
};

#endif