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
	return financeRepositoryAccounts.Begin();
}

// Class member function. Find begin iterator of repository of categories
CategoryRepositoryIterator FinanceRepository::beginCategoryRepository() const
{
	return financeRepositoryCategories.Begin();
}

// Class member function. Find begin iterator of repository of currencies
CurrencyRepositoryIterator FinanceRepository::beginCurrencyRepository() const
{
	return financeRepositoryCurrencies.Begin();
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
	return financeRepositoryComments.Begin();
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
	return financeRepositoryAccounts.End();
}

// Class member function. Find end iterator of repository of categories
CategoryRepositoryIterator FinanceRepository::endCategoryRepository() const
{
	return financeRepositoryCategories.End();
}

// Class member function. Find end iterator of repository of currencies
CurrencyRepositoryIterator FinanceRepository::endCurrencyRepository() const
{
	return financeRepositoryCurrencies.End();
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
	return financeRepositoryComments.End();
}

// Class member function. Find end iterator of repository of tags
TagRepositoryIterator FinanceRepository::endTagRepository() const
{
	return financeRepositoryTags.end();
}

// Class member function. Add transaction to repository of transactions
void FinanceRepository::addTransaction(Transaction& transactionForAdd)
{
	updateAccountRepository(transactionForAdd);
	updateAccountAmount(transactionForAdd);

	updateCategoryRepository(transactionForAdd);
	updateCurrencyRepository(transactionForAdd);
	updateDescriptionRepository(transactionForAdd);
	updatePayeeRepository(transactionForAdd);
	updateCommentRepository(transactionForAdd);
	updateTagRepository(transactionForAdd);

	financeRepositoryTransactions.add(transactionForAdd);
}

// Class member function. Add account to repository of accounts
void FinanceRepository::addAccount(const Account& accountForAdd)
{
	financeRepositoryAccounts.Add(accountForAdd);
}

// Class member function. Add category to repository of categories
void FinanceRepository::addCategory(const Category& categoryForAdd)
{
	financeRepositoryCategories.Add(categoryForAdd);
}

// Class member function. Add currency to repository of currencies
void FinanceRepository::addCurrency(const Currency& currencyForAdd)
{
	financeRepositoryCurrencies.Add(currencyForAdd);
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
	financeRepositoryComments.Add(commentForAdd);
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
	financeRepositoryAccounts.Remove(accountForRemove);
}

// Class member function. Remove category(shared pointer to category) from repository of categories
void FinanceRepository::removeCategory(std::shared_ptr<Category> categoryForRemove)
{
	financeRepositoryCategories.Remove(categoryForRemove);

}

// Class member function. Remove currency (shared pointer to currency) from repository of currencies
void FinanceRepository::removeCurrency(std::shared_ptr<Currency> currencyForRemove)
{
	financeRepositoryCurrencies.Remove(currencyForRemove);
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
	financeRepositoryComments.Remove(commentForRemove);
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
	return financeRepositoryAccounts.Size();
}

// Class member function. Calculate number of elements in categories repository
size_t FinanceRepository::getCategoriesNumber() const
{
	return financeRepositoryCategories.Size();
}

// Class member function. Calculate number of elements in currencies repository
size_t FinanceRepository::getCurrenciesNumber() const
{
	return financeRepositoryCurrencies.Size();
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
	return financeRepositoryComments.Size();
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
	financeRepositoryAccounts.Clear();
}

// Class member function. Clear categories repository
void FinanceRepository::clearCategories()
{
	financeRepositoryCategories.Clear();
}

// Class member function. Clear currencies repository
void FinanceRepository::clearCurrencies()
{
	financeRepositoryCurrencies.Clear();
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
	financeRepositoryComments.Clear();
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
	return financeRepositoryAccounts.Find(accountForFind);
}

// Class member function. Find category (shared pointer) in categories repository
CategoryRepositoryIterator FinanceRepository::findCategory(std::shared_ptr<Category> categoryForFind) const
{
	return financeRepositoryCategories.Find(categoryForFind);
}

// Class member function. Find currency (shared pointer) in currencies repository
CurrencyRepositoryIterator FinanceRepository::findCurrency(std::shared_ptr<Currency> currencyForFind) const
{
	return financeRepositoryCurrencies.Find(currencyForFind);
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
	return financeRepositoryComments.Find(commentForFind);
}

// Class member function. Find tag (shared pointer) in tags repository
TagRepositoryIterator FinanceRepository::findTag(std::shared_ptr<Tag> tagForFind) const
{
	return financeRepositoryTags.find(tagForFind);
}

// Class member function. Update last amount of account in accounts repository with adding new transaction
void FinanceRepository::updateAccountAmount(Transaction& transactionForAdd)
{
	if (transactionForAdd.GetType() == Type(kEnumType::Expense))
	{
		auto amount = transactionForAdd.GetAmountLastestAccountFrom() - transactionForAdd.GetAmount();
		transactionForAdd.SetAmountLastestAccountFrom(amount);
		transactionForAdd.SetAmountLastestAccountTo(amount);
		transactionForAdd.SetAmountAccountFrom(amount);
		transactionForAdd.SetAmountAccountTo(amount);
	}
	if (transactionForAdd.GetType() == Type(kEnumType::Income))
	{
		auto amount = transactionForAdd.GetAmountLastestAccountFrom() + transactionForAdd.GetAmount();
		transactionForAdd.SetAmountLastestAccountFrom(amount);
		transactionForAdd.SetAmountLastestAccountTo(amount);
		transactionForAdd.SetAmountAccountFrom(amount);
		transactionForAdd.SetAmountAccountTo(amount);
	}
	if (transactionForAdd.GetType() == Type(kEnumType::Transfer))
	{
		auto amountFrom = transactionForAdd.GetAmountLastestAccountFrom() - transactionForAdd.GetAmount();
		transactionForAdd.SetAmountLastestAccountFrom(amountFrom);
		transactionForAdd.SetAmountAccountFrom(amountFrom);
		auto amountTo = transactionForAdd.GetAmountLastestAccountTo() + transactionForAdd.GetAmount();
		transactionForAdd.SetAmountLastestAccountTo(amountTo);
		transactionForAdd.SetAmountAccountTo(amountTo);
	}
}

// Class member function. Update accounts repository with adding new transaction
void FinanceRepository::updateAccountRepository(Transaction& transactionForAdd)
{
	if (financeRepositoryAccounts.Size() == 0)
	{
		financeRepositoryAccounts.Add(transactionForAdd.GetAccountFromPtr());
	}
	else
	{
		bool keyFrom = false;
		for (auto i = financeRepositoryAccounts.Begin(); i != financeRepositoryAccounts.End(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetAccountFrom().GetName())
			{
				keyFrom = true;
				transactionForAdd.SetAccountFromPtr(*i);
				break;
			}
		}
		if (!keyFrom)
		{
			financeRepositoryAccounts.Add(transactionForAdd.GetAccountFromPtr());
		}
		bool keyTo = false;
		for (auto i = financeRepositoryAccounts.Begin(); i != financeRepositoryAccounts.End(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetAccountTo().GetName())
			{
				keyTo = true;
				transactionForAdd.SetAccountToPtr(*i);
				break;
			}
		}
		if (!keyTo)
		{
			financeRepositoryAccounts.Add(transactionForAdd.GetAccountToPtr());
		}
	}
}

// Class member function. Update categories repository with adding new transaction
void FinanceRepository::updateCategoryRepository(Transaction& transactionForAdd)
{
	if (financeRepositoryCategories.Size() == 0)
	{
		financeRepositoryCategories.Add(transactionForAdd.GetCategoryPtr());
	}
	else
	{
		bool keyFrom = false;
		for (auto i = financeRepositoryCategories.Begin(); i != financeRepositoryCategories.End(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetCategory().GetName())
			{
				keyFrom = true;
				transactionForAdd.SetCategoryPtr(*i);
				break;
			}
		}
		if (!keyFrom)
		{
			financeRepositoryCategories.Add(transactionForAdd.GetCategory());
		}
		bool keyTo = false;
		for (auto i = financeRepositoryCategories.Begin(); i != financeRepositoryCategories.End(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetCategory().GetName())
			{
				keyTo = true;
				transactionForAdd.SetCategoryPtr(*i);
				break;
			}
		}
		if (!keyTo)
		{
			financeRepositoryCategories.Add(transactionForAdd.GetCategoryPtr());
		}
	}
}

// Class member function. Update currencies repository with adding new transaction
void FinanceRepository::updateCurrencyRepository(Transaction& transactionForAdd)
{
	if (financeRepositoryCurrencies.Size() == 0)
	{
		financeRepositoryCurrencies.Add(transactionForAdd.GetCurrencyPtr());
	}
	else
	{
		bool keyFrom = false;
		for (auto i = financeRepositoryCurrencies.Begin(); i != financeRepositoryCurrencies.End(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetCurrency().GetName())
			{
				keyFrom = true;
				transactionForAdd.SetCurrencyPtr(*i);
				break;
			}
		}
		if (!keyFrom)
		{
			financeRepositoryCurrencies.Add(transactionForAdd.GetCurrency());
		}
		bool keyTo = false;
		for (auto i = financeRepositoryCurrencies.Begin(); i != financeRepositoryCurrencies.End(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetCurrency().GetName())
			{
				keyTo = true;
				transactionForAdd.SetCurrencyPtr(*i);
				break;
			}
		}
		if (!keyTo)
		{
			financeRepositoryCurrencies.Add(transactionForAdd.GetCurrencyPtr());
		}
	}
}

// Class member function. Update descriptions repository with adding new transaction
void FinanceRepository::updateDescriptionRepository(Transaction& transactionForAdd)
{
	if (financeRepositoryDescriptions.size() == 0)
	{
		financeRepositoryDescriptions.add(transactionForAdd.GetDescriptionPtr());
	}
	else
	{
		bool keyFrom = false;
		for (auto i = financeRepositoryDescriptions.begin(); i != financeRepositoryDescriptions.end(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetDescription().GetName())
			{
				keyFrom = true;
				transactionForAdd.SetDescriptionPtr(*i);
				break;
			}
		}
		if (!keyFrom)
		{
			financeRepositoryDescriptions.add(transactionForAdd.GetDescription());
		}
		bool keyTo = false;
		for (auto i = financeRepositoryDescriptions.begin(); i != financeRepositoryDescriptions.end(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetDescription().GetName())
			{
				keyTo = true;
				transactionForAdd.SetDescriptionPtr(*i);
				break;
			}
		}
		if (!keyTo)
		{
			financeRepositoryDescriptions.add(transactionForAdd.GetDescriptionPtr());
		}
	}
}

// Class member function. Update payees repository with adding new transaction
void FinanceRepository::updatePayeeRepository(Transaction& transactionForAdd)
{
	if (financeRepositoryPayees.size() == 0)
	{
		financeRepositoryPayees.add(transactionForAdd.GetPayeePtr());
	}
	else
	{
		bool keyFrom = false;
		for (auto i = financeRepositoryPayees.begin(); i != financeRepositoryPayees.end(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetPayee().GetName())
			{
				keyFrom = true;
				transactionForAdd.SetPayeePtr(*i);
				break;
			}
		}
		if (!keyFrom)
		{
			financeRepositoryPayees.add(transactionForAdd.GetPayee());
		}
		bool keyTo = false;
		for (auto i = financeRepositoryPayees.begin(); i != financeRepositoryPayees.end(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetPayee().GetName())
			{
				keyTo = true;
				transactionForAdd.SetPayeePtr(*i);
				break;
			}
		}
		if (!keyTo)
		{
			financeRepositoryPayees.add(transactionForAdd.GetPayeePtr());
		}
	}
}

// Class member function. Update comments repository with adding new transaction
void FinanceRepository::updateCommentRepository(Transaction& transactionForAdd)
{
	if (financeRepositoryComments.Size() == 0)
	{
		financeRepositoryComments.Add(transactionForAdd.GetCommentPtr());
	}
	else
	{
		bool keyFrom = false;
		for (auto i = financeRepositoryComments.Begin(); i != financeRepositoryComments.End(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetComment().GetName())
			{
				keyFrom = true;
				transactionForAdd.SetCommentPtr(*i);
				break;
			}
		}
		if (!keyFrom)
		{
			financeRepositoryComments.Add(transactionForAdd.GetComment());
		}
		bool keyTo = false;
		for (auto i = financeRepositoryComments.Begin(); i != financeRepositoryComments.End(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetComment().GetName())
			{
				keyTo = true;
				transactionForAdd.SetCommentPtr(*i);
				break;
			}
		}
		if (!keyTo)
		{
			financeRepositoryComments.Add(transactionForAdd.GetCommentPtr());
		}
	}
}

// Class member function. Update tags repository with adding new transaction
void FinanceRepository::updateTagRepository(Transaction& transactionForAdd)
{
	if (financeRepositoryTags.size() == 0)
	{
		financeRepositoryTags.add(transactionForAdd.GetTagPtr());
	}
	else
	{
		bool keyFrom = false;
		for (auto i = financeRepositoryTags.begin(); i != financeRepositoryTags.end(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetTag().GetName())
			{
				keyFrom = true;
				transactionForAdd.SetTagPtr(*i);
				break;
			}
		}
		if (!keyFrom)
		{
			financeRepositoryTags.add(transactionForAdd.GetTag());
		}
		bool keyTo = false;
		for (auto i = financeRepositoryTags.begin(); i != financeRepositoryTags.end(); ++i)
		{
			if ((**i).GetName() == transactionForAdd.GetTag().GetName())
			{
				keyTo = true;
				transactionForAdd.SetTagPtr(*i);
				break;
			}
		}
		if (!keyTo)
		{
			financeRepositoryTags.add(transactionForAdd.GetTagPtr());
		}
	}
}