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

	size_t getTransactionsNumber() const;
	size_t getCategoriesNumber() const;
	size_t getCurrenciesNumber() const;
	size_t getPayeesNumber() const;
	size_t getTagsNumber() const;
	size_t getCommentsNumber() const;
	size_t getDescriptionsNumber() const;
	size_t getAccountsNumber() const;

	void clearTransactions();
	void clearCategories();
	void clearCurrencies();
	void clearPayees();
	void clearTags();
	void clearComments();
	void clearDescriptions();
	void clearAccounts();

	TransactionRepositoryIterator findTransaction(Transaction&& transactionForFind) const;
	CategoryRepositoryIterator findCategory(Category&& categoryForFind) const;
	CurrencyRepositoryIterator findCurrency(Currency&& currencyForFind) const;
	PayeeRepositoryIterator findPayee(Payee&& payeeForFind) const;
	TagRepositoryIterator findTag(Tag&& tagForFind) const;
	CommentRepositoryIterator findComment(Comment&& commentForFind) const;
	DescriptionRepositoryIterator findDescription(Description&& descriptionForFind) const;
	AccountRepositoryIterator findAccount(Account&& accountForFind) const;
};