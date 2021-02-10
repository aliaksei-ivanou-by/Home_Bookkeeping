#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Account.h"

class AccountRepository
{
private:
	std::set<Account> accountRepository;
public:
	AccountRepository();
	void addAccount(Account accountForAdd);
	void removeAccount(Account accountForRemove);
	std::set<Account> getAccountRepository() const;
	void setAccountRepository(std::set<Account>&& accountsForAdd);
};