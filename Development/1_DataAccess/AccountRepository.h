#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Account.h"

using AccountRepositoryIterator = std::set<Account>::iterator;

class AccountRepository
{
private:
	std::set<Account> repository;
public:
	AccountRepository();
	void add(Account accountForAdd);
	void remove(Account accountForRemove);
	size_t size() const;
	void clear();
	AccountRepositoryIterator find(const Account& accountForFind) const;
	AccountRepositoryIterator begin() const;
	AccountRepositoryIterator end() const;
};