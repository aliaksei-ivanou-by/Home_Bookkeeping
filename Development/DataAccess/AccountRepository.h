#pragma once

#ifndef ACCOUNTREPOSITORY_H
#define ACCOUNTREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef ACCOUNT_H
#include "../Models/Account.h"
#endif

class AccountRepository
{
private:
	std::set<Account> repository;
public:
	AccountRepository() {}
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