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
	std::set<Account> accountRepository;
public:
	AccountRepository()
	{}
	void addAccount(Account account)
	{
		accountRepository.insert(account);
	}
	void removeAccount(Account account)
	{
		accountRepository.erase(account);
	}
	std::set<Account> getAccountRepository() const
	{
		return accountRepository;
	}
	void setAccountRepository(std::set<Account>&& accounts)
	{
		accountRepository = accounts;
	}
};

#endif