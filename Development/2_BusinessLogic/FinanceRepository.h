#pragma once
#include "../include/stdafx.h"
#include "../include/1_DataAccess_Main.h"

/*
Class FinanceRepository
Includes repositories: transactions, categories, comments, payees, accounts, currencies, descriptions, tags.

Constructors:
	Default

Class member functions:
	basic:
		iterators:
			begin:
				Find begin iterator of repository of transactions
				Find begin iterator of repository of accounts
				Find begin iterator of repository of categories
				Find begin iterator of repository of currencies
				Find begin iterator of repository of descriptions
				Find begin iterator of repository of payees
				Find begin iterator of repository of comments
				Find begin iterator of repository of tags
			end:
				Find end iterator of repository of transactions
				Find end iterator of repository of accounts
				Find end iterator of repository of categories
				Find end iterator of repository of currencies
				Find end iterator of repository of descriptions
				Find end iterator of repository of payees
				Find end iterator of repository of comments
				Find end iterator of repository of tags
		add element:
			Add transaction to repository of transactions
			Add account to repository of accounts
			Add category to repository of categories
			Add currency to repository of currencies
			Add description to repository of descriptions
			Add payee to repository of payees
			Add comment to repository of comments
			Add tag to repository of tags
		remove element:
			Remove transaction (shared pointer to transaction) from repository of transactions
			Remove account (shared pointer to account) from repository of accounts
			Remove category (shared pointer to category) from repository of categories
			Remove currency (shared pointer to currency) from repository of currencies
			Remove description (shared pointer to description) from repository of descriptions
			Remove payee (shared pointer to payee) from repository of payees
			Remove comment (shared pointer to comment) from repository of comments
			Remove tag (shared pointer to tag) from repository of tags
		size of element in repository:
			Calculate number of elements in transactions repository
			Calculate number of elements in accounts repository
			Calculate number of elements in categories repository
			Calculate number of elements in currencies repository
			Calculate number of elements in descriptions repository
			Calculate number of elements in payees repository
			Calculate number of elements in comments repository
			Calculate number of elements in tags repository
		clear repository:
			Clear transactions repository
			Clear accounts repository
			Clear categories repository
			Clear currencies repository
			Clear descriptions repository
			Clear payees repository
			Clear comments repository
			Clear tags repository
		print repository:
			Print transactions repository
			Print accounts repository
			Print categories repository
			Print currencies repository
			Print descriptions repository
			Print payees repository
			Print comments repository
			Print tags repository
		find:
			Find transaction (shared pointer) in transactions repository
			Find account (shared pointer) in accounts repository
			Find category (shared pointer) in categories repository
			Find currency (shared pointer) in currencies repository
			Find description (shared pointer) in descriptions repository
			Find payee (shared pointer) in payees repository
			Find comment (shared pointer) in comments repository
			Find tag (shared pointer) in tags repository
		additional:
			Update last amount of account in accounts repository with adding new transaction
	sum:
		expenses:
			Calculate sum of today expenses
			Calculate sum of this month expenses
			Calculate sum of all time expenses
		incomes:
			Calculate sum of today incomes
			Calculate sum of this month incomes
			Calculate sum of all time incomes
	default repositories:
		Set default accounts repository
		Set default categories repository
		Set default currencies repository
*/

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
	AccountRepositoryIterator beginAccountRepository() const;
	CategoryRepositoryIterator beginCategoryRepository() const;
	CurrencyRepositoryIterator beginCurrencyRepository() const;
	DescriptionRepositoryIterator beginDescriptionRepository() const;
	PayeeRepositoryIterator beginPayeeRepository() const;
	CommentRepositoryIterator beginCommentRepository() const;
	TagRepositoryIterator beginTagRepository() const;

	TransactionRepositoryIterator endTransactionRepository() const;
	AccountRepositoryIterator endAccountRepository() const;
	CategoryRepositoryIterator endCategoryRepository() const;
	CurrencyRepositoryIterator endCurrencyRepository() const;
	DescriptionRepositoryIterator endDescriptionRepository() const;
	PayeeRepositoryIterator endPayeeRepository() const;
	CommentRepositoryIterator endCommentRepository() const;
	TagRepositoryIterator endTagRepository() const;
public:
	FinanceRepository();

	void addTransaction(Transaction& transactionForAdd);
	void addAccount(const Account& accountForAdd);
	void addCategory(const Category& categoryForAdd);
	void addCurrency(const Currency& currencyForAdd);
	void addDescription(const Description& descriptionForAdd);
	void addPayee(const Payee& payeeForAdd);
	void addComment(const Comment& commentForAdd);
	void addTag(const Tag& tagForAdd);

	void removeTransaction(std::shared_ptr<Transaction> transactionForRemove);
	void removeAccount(std::shared_ptr<Account> accountForRemove);
	void removeCategory(std::shared_ptr<Category> categoryForRemove);
	void removeCurrency(std::shared_ptr<Currency> currencyForRemove);
	void removeDescription(std::shared_ptr<Description> descriptionForRemove);
	void removePayee(std::shared_ptr<Payee> payeeForRemove);
	void removeComment(std::shared_ptr<Comment> commentForRemove);
	void removeTag(std::shared_ptr<Tag> tagForRemove);

	size_t getTransactionsNumber() const;
	size_t getAccountsNumber() const;
	size_t getCategoriesNumber() const;
	size_t getCurrenciesNumber() const;
	size_t getDescriptionsNumber() const;
	size_t getPayeesNumber() const;
	size_t getCommentsNumber() const;
	size_t getTagsNumber() const;

	void clearTransactions();
	void clearAccounts();
	void clearCategories();
	void clearCurrencies();
	void clearDescriptions();
	void clearPayees();
	void clearComments();
	void clearTags();
	
	void printTransactions(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printAccounts(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printCategories(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printCurrencies(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printDescriptions(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printPayees(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printComments(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;
	void printTags(const std::string& delimeter = "\n", std::ostream& outputStream = std::cout) const;

	TransactionRepositoryIterator findTransaction(std::shared_ptr<Transaction> transactionForFind) const;
	AccountRepositoryIterator findAccount(std::shared_ptr<Account> accountForFind) const;
	CategoryRepositoryIterator findCategory(std::shared_ptr<Category> categoryForFind) const;
	CurrencyRepositoryIterator findCurrency(std::shared_ptr<Currency> currencyForFind) const;
	DescriptionRepositoryIterator findDescription(std::shared_ptr<Description> descriptionForFind) const;
	PayeeRepositoryIterator findPayee(std::shared_ptr<Payee> payeeForFind) const;
	CommentRepositoryIterator findComment(std::shared_ptr<Comment> commentForFind) const;
	TagRepositoryIterator findTag(std::shared_ptr<Tag> tagForFind) const;

	void updateAccountAmount(Transaction& transactionForAdd);

	double sumExpencesToday() const;
	double sumExpencesThisMonth() const;
	double sumExpencesAllTime() const;

	double sumIncomesToday() const;
	double sumIncomesThisMonth() const;
	double sumIncomesAllTime() const;
	
	void setDefaultCategories();
	void setDefaultAccounts();
	void setDefaultCurrencies();
};