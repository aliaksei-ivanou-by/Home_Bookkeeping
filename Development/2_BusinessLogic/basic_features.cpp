#include "FinanceRepository.h"

FinanceRepository::FinanceRepository()
{}

void FinanceRepository::addTransaction(Transaction&& transactionForAdd)
{
	financeRepositoryTransactions.add(std::move(transactionForAdd));
}

void FinanceRepository::addCategory(Category&& categoryForAdd)
{
	financeRepositoryCategories.add(std::move(categoryForAdd));
}

void FinanceRepository::addCurrency(Currency&& currencyForAdd)
{
	financeRepositoryCurrencies.add(std::move(currencyForAdd));
}

void FinanceRepository::addPayee(Payee&& payeeForAdd)
{
	financeRepositoryPayees.add(std::move(payeeForAdd));
}

void FinanceRepository::addTag(Tag&& tagForAdd)
{
	financeRepositoryTags.add(std::move(tagForAdd));
}

void FinanceRepository::addComment(Comment&& commentForAdd)
{
	financeRepositoryComments.add(std::move(commentForAdd));
}

void FinanceRepository::addDescription(Description&& descriptionForAdd)
{
	financeRepositoryDescriptions.add(std::move(descriptionForAdd));
}

void FinanceRepository::addAccount(Account&& accountForAdd)
{
	financeRepositoryAccounts.add(std::move(accountForAdd));
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

TransactionRepositoryIterator FinanceRepository::findTransaction(Transaction&& transactionForFind) const
{
	return financeRepositoryTransactions.find(std::move(transactionForFind));
}

CategoryRepositoryIterator FinanceRepository::findCategory(Category&& categoryForFind) const
{
	return financeRepositoryCategories.find(std::move(categoryForFind));
}

CurrencyRepositoryIterator FinanceRepository::findCurrency(Currency&& currencyForFind) const
{
	return financeRepositoryCurrencies.find(std::move(currencyForFind));
}

PayeeRepositoryIterator FinanceRepository::findPayee(Payee&& payeeForFind) const
{
	return financeRepositoryPayees.find(std::move(payeeForFind));
}

TagRepositoryIterator FinanceRepository::findTag(Tag&& tagForFind) const
{
	return financeRepositoryTags.find(std::move(tagForFind));
}

CommentRepositoryIterator FinanceRepository::findComment(Comment&& commentForFind) const
{
	return financeRepositoryComments.find(std::move(commentForFind));
}

DescriptionRepositoryIterator FinanceRepository::findDescription(Description&& descriptionForFind) const
{
	return financeRepositoryDescriptions.find(std::move(descriptionForFind));
}

AccountRepositoryIterator FinanceRepository::findAccount(Account&& accountForFind) const
{
	return financeRepositoryAccounts.find(std::move(accountForFind));
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