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
	void addTransaction(const Transaction& transactionForAdd);
	void addCategory(const Category& categoryForAdd);
	void addCurrency(const Currency& currencyForAdd);
	void addPayee(const Payee& payeeForAdd);
	void addTag(const Tag& tagForAdd);
	void addComment(const Comment& commentForAdd);
	void addDescription(const Description& descriptionForAdd);
	void addAccount(const Account& accountForAdd);

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

	TransactionRepositoryIterator findTransaction(const Transaction& transactionForFind) const;
	CategoryRepositoryIterator findCategory(const Category& categoryForFind) const;
	CurrencyRepositoryIterator findCurrency(const Currency& currencyForFind) const;
	PayeeRepositoryIterator findPayee(const Payee& payeeForFind) const;
	TagRepositoryIterator findTag(const Tag& tagForFind) const;
	CommentRepositoryIterator findComment(const Comment& commentForFind) const;
	DescriptionRepositoryIterator findDescription(const Description& descriptionForFind) const;
	AccountRepositoryIterator findAccount(const Account& accountForFind) const;

	void printAccounts(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printTransactions(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printCategories(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printCurrencies(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printPayees(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printTags(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printComments(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printDescriptions(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
};