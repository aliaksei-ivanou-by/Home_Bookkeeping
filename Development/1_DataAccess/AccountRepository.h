#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Account.h"

using AccountRepositoryIterator = std::set<std::shared_ptr<Account>>::iterator;

class AccountRepository
{
private:
	std::set<std::shared_ptr<Account>> repository;
public:
	AccountRepository();
	void add(Account accountForAdd);
	void add(std::shared_ptr<Account> accountForAdd);
	void remove(std::shared_ptr<Account> accountForRemove);
	size_t size() const;
	void clear();
	AccountRepositoryIterator find(std::shared_ptr<Account> accountForFind) const;
	AccountRepositoryIterator begin() const;
	AccountRepositoryIterator end() const;
};