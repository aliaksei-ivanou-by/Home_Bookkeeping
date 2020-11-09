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
	void add(std::string name)
	{
		repository.insert(name);
	}
	void remove(std::string name)
	{
		repository.erase(name);
	}
};

#endif