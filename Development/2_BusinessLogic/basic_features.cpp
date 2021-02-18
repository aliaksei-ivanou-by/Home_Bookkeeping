#include "FinanceRepository.h"

FinanceRepository::FinanceRepository()
{}

void FinanceRepository::addTransaction(Transaction& transactionForAdd)
{
	updateAccountAmount(transactionForAdd);

	if (financeRepositoryAccounts.size() == 0)
	{
		financeRepositoryAccounts.add(transactionForAdd.getTransactionAccountPtrFrom());
	}
	else
	{
		if (financeRepositoryAccounts.find(transactionForAdd.getTransactionAccountPtrFrom()) == financeRepositoryAccounts.end())
		{
			financeRepositoryAccounts.add(transactionForAdd.getTransactionAccountPtrFrom());
		}
	}
	financeRepositoryTransactions.add(transactionForAdd);
}

void FinanceRepository::addCategory(const Category& categoryForAdd)
{
	financeRepositoryCategories.add(categoryForAdd);
}

void FinanceRepository::addCurrency(const Currency& currencyForAdd)
{
	financeRepositoryCurrencies.add(currencyForAdd);
}

void FinanceRepository::addPayee(const Payee& payeeForAdd)
{
	financeRepositoryPayees.add(payeeForAdd);
}

void FinanceRepository::addTag(const Tag& tagForAdd)
{
	financeRepositoryTags.add(tagForAdd);
}

void FinanceRepository::addComment(const Comment& commentForAdd)
{
	financeRepositoryComments.add(commentForAdd);
}

void FinanceRepository::addDescription(const Description& descriptionForAdd)
{
	financeRepositoryDescriptions.add(descriptionForAdd);
}

void FinanceRepository::addAccount(const Account& accountForAdd)
{
	financeRepositoryAccounts.add(accountForAdd);
}

void FinanceRepository::removeTransaction(const Transaction& transactionForRemove)
{
	financeRepositoryTransactions.remove(transactionForRemove);
}

void FinanceRepository::removeCategory(const Category& categoryForRemove)
{
	financeRepositoryCategories.remove(categoryForRemove);

}
void FinanceRepository::removeCurrency(const Currency& currencyForRemove)
{
	financeRepositoryCurrencies.remove(currencyForRemove);
}

void FinanceRepository::removePayee(const Payee& payeeForRemove)
{
	financeRepositoryPayees.remove(payeeForRemove);
}

void FinanceRepository::removeTag(const Tag& tagForRemove)
{
	financeRepositoryTags.remove(tagForRemove);
}

void FinanceRepository::removeComment(const Comment& commentForRemove)
{
	financeRepositoryComments.remove(commentForRemove);
}

void FinanceRepository::removeDescription(const Description& descriptionForRemove)
{
	financeRepositoryDescriptions.remove(descriptionForRemove);
}

void FinanceRepository::removeAccount(const Account& accountForRemove)
{
	financeRepositoryAccounts.remove(accountForRemove);
}

size_t FinanceRepository::getTransactionsNumber() const
{
	return financeRepositoryTransactions.size();
}

size_t FinanceRepository::getCategoriesNumber() const
{
	return financeRepositoryCategories.size();
}

size_t FinanceRepository::getCurrenciesNumber() const
{
	return financeRepositoryCurrencies.size();
}

size_t FinanceRepository::getPayeesNumber() const
{
	return financeRepositoryPayees.size();
}

size_t FinanceRepository::getTagsNumber() const
{
	return financeRepositoryTags.size();
}

size_t FinanceRepository::getCommentsNumber() const
{
	return financeRepositoryComments.size();
}

size_t FinanceRepository::getDescriptionsNumber() const
{
	return financeRepositoryDescriptions.size();
}

size_t FinanceRepository::getAccountsNumber() const
{
	return financeRepositoryAccounts.size();
}

void FinanceRepository::clearTransactions()
{
	financeRepositoryTransactions.clear();
}

void FinanceRepository::clearCategories()
{
	financeRepositoryCategories.clear();
}

void FinanceRepository::clearCurrencies()
{
	financeRepositoryCurrencies.clear();
}

void FinanceRepository::clearPayees()
{
	financeRepositoryPayees.clear();
}

void FinanceRepository::clearTags()
{
	financeRepositoryTags.clear();
}

void FinanceRepository::clearComments()
{
	financeRepositoryComments.clear();
}

void FinanceRepository::clearDescriptions()
{
	financeRepositoryDescriptions.clear();
}

void FinanceRepository::clearAccounts()
{
	financeRepositoryAccounts.clear();
}

TransactionRepositoryIterator FinanceRepository::findTransaction(const Transaction& transactionForFind) const
{
	return financeRepositoryTransactions.find(transactionForFind);
}

CategoryRepositoryIterator FinanceRepository::findCategory(const Category& categoryForFind) const
{
	return financeRepositoryCategories.find(categoryForFind);
}

CurrencyRepositoryIterator FinanceRepository::findCurrency(const Currency& currencyForFind) const
{
	return financeRepositoryCurrencies.find(currencyForFind);
}

PayeeRepositoryIterator FinanceRepository::findPayee(const Payee& payeeForFind) const
{
	return financeRepositoryPayees.find(payeeForFind);
}

TagRepositoryIterator FinanceRepository::findTag(const Tag& tagForFind) const
{
	return financeRepositoryTags.find(tagForFind);
}

CommentRepositoryIterator FinanceRepository::findComment(const Comment& commentForFind) const
{
	return financeRepositoryComments.find(commentForFind);
}

DescriptionRepositoryIterator FinanceRepository::findDescription(const Description& descriptionForFind) const
{
	return financeRepositoryDescriptions.find(descriptionForFind);
}

AccountRepositoryIterator FinanceRepository::findAccount(const Account& accountForFind) const
{
	return financeRepositoryAccounts.find(accountForFind);
}

TransactionRepositoryIterator FinanceRepository::beginTransactionRepository() const
{
	return financeRepositoryTransactions.begin();
}

CategoryRepositoryIterator FinanceRepository::beginCategoryRepository() const
{
	return financeRepositoryCategories.begin();
}

CurrencyRepositoryIterator FinanceRepository::beginCurrencyRepository() const
{
	return financeRepositoryCurrencies.begin();
}

PayeeRepositoryIterator FinanceRepository::beginPayeeRepository() const
{
	return financeRepositoryPayees.begin();
}

TagRepositoryIterator FinanceRepository::beginTagRepository() const
{
	return financeRepositoryTags.begin();
}

CommentRepositoryIterator FinanceRepository::beginCommentRepository() const
{
	return financeRepositoryComments.begin();
}

DescriptionRepositoryIterator FinanceRepository::beginDescriptionRepository() const
{
	return financeRepositoryDescriptions.begin();
}

AccountRepositoryIterator FinanceRepository::beginAccountRepository() const
{
	return financeRepositoryAccounts.begin();
}

TransactionRepositoryIterator FinanceRepository::endTransactionRepository() const
{
	return financeRepositoryTransactions.end();
}

CategoryRepositoryIterator FinanceRepository::endCategoryRepository() const
{
	return financeRepositoryCategories.end();
}

CurrencyRepositoryIterator FinanceRepository::endCurrencyRepository() const
{
	return financeRepositoryCurrencies.end();
}

PayeeRepositoryIterator FinanceRepository::endPayeeRepository() const
{
	return financeRepositoryPayees.end();
}

TagRepositoryIterator FinanceRepository::endTagRepository() const
{
	return financeRepositoryTags.end();
}

CommentRepositoryIterator FinanceRepository::endCommentRepository() const
{
	return financeRepositoryComments.end();
}

DescriptionRepositoryIterator FinanceRepository::endDescriptionRepository() const
{
	return financeRepositoryDescriptions.end();
}

AccountRepositoryIterator FinanceRepository::endAccountRepository() const
{
	return financeRepositoryAccounts.end();
}

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

void FinanceRepository::printTransactions(const std::string& delimeter, std::ostream& outputStream) const
{
	auto i = beginTransactionRepository();
	while (i != endTransactionRepository())
	{
		outputStream << *i;
		++i;
		if (i != endTransactionRepository())
		{
			outputStream << delimeter;
		}
	}
}

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

void FinanceRepository::updateAccountAmount(Transaction& transactionForAdd)
{
	if (transactionForAdd.getTransactionType() == TransactionType(TransactionTypeEnum::Expence))
	{
		auto amount1 = transactionForAdd.getTransactionAccountFromLastAmount() - transactionForAdd.getTransactionAmount();
		transactionForAdd.setTransactionAccountFromLastAmount(amount1);
		transactionForAdd.setTransactionAccountToLastAmount(amount1);
		auto amount2 = transactionForAdd.getTransactionAccountFromLastAmount();
		transactionForAdd.setTransactionAccountFromCurrentAmount(amount2);
		transactionForAdd.setTransactionAccountToCurrentAmount(amount2);
	}
	if (transactionForAdd.getTransactionType() == TransactionType(TransactionTypeEnum::Income))
	{
		auto amount1 = transactionForAdd.getTransactionAccountFromLastAmount() + transactionForAdd.getTransactionAmount();
		transactionForAdd.setTransactionAccountFromLastAmount(amount1);
		transactionForAdd.setTransactionAccountToLastAmount(amount1);
		auto amount2 = transactionForAdd.getTransactionAccountFromLastAmount();
		transactionForAdd.setTransactionAccountFromCurrentAmount(amount2);
		transactionForAdd.setTransactionAccountToCurrentAmount(amount2);
	}
	if (transactionForAdd.getTransactionType() == TransactionType(TransactionTypeEnum::Transfer))
	{

	}
}