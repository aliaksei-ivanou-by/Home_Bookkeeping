/*#pragma once

#include "../include/stdafx.h"
#include "../include/DataAccess1.h"
#include "../include/DataAccess2.h"

class FinanceRepository
{
private:
	TransactionRepository financeRepositoryTransactions;
	CategoryRepository financeRepositoryCategories;
	CommentRepository financeRepositoryComments;
	PayeeRepository financeRepositoryPayees;
	AccountRepository financeRepositoryAccounts;
	CurrencyRepository financeRepositoryCurrencies;
	DescriptionRepository financeRepositoryDescriptions;
	TagRepository financeRepositoryTags;
public:
	FinanceRepository();
	
	TransactionRepository getTransactionRepository() const;
	CategoryRepository getCategoryRepository() const;
	CommentRepository getCommentRepository() const;
	PayeeRepository getPayeeRepository() const;
	AccountRepository getAccountRepository() const;
	CurrencyRepository getCurrencyRepository() const;
	DescriptionRepository getDescriptionRepository() const;
	TagRepository getTagRepository() const;
	
	void addTransaction(Transaction& transactionForAdd);
	void addCategory(Category categoryForAdd);
	void addCurrency(Currency currencyForAdd);
	void addPayee(Payee payeeForAdd);
	void addTag(Tag tagForAdd);
	void addComment(Comment commentForAdd);
	void addDescription(Description descriptionForAdd);
	void addAccount(Account accountForAdd);
};*/