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
	std::set<Payee> repository;
public:
	PayeeRepository() {}
	void add(Payee name)
	{
		repository.insert(name);
	}
	void remove(Payee name)
	{
		repository.erase(name);
	}
	std::set<Payee> get_payee_repository() const
	{
		return repository;
	}
};

#endif