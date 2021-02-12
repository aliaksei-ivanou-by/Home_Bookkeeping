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

	size_t getTransactionRepositorySize() const;
	size_t getCategoryRepositorySize() const;
	size_t getCurrencyRepositorySize() const;
	size_t getPayeeRepositorySize() const;
	size_t getTagRepositorySize() const;
	size_t getCommentRepositorySize() const;
	size_t getDescriptionRepositorySize() const;
	size_t getAccountRepositorySize() const;

	void clearTransactionRepository();
	void clearCategoryRepository();
	void clearCurrencyRepository();
	void clearPayeeRepository();
	void clearTagRepository();
	void clearCommentRepository();
	void clearDescriptionRepository();
	void clearAccountRepository();

	TransactionRepositoryIterator findTransactionRepository(Transaction&& transactionForFind) const;
	CategoryRepositoryIterator findCategoryRepository(Category&& categoryForFind) const;
	CurrencyRepositoryIterator findCurrencyRepository(Currency&& currencyForFind) const;
	PayeeRepositoryIterator findPayeeRepository(Payee&& payeeForFind) const;
	TagRepositoryIterator findTagRepository(Tag&& tagForFind) const;
	CommentRepositoryIterator findCommentRepository(Comment&& commentForFind) const;
	DescriptionRepositoryIterator findDescriptionRepository(Description&& descriptionForFind) const;
	AccountRepositoryIterator findAccountRepository(Account&& accountForFind) const;

	TransactionRepositoryIterator beginTransactionRepository() const;
	CategoryRepositoryIterator beginCategoryRepository() const;
	CurrencyRepositoryIterator beginCurrencyRepository() const;
	PayeeRepositoryIterator beginPayeeRepository() const;
	TagRepositoryIterator beginTagRepository() const;
	CommentRepositoryIterator beginCommentRepository() const;
	DescriptionRepositoryIterator beginDescriptionRepository() const;
	AccountRepositoryIterator beginAccountRepository() const;

	TransactionRepositoryIterator endTransactionRepository() const;
	CategoryRepositoryIterator endCategoryRepository() const;
	CurrencyRepositoryIterator endCurrencyRepository() const;
	PayeeRepositoryIterator endPayeeRepository() const;
	TagRepositoryIterator endTagRepository() const;
	CommentRepositoryIterator endCommentRepository() const;
	DescriptionRepositoryIterator endDescriptionRepository() const;
	AccountRepositoryIterator endAccountRepository() const;
};