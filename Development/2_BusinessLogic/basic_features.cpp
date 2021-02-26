#include "FinanceRepository.h"

// Default constructor
FinanceRepository::FinanceRepository()
{}

// Class member function. Find begin iterator of repository of transactions
TransactionRepositoryIterator FinanceRepository::beginTransactionRepository() const
{
	return financeRepositoryTransactions.begin();
}

// Class member function. Find begin iterator of repository of accounts
AccountRepositoryIterator FinanceRepository::beginAccountRepository() const
{
	return financeRepositoryAccounts.begin();
}

// Class member function. Find begin iterator of repository of categories
CategoryRepositoryIterator FinanceRepository::beginCategoryRepository() const
{
	return financeRepositoryCategories.begin();
}

// Class member function. Find begin iterator of repository of currencies
CurrencyRepositoryIterator FinanceRepository::beginCurrencyRepository() const
{
	return financeRepositoryCurrencies.begin();
}

// Class member function. Find begin iterator of repository of descriptions
DescriptionRepositoryIterator FinanceRepository::beginDescriptionRepository() const
{
	return financeRepositoryDescriptions.begin();
}

// Class member function. Find begin iterator of repository of payees
PayeeRepositoryIterator FinanceRepository::beginPayeeRepository() const
{
	return financeRepositoryPayees.begin();
}

// Class member function. Find begin iterator of repository of comments
CommentRepositoryIterator FinanceRepository::beginCommentRepository() const
{
	return financeRepositoryComments.begin();
}

// Class member function. Find begin iterator of repository of tags
TagRepositoryIterator FinanceRepository::beginTagRepository() const
{
	return financeRepositoryTags.begin();
}

// Class member function. Find end iterator of repository of transactions
TransactionRepositoryIterator FinanceRepository::endTransactionRepository() const
{
	return financeRepositoryTransactions.end();
}

// Class member function. Find end iterator of repository of accounts
AccountRepositoryIterator FinanceRepository::endAccountRepository() const
{
	return financeRepositoryAccounts.end();
}

// Class member function. Find end iterator of repository of categories
CategoryRepositoryIterator FinanceRepository::endCategoryRepository() const
{
	return financeRepositoryCategories.end();
}

// Class member function. Find end iterator of repository of currencies
CurrencyRepositoryIterator FinanceRepository::endCurrencyRepository() const
{
	return financeRepositoryCurrencies.end();
}

// Class member function. Find end iterator of repository of descriptions
DescriptionRepositoryIterator FinanceRepository::endDescriptionRepository() const
{
	return financeRepositoryDescriptions.end();
}

// Class member function. Find end iterator of repository of payees
PayeeRepositoryIterator FinanceRepository::endPayeeRepository() const
{
	return financeRepositoryPayees.end();
}

// Class member function. Find end iterator of repository of comments
CommentRepositoryIterator FinanceRepository::endCommentRepository() const
{
	return financeRepositoryComments.end();
}

// Class member function. Find end iterator of repository of tags
TagRepositoryIterator FinanceRepository::endTagRepository() const
{
	return financeRepositoryTags.end();
}

// Class member function. Add transaction to repository of transactions
void FinanceRepository::addTransaction(Transaction& transactionForAdd)
{
	// Account
	if (financeRepositoryAccounts.size() == 0)
	{
		financeRepositoryAccounts.add(transactionForAdd.getTransactionAccountPtrFrom());
	}
	else
	{
		bool keyFrom = false;
		for (auto i = financeRepositoryAccounts.begin(); i != financeRepositoryAccounts.end(); ++i)
		{
			if ((**i).getAccountName() == transactionForAdd.getTransactionAccountFrom().getAccountName())
			{
				keyFrom = true;
				transactionForAdd.setTransactionAccountPtrFrom(*i);
				break;
			}
		}
		if (!keyFrom)
		{
			financeRepositoryAccounts.add(transactionForAdd.getTransactionAccountPtrFrom());
		}
		bool keyTo = false;
		for (auto i = financeRepositoryAccounts.begin(); i != financeRepositoryAccounts.end(); ++i)
		{
			if ((**i).getAccountName() == transactionForAdd.getTransactionAccountTo().getAccountName())
			{
				keyTo = true;
				transactionForAdd.setTransactionAccountPtrTo(*i);
				break;
			}
		}
		if (!keyTo)
		{
			financeRepositoryAccounts.add(transactionForAdd.getTransactionAccountPtrTo());
		}
	}
	updateAccountAmount(transactionForAdd);
	// Category
	if (financeRepositoryCategories.size() == 0)
	{
		financeRepositoryCategories.add(transactionForAdd.getTransactionCategoryPtr());
	}
	else
	{
		bool keyFrom = false;
		for (auto i = financeRepositoryCategories.begin(); i != financeRepositoryCategories.end(); ++i)
		{
			if ((**i).getCategoryName() == transactionForAdd.getTransactionCategory().getCategoryName())
			{
				keyFrom = true;
				transactionForAdd.setTransactionCategoryPtr(*i);
				break;
			}
		}
		if (!keyFrom)
		{
			financeRepositoryCategories.add(transactionForAdd.getTransactionCategory());
		}
		bool keyTo = false;
		for (auto i = financeRepositoryCategories.begin(); i != financeRepositoryCategories.end(); ++i)
		{
			if ((**i).getCategoryName() == transactionForAdd.getTransactionCategory().getCategoryName())
			{
				keyTo = true;
				transactionForAdd.setTransactionCategoryPtr(*i);
				break;
			}
		}
		if (!keyTo)
		{
			financeRepositoryCategories.add(transactionForAdd.getTransactionCategoryPtr());
		}
	}
	financeRepositoryTransactions.add(transactionForAdd);
}

// Class member function. Add account to repository of accounts
void FinanceRepository::addAccount(const Account& accountForAdd)
{
	financeRepositoryAccounts.add(accountForAdd);
}

// Class member function. Add category to repository of categories
void FinanceRepository::addCategory(const Category& categoryForAdd)
{
	financeRepositoryCategories.add(categoryForAdd);
}

// Class member function. Add currency to repository of currencies
void FinanceRepository::addCurrency(const Currency& currencyForAdd)
{
	financeRepositoryCurrencies.add(currencyForAdd);
}

// Class member function. Add description to repository of descriptions
void FinanceRepository::addDescription(const Description& descriptionForAdd)
{
	financeRepositoryDescriptions.add(descriptionForAdd);
}

// Class member function. Add payee to repository of payees
void FinanceRepository::addPayee(const Payee& payeeForAdd)
{
	financeRepositoryPayees.add(payeeForAdd);
}

// Class member function. Add comment to repository of comments
void FinanceRepository::addComment(const Comment& commentForAdd)
{
	financeRepositoryComments.add(commentForAdd);
}

// Class member function. Add tag to repository of tags
void FinanceRepository::addTag(const Tag& tagForAdd)
{
	financeRepositoryTags.add(tagForAdd);
}

// Class member function. Remove transaction (shared pointer to transaction) from repository of transactions
void FinanceRepository::removeTransaction(std::shared_ptr<Transaction> transactionForRemove)
{
	financeRepositoryTransactions.remove(transactionForRemove);
}

// Class member function. Remove account (shared pointer to account) from repository of accounts
void FinanceRepository::removeAccount(std::shared_ptr<Account> accountForRemove)
{
	financeRepositoryAccounts.remove(accountForRemove);
}

// Class member function. Remove category(shared pointer to category) from repository of categories
void FinanceRepository::removeCategory(std::shared_ptr<Category> categoryForRemove)
{
	financeRepositoryCategories.remove(categoryForRemove);

}

// Class member function. Remove currency (shared pointer to currency) from repository of currencies
void FinanceRepository::removeCurrency(std::shared_ptr<Currency> currencyForRemove)
{
	financeRepositoryCurrencies.remove(currencyForRemove);
}

// Class member function. Remove description (shared pointer to description) from repository of descriptions
void FinanceRepository::removeDescription(std::shared_ptr<Description> descriptionForRemove)
{
	financeRepositoryDescriptions.remove(descriptionForRemove);
}

// Class member function. Remove payee(shared pointer to payee) from repository of payees
void FinanceRepository::removePayee(std::shared_ptr<Payee> payeeForRemove)
{
	financeRepositoryPayees.remove(payeeForRemove);
}

// Class member function. Remove comment (shared pointer to comment) from repository of comments
void FinanceRepository::removeComment(std::shared_ptr<Comment> commentForRemove)
{
	financeRepositoryComments.remove(commentForRemove);
}

// Class member function. Remove tag (shared pointer to tag) from repository of tags
void FinanceRepository::removeTag(std::shared_ptr<Tag> tagForRemove)
{
	financeRepositoryTags.remove(tagForRemove);
}

// Class member function. Calculate number of elements in transactions repository
size_t FinanceRepository::getTransactionsNumber() const
{
	return financeRepositoryTransactions.size();
}

// Class member function. Calculate number of elements in accounts repository
size_t FinanceRepository::getAccountsNumber() const
{
	return financeRepositoryAccounts.size();
}

// Class member function. Calculate number of elements in categories repository
size_t FinanceRepository::getCategoriesNumber() const
{
	return financeRepositoryCategories.size();
}

// Class member function. Calculate number of elements in currencies repository
size_t FinanceRepository::getCurrenciesNumber() const
{
	return financeRepositoryCurrencies.size();
}

// Class member function. Calculate number of elements in descriptions repository
size_t FinanceRepository::getDescriptionsNumber() const
{
	return financeRepositoryDescriptions.size();
}

// Class member function. Calculate number of elements in payees repository
size_t FinanceRepository::getPayeesNumber() const
{
	return financeRepositoryPayees.size();
}

// Class member function. Calculate number of elements in comments repository
size_t FinanceRepository::getCommentsNumber() const
{
	return financeRepositoryComments.size();
}

// Class member function. Calculate number of elements in tags repository
size_t FinanceRepository::getTagsNumber() const
{
	return financeRepositoryTags.size();
}

// Class member function. Clear transactions repository
void FinanceRepository::clearTransactions()
{
	financeRepositoryTransactions.clear();
}

// Class member function. Clear accounts repository
void FinanceRepository::clearAccounts()
{
	financeRepositoryAccounts.clear();
}

// Class member function. Clear categories repository
void FinanceRepository::clearCategories()
{
	financeRepositoryCategories.clear();
}

// Class member function. Clear currencies repository
void FinanceRepository::clearCurrencies()
{
	financeRepositoryCurrencies.clear();
}

// Class member function. Clear descriptions repository
void FinanceRepository::clearDescriptions()
{
	financeRepositoryDescriptions.clear();
}

// Class member function. Clear payees repository
void FinanceRepository::clearPayees()
{
	financeRepositoryPayees.clear();
}

// Class member function. Clear comments repository
void FinanceRepository::clearComments()
{
	financeRepositoryComments.clear();
}

// Class member function. Clear tags repository
void FinanceRepository::clearTags()
{
	financeRepositoryTags.clear();
}

// Class member function. Print transactions repository
void FinanceRepository::printTransactions(const std::string& delimeter, std::ostream& outputStream) const
{
	auto i = beginTransactionRepository();
	while (i != endTransactionRepository())
	{
		outputStream << **i;
		++i;
		if (i != endTransactionRepository())
		{
			outputStream << delimeter;
		}
	}
}

// Class member function. Print accounts repository
void FinanceRepository::printAccounts(const std::string& delimeter, std::ostream& outputStream) const
{
	auto i = beginAccountRepository();
	while (i != endAccountRepository())
	{
		outputStream << **i;
		++i;
		if (i != endAccountRepository())
		{
			outputStream << delimeter;
		}
	}
}

// Class member function. Print categories repository
void FinanceRepository::printCategories(const std::string& delimeter, std::ostream& outputStream) const
{
	auto i = beginCategoryRepository();
	while (i != endCategoryRepository())
	{
		outputStream << *i;
		++i;
		if (i != endCategoryRepository())
		{
			outputStream << delimeter;
		}
	}
}

// Class member function. Print currencies repository
void FinanceRepository::printCurrencies(const std::string& delimeter, std::ostream& outputStream) const
{
	auto i = beginCurrencyRepository();
	while (i != endCurrencyRepository())
	{
		outputStream << *i;
		++i;
		if (i != endCurrencyRepository())
		{
			outputStream << delimeter;
		}
	}
}

// Class member function. Print descriptions repository
void FinanceRepository::printDescriptions(const std::string& delimeter, std::ostream& outputStream) const
{
	auto i = beginDescriptionRepository();
	while (i != endDescriptionRepository())
	{
		outputStream << *i;
		++i;
		if (i != endDescriptionRepository())
		{
			outputStream << delimeter;
		}
	}
}

// Class member function. Print payees repository
void FinanceRepository::printPayees(const std::string& delimeter, std::ostream& outputStream) const
{
	auto i = beginPayeeRepository();
	while (i != endPayeeRepository())
	{
		outputStream << *i;
		++i;
		if (i != endPayeeRepository())
		{
			outputStream << delimeter;
		}
	}
}

// Class member function. Print comments repository
void FinanceRepository::printComments(const std::string& delimeter, std::ostream& outputStream) const
{
	auto i = beginCommentRepository();
	while (i != endCommentRepository())
	{
		outputStream << *i;
		++i;
		if (i != endCommentRepository())
		{
			outputStream << delimeter;
		}
	}
}

// Class member function. Print tags repository
void FinanceRepository::printTags(const std::string& delimeter, std::ostream& outputStream) const
{
	auto i = beginTagRepository();
	while (i != endTagRepository())
	{
		outputStream << *i;
		++i;
		if (i != endTagRepository())
		{
			outputStream << delimeter;
		}
	}
}

// Class member function. Find transaction (shared pointer) in transactions repository
TransactionRepositoryIterator FinanceRepository::findTransaction(std::shared_ptr<Transaction> transactionForFind) const
{
	return financeRepositoryTransactions.find(transactionForFind);
}

// Class member function. Find account (shared pointer) in accounts repository
AccountRepositoryIterator FinanceRepository::findAccount(std::shared_ptr<Account> accountForFind) const
{
	return financeRepositoryAccounts.find(accountForFind);
}

// Class member function. Find category (shared pointer) in categories repository
CategoryRepositoryIterator FinanceRepository::findCategory(std::shared_ptr<Category> categoryForFind) const
{
	return financeRepositoryCategories.find(categoryForFind);
}

// Class member function. Find currency (shared pointer) in currencies repository
CurrencyRepositoryIterator FinanceRepository::findCurrency(std::shared_ptr<Currency> currencyForFind) const
{
	return financeRepositoryCurrencies.find(currencyForFind);
}

// Class member function. Find description (shared pointer) in descriptions repository
DescriptionRepositoryIterator FinanceRepository::findDescription(std::shared_ptr<Description> descriptionForFind) const
{
	return financeRepositoryDescriptions.find(descriptionForFind);
}

// Class member function. Find payee (shared pointer) in payees repository
PayeeRepositoryIterator FinanceRepository::findPayee(std::shared_ptr<Payee> payeeForFind) const
{
	return financeRepositoryPayees.find(payeeForFind);
}

// Class member function. Find comment (shared pointer) in comments repository
CommentRepositoryIterator FinanceRepository::findComment(std::shared_ptr<Comment> commentForFind) const
{
	return financeRepositoryComments.find(commentForFind);
}

// Class member function. Find tag (shared pointer) in tags repository
TagRepositoryIterator FinanceRepository::findTag(std::shared_ptr<Tag> tagForFind) const
{
	return financeRepositoryTags.find(tagForFind);
}

// Class member function. Update last amount of account in accounts repository with adding new transaction
void FinanceRepository::updateAccountAmount(Transaction& transactionForAdd)
{
	if (transactionForAdd.getTransactionType() == TransactionType(TransactionTypeEnum::Expence))
	{
		auto amount = transactionForAdd.getTransactionAccountFromLastAmount() - transactionForAdd.getTransactionAmount();
		transactionForAdd.setTransactionAccountFromLastAmount(amount);
		transactionForAdd.setTransactionAccountToLastAmount(amount);
		transactionForAdd.setTransactionAccountFromCurrentAmount(amount);
		transactionForAdd.setTransactionAccountToCurrentAmount(amount);
	}
	if (transactionForAdd.getTransactionType() == TransactionType(TransactionTypeEnum::Income))
	{
		auto amount = transactionForAdd.getTransactionAccountFromLastAmount() + transactionForAdd.getTransactionAmount();
		transactionForAdd.setTransactionAccountFromLastAmount(amount);
		transactionForAdd.setTransactionAccountToLastAmount(amount);
		transactionForAdd.setTransactionAccountFromCurrentAmount(amount);
		transactionForAdd.setTransactionAccountToCurrentAmount(amount);
	}
	if (transactionForAdd.getTransactionType() == TransactionType(TransactionTypeEnum::Transfer))
	{
		auto amountFrom = transactionForAdd.getTransactionAccountFromLastAmount() - transactionForAdd.getTransactionAmount();
		transactionForAdd.setTransactionAccountFromLastAmount(amountFrom);
		transactionForAdd.setTransactionAccountFromCurrentAmount(amountFrom);
		auto amountTo = transactionForAdd.getTransactionAccountToLastAmount() + transactionForAdd.getTransactionAmount();
		transactionForAdd.setTransactionAccountToLastAmount(amountTo);
		transactionForAdd.setTransactionAccountToCurrentAmount(amountTo);
	}
}