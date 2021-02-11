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