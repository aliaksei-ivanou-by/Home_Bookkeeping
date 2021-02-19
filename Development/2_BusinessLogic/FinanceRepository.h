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
	void addTransaction(Transaction& transactionForAdd);
	void addCategory(const Category& categoryForAdd);
	void addCurrency(const Currency& currencyForAdd);
	void addPayee(const Payee& payeeForAdd);
	void addTag(const Tag& tagForAdd);
	void addComment(const Comment& commentForAdd);
	void addDescription(const Description& descriptionForAdd);
	void addAccount(const Account& accountForAdd);

	void removeTransaction(std::shared_ptr<Transaction> transactionForRemove);
	void removeCategory(std::shared_ptr<Category> categoryForRemove);
	void removeCurrency(std::shared_ptr<Currency> currencyForRemove);
	void removePayee(std::shared_ptr<Payee> payeeForRemove);
	void removeTag(std::shared_ptr<Tag> tagForRemove);
	void removeComment(std::shared_ptr<Comment> commentForRemove);
	void removeDescription(std::shared_ptr<Description> descriptionForRemove);
	void removeAccount(std::shared_ptr<Account> accountForRemove);

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

	TransactionRepositoryIterator findTransaction(std::shared_ptr<Transaction> transactionForFind) const;
	CategoryRepositoryIterator findCategory(std::shared_ptr<Category> categoryForFind) const;
	CurrencyRepositoryIterator findCurrency(std::shared_ptr<Currency> currencyForFind) const;
	PayeeRepositoryIterator findPayee(std::shared_ptr<Payee> payeeForFind) const;
	TagRepositoryIterator findTag(std::shared_ptr<Tag> tagForFind) const;
	CommentRepositoryIterator findComment(std::shared_ptr<Comment> commentForFind) const;
	DescriptionRepositoryIterator findDescription(std::shared_ptr<Description> descriptionForFind) const;
	AccountRepositoryIterator findAccount(std::shared_ptr<Account> accountForFind) const;

	void printAccounts(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printTransactions(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printCategories(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printCurrencies(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printPayees(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printTags(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printComments(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printDescriptions(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;

	double sumExpencesToday() const;
	double sumExpencesThisMonth() const;
	double sumExpencesAllTime() const;

	double sumIncomesToday() const;
	double sumIncomesThisMonth() const;
	double sumIncomesAllTime() const;
	
	void setDefaultCategories();
	void setDefaultAccounts();
	void setDefaultCurrencies();


	void updateAccountAmount(Transaction& transactionForAdd);
};