#pragma once
#include "../include/stdafx.h"
#include "../include/1_DataAccess_Main.h"

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
	void addTransaction(Transaction&& transactionForAdd);
	void addCategory(Category&& categoryForAdd);
	void addCurrency(Currency&& currencyForAdd);
	void addPayee(Payee&& payeeForAdd);
	void addTag(Tag&& tagForAdd);
	void addComment(Comment&& commentForAdd);
	void addDescription(Description&& descriptionForAdd);
	void addAccount(Account&& accountForAdd);

	size_t getTransactionRepositorySize();
	size_t getCategoryRepositorySize();
	size_t getCurrencyRepositorySize();
	size_t getPayeeRepositorySize();
	size_t getTagRepositorySize();
	size_t getCommentRepositorySize();
	size_t getDescriptionRepositorySize();
	size_t getAccountRepositorySize();
};