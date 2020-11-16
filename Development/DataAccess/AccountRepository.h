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
	void add(Account name)
	{
		repository.insert(name);
	}
	void remove(Account name)
	{
		repository.erase(name);
	}
	std::set<Account> get_account_repository() const
	{
		return repository;
	}
};

#endif