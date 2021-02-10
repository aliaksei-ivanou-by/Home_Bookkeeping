#include "BookKeepingRepository.h"

FinanceRepository::FinanceRepository()
{
	TransactionRepository();
	CategoryRepository();
	CommentRepository();
	PayeeRepository();
	AccountRepository();
	CurrencyRepository();
	CurrencyRateRepository();
	DescriptionRepository();
	TagRepository();
}
TransactionRepository FinanceRepository::getTransactions() const
{
	return financeRepositoryTransactions;
}
CategoryRepository FinanceRepository::getCategories() const
{
	return financeRepositoryCategories;
}
CommentRepository FinanceRepository::getComments() const
{
	return financeRepositoryComments;
}
PayeeRepository FinanceRepository::getPayees() const
{
	return financeRepositoryPayees;
}
AccountRepository FinanceRepository::getAccounts() const
{
	return financeRepositoryAccounts;
}
CurrencyRepository FinanceRepository::getCurrencies() const
{
	return financeRepositoryCurrencies;
}
CurrencyRateRepository FinanceRepository::getCurrenciesRate() const
{
	return financeRepositoryCurrenciesRate;
}
DescriptionRepository FinanceRepository::getDescriptions() const
{
	return financeRepositoryDescriptions;
}
TagRepository FinanceRepository::getTags() const
{
	return financeRepositoryTags;
}
void FinanceRepository::addTransaction(Transaction& transactionForAdd)
{
	financeRepositoryTransactions.addTransaction(transactionForAdd);
}
void FinanceRepository::addCategory(Category categoryForAdd)
{
	financeRepositoryCategories.addCategory(categoryForAdd);
}
void FinanceRepository::addCurrency(Currency currencyForAdd)
{
	financeRepositoryCurrencies.addCurrency(currencyForAdd);
}
void FinanceRepository::addPayee(Payee payeeForAdd)
{
	financeRepositoryPayees.addPayee(payeeForAdd);
}
void FinanceRepository::addTag(Tag tagForAdd)
{
	financeRepositoryTags.addTag(tagForAdd);
}
void FinanceRepository::addComment(Comment commentForAdd)
{
	financeRepositoryComments.addComment(commentForAdd);
}
void FinanceRepository::addDescription(Description descriptionForAdd)
{
	financeRepositoryDescriptions.addDescription(descriptionForAdd);
}
void FinanceRepository::addAccount(Account accountForAdd)
{
	financeRepositoryAccounts.addAccount(accountForAdd);
}