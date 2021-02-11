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
	size_t sizeAccountRepository();
	void clearAccountRepository();
};