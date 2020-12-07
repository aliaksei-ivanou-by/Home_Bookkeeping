#pragma once

#ifndef BOOKKEEPINGREPOSITORY_H
#define BOOKKEEPINGREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef MODELS_H
#include "../include/Models.h"
#endif

#ifndef DATAACCESS1_H
#include "../include/includeDataAccess1.h"
#endif

#ifndef DATAACCESS2_H
#include "../include/includeDataAccess2.h"
#endif

class FinanceRepository
{
private:
	TransactionRepository financeRepositoryTransactions;
	CategoryRepository financeRepositoryCategories;
	CategorySubRepository financeRepositoryCategoriesSub;
	CommentRepository financeRepositoryComments;
	PayeeRepository financeRepositoryPayees;
	AccountRepository financeRepositoryAccounts;
	CurrencyRepository financeRepositoryCurrencies;
	CurrencyRateRepository financeRepositoryCurrenciesRate;
	DescriptionRepository financeRepositoryDescriptions;
	TagRepository financeRepositoryTags;
public:
	FinanceRepository()
	{
		TransactionRepository();
		CategoryRepository();
		CategorySubRepository();
		CommentRepository();
		PayeeRepository();
		AccountRepository();
		CurrencyRepository();
		CurrencyRateRepository();
		DescriptionRepository();
		TagRepository();
	}
	TransactionRepository getTransactions() const
	{
		return this->financeRepositoryTransactions;
	}
	CategoryRepository getCategories() const
	{
		return this->financeRepositoryCategories;
	}
	CategorySubRepository getCategoriesSub() const
	{
		return this->financeRepositoryCategoriesSub;
	}
	CommentRepository getComments() const
	{
		return this->financeRepositoryComments;
	}
	PayeeRepository getPayees() const
	{
		return this->financeRepositoryPayees;
	}
	AccountRepository getAccounts() const
	{
		return this->financeRepositoryAccounts;
	}
	CurrencyRepository getCurrencies() const
	{
		return this->financeRepositoryCurrencies;
	}
	CurrencyRateRepository getCurrenciesRate() const
	{
		return this->financeRepositoryCurrenciesRate;
	}
	DescriptionRepository getDescriptions() const
	{
		return this->financeRepositoryDescriptions;
	}
	TagRepository getTags() const
	{
		return this->financeRepositoryTags;
	}
	void addTransaction(Transaction& transaction)
	{
		this->financeRepositoryTransactions.addTransaction(transaction);
	}
	void addCategory(Category category)
	{
		this->financeRepositoryCategories.addCategory(category);
	}
	void addCategorySub(CategorySub categorySub)
	{
		this->financeRepositoryCategoriesSub.addCategorySub(categorySub);
	}
	void addCurrency(Currency currency)
	{
		this->financeRepositoryCurrencies.addCurrency(currency);
	}
	void addPayee(Payee payee)
	{
		this->financeRepositoryPayees.addPayee(payee);
	}
	void addTag(Tag tag)
	{
		this->financeRepositoryTags.addTag(tag);
	}
	void addComment(Comment comment)
	{
		this->financeRepositoryComments.addComment(comment);
	}
	void addDescription(Description description)
	{
		this->financeRepositoryDescriptions.addDescription(description);
	}
	void addAccount(Account account)
	{
		this->financeRepositoryAccounts.addAccount(account);
	}
};

#endif