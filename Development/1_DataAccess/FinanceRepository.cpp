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

size_t FinanceRepository::getTransactionRepositorySize()
{
	return financeRepositoryTransactions.sizeTransactionRepository();
}

size_t FinanceRepository::getCategoryRepositorySize()
{
	return financeRepositoryCategories.sizeCategoryRepository();
}

size_t FinanceRepository::getCurrencyRepositorySize()
{
	return financeRepositoryCurrencies.sizeCurrencyRepository();
}

size_t FinanceRepository::getPayeeRepositorySize()
{
	return financeRepositoryPayees.sizePayeeRepository();
}

size_t FinanceRepository::getTagRepositorySize()
{
	return financeRepositoryTags.sizeTagRepository();
}

size_t FinanceRepository::getCommentRepositorySize()
{
	return financeRepositoryComments.sizeCommentRepository();
}

size_t FinanceRepository::getDescriptionRepositorySize()
{
	return financeRepositoryDescriptions.sizeDescriptionRepository();
}

size_t FinanceRepository::getAccountRepositorySize()
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

TransactionRepositoryIterator FinanceRepository::findTransactionRepository(Transaction&& transactionForFind)
{
	return financeRepositoryTransactions.findTransactionRepository(std::move(transactionForFind));
}

CategoryRepositoryIterator FinanceRepository::findCategoryRepository(Category&& categoryForFind)
{
	return financeRepositoryCategories.findCategoryRepository(std::move(categoryForFind));
}

CurrencyRepositoryIterator FinanceRepository::findCurrencyRepository(Currency&& currencyForFind)
{
	return financeRepositoryCurrencies.findCurrencyRepository(std::move(currencyForFind));
}

PayeeRepositoryIterator FinanceRepository::findPayeeRepository(Payee&& payeeForFind)
{
	return financeRepositoryPayees.findPayeeRepository(std::move(payeeForFind));
}

TagRepositoryIterator FinanceRepository::findTagRepository(Tag&& tagForFind)
{
	return financeRepositoryTags.findPayeeRepository(std::move(tagForFind));
}

CommentRepositoryIterator FinanceRepository::findCommentRepository(Comment&& commentForFind)
{
	return financeRepositoryComments.findCommentRepository(std::move(commentForFind));
}

DescriptionRepositoryIterator FinanceRepository::findDescriptionRepository(Description&& descriptionForFind)
{
	return financeRepositoryDescriptions.findDescriptionRepository(std::move(descriptionForFind));
}

AccountRepositoryIterator FinanceRepository::findAccountRepository(Account&& accountForFind)
{
	return financeRepositoryAccounts.findAccountRepository(std::move(accountForFind));
}