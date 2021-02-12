#include "FinanceRepository.h"

FinanceRepository::FinanceRepository()
{}

void FinanceRepository::addTransaction(Transaction&& transactionForAdd)
{
	financeRepositoryTransactions.addTransaction(std::move(transactionForAdd));
}

void FinanceRepository::addCategory(Category&& categoryForAdd)
{
	financeRepositoryCategories.addCategory(std::move(categoryForAdd));
}

void FinanceRepository::addCurrency(Currency&& currencyForAdd)
{
	financeRepositoryCurrencies.addCurrency(std::move(currencyForAdd));
}

void FinanceRepository::addPayee(Payee&& payeeForAdd)
{
	financeRepositoryPayees.addPayee(std::move(payeeForAdd));
}

void FinanceRepository::addTag(Tag&& tagForAdd)
{
	financeRepositoryTags.addTag(std::move(tagForAdd));
}

void FinanceRepository::addComment(Comment&& commentForAdd)
{
	financeRepositoryComments.addComment(std::move(commentForAdd));
}

void FinanceRepository::addDescription(Description&& descriptionForAdd)
{
	financeRepositoryDescriptions.addDescription(std::move(descriptionForAdd));
}

void FinanceRepository::addAccount(Account&& accountForAdd)
{
	financeRepositoryAccounts.addAccount(std::move(accountForAdd));
}

size_t FinanceRepository::getTransactionRepositorySize() const
{
	return financeRepositoryTransactions.sizeTransactionRepository();
}

size_t FinanceRepository::getCategoryRepositorySize() const
{
	return financeRepositoryCategories.sizeCategoryRepository();
}

size_t FinanceRepository::getCurrencyRepositorySize() const
{
	return financeRepositoryCurrencies.sizeCurrencyRepository();
}

size_t FinanceRepository::getPayeeRepositorySize() const
{
	return financeRepositoryPayees.sizePayeeRepository();
}

size_t FinanceRepository::getTagRepositorySize() const
{
	return financeRepositoryTags.sizeTagRepository();
}

size_t FinanceRepository::getCommentRepositorySize() const
{
	return financeRepositoryComments.sizeCommentRepository();
}

size_t FinanceRepository::getDescriptionRepositorySize() const
{
	return financeRepositoryDescriptions.sizeDescriptionRepository();
}

size_t FinanceRepository::getAccountRepositorySize() const
{
	return financeRepositoryAccounts.sizeAccountRepository();
}

void FinanceRepository::clearTransactionRepository()
{
	financeRepositoryTransactions.clearTransactionRepository();
}

void FinanceRepository::clearCategoryRepository()
{
	financeRepositoryCategories.clearCategoryRepository();
}

void FinanceRepository::clearCurrencyRepository()
{
	financeRepositoryCurrencies.clearCurrencyRepository();
}

void FinanceRepository::clearPayeeRepository()
{
	financeRepositoryPayees.clearPayeeRepository();
}

void FinanceRepository::clearTagRepository()
{
	financeRepositoryTags.clearTagRepository();
}

void FinanceRepository::clearCommentRepository()
{
	financeRepositoryComments.clearCommentRepository();
}

void FinanceRepository::clearDescriptionRepository()
{
	financeRepositoryDescriptions.clearDescriptionRepository();
}

void FinanceRepository::clearAccountRepository()
{
	financeRepositoryAccounts.clearAccountRepository();
}

TransactionRepositoryIterator FinanceRepository::findTransactionRepository(Transaction&& transactionForFind) const
{
	return financeRepositoryTransactions.findTransactionRepository(std::move(transactionForFind));
}

CategoryRepositoryIterator FinanceRepository::findCategoryRepository(Category&& categoryForFind) const
{
	return financeRepositoryCategories.findCategoryRepository(std::move(categoryForFind));
}

CurrencyRepositoryIterator FinanceRepository::findCurrencyRepository(Currency&& currencyForFind) const
{
	return financeRepositoryCurrencies.findCurrencyRepository(std::move(currencyForFind));
}

PayeeRepositoryIterator FinanceRepository::findPayeeRepository(Payee&& payeeForFind) const
{
	return financeRepositoryPayees.findPayeeRepository(std::move(payeeForFind));
}

TagRepositoryIterator FinanceRepository::findTagRepository(Tag&& tagForFind) const
{
	return financeRepositoryTags.findPayeeRepository(std::move(tagForFind));
}

CommentRepositoryIterator FinanceRepository::findCommentRepository(Comment&& commentForFind) const
{
	return financeRepositoryComments.findCommentRepository(std::move(commentForFind));
}

DescriptionRepositoryIterator FinanceRepository::findDescriptionRepository(Description&& descriptionForFind) const
{
	return financeRepositoryDescriptions.findDescriptionRepository(std::move(descriptionForFind));
}

AccountRepositoryIterator FinanceRepository::findAccountRepository(Account&& accountForFind) const
{
	return financeRepositoryAccounts.findAccountRepository(std::move(accountForFind));
}