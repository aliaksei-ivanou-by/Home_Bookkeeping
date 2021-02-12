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

size_t FinanceRepository::getTransactionRepositorySize() const
{
	return financeRepositoryTransactions.size();
}

size_t FinanceRepository::getCategoryRepositorySize() const
{
	return financeRepositoryCategories.size();
}

size_t FinanceRepository::getCurrencyRepositorySize() const
{
	return financeRepositoryCurrencies.size();
}

size_t FinanceRepository::getPayeeRepositorySize() const
{
	return financeRepositoryPayees.size();
}

size_t FinanceRepository::getTagRepositorySize() const
{
	return financeRepositoryTags.size();
}

size_t FinanceRepository::getCommentRepositorySize() const
{
	return financeRepositoryComments.size();
}

size_t FinanceRepository::getDescriptionRepositorySize() const
{
	return financeRepositoryDescriptions.size();
}

size_t FinanceRepository::getAccountRepositorySize() const
{
	return financeRepositoryAccounts.size();
}

void FinanceRepository::clearTransactionRepository()
{
	financeRepositoryTransactions.clear();
}

void FinanceRepository::clearCategoryRepository()
{
	financeRepositoryCategories.clear();
}

void FinanceRepository::clearCurrencyRepository()
{
	financeRepositoryCurrencies.clear();
}

void FinanceRepository::clearPayeeRepository()
{
	financeRepositoryPayees.clear();
}

void FinanceRepository::clearTagRepository()
{
	financeRepositoryTags.clear();
}

void FinanceRepository::clearCommentRepository()
{
	financeRepositoryComments.clear();
}

void FinanceRepository::clearDescriptionRepository()
{
	financeRepositoryDescriptions.clear();
}

void FinanceRepository::clearAccountRepository()
{
	financeRepositoryAccounts.clear();
}

TransactionRepositoryIterator FinanceRepository::findTransactionRepository(Transaction&& transactionForFind) const
{
	return financeRepositoryTransactions.find(std::move(transactionForFind));
}

CategoryRepositoryIterator FinanceRepository::findCategoryRepository(Category&& categoryForFind) const
{
	return financeRepositoryCategories.find(std::move(categoryForFind));
}

CurrencyRepositoryIterator FinanceRepository::findCurrencyRepository(Currency&& currencyForFind) const
{
	return financeRepositoryCurrencies.find(std::move(currencyForFind));
}

PayeeRepositoryIterator FinanceRepository::findPayeeRepository(Payee&& payeeForFind) const
{
	return financeRepositoryPayees.find(std::move(payeeForFind));
}

TagRepositoryIterator FinanceRepository::findTagRepository(Tag&& tagForFind) const
{
	return financeRepositoryTags.find(std::move(tagForFind));
}

CommentRepositoryIterator FinanceRepository::findCommentRepository(Comment&& commentForFind) const
{
	return financeRepositoryComments.find(std::move(commentForFind));
}

DescriptionRepositoryIterator FinanceRepository::findDescriptionRepository(Description&& descriptionForFind) const
{
	return financeRepositoryDescriptions.find(std::move(descriptionForFind));
}

AccountRepositoryIterator FinanceRepository::findAccountRepository(Account&& accountForFind) const
{
	return financeRepositoryAccounts.find(std::move(accountForFind));
}