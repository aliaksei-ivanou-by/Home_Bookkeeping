#pragma once

#include "../include/stdafx.h"
#include "../include/Models.h"
#include "../include/includeDataAccess1.h"
#include "../include/includeDataAccess2.h"

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
	FinanceRepository();
	
	TransactionRepository getTransactions() const;
	CategoryRepository getCategories() const;
	CategorySubRepository getCategoriesSub() const;
	CommentRepository getComments() const;
	PayeeRepository getPayees() const;
	AccountRepository getAccounts() const;
	CurrencyRepository getCurrencies() const;
	CurrencyRateRepository getCurrenciesRate() const;
	DescriptionRepository getDescriptions() const;
	TagRepository getTags() const;
	
	void addTransaction(Transaction& transactionForAdd);
	void addCategory(Category categoryForAdd);
	void addCategorySub(CategorySub categorySubForAdd);
	void addCurrency(Currency currencyForAdd);
	void addPayee(Payee payeeForAdd);
	void addTag(Tag tagForAdd);
	void addComment(Comment commentForAdd);
	void addDescription(Description descriptionForAdd);
	void addAccount(Account accountForAdd);
};