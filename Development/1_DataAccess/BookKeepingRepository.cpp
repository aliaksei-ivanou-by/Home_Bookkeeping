/*#include "BookKeepingRepository.h"

FinanceRepository::FinanceRepository()
{
	TransactionRepository();
	CategoryRepository();
	CommentRepository();
	PayeeRepository();
	AccountRepository();
	CurrencyRepository();
	DescriptionRepository();
	TagRepository();
}
TransactionRepository FinanceRepository::getTransactionRepository() const
{
	return financeRepositoryTransactions;
}
CategoryRepository FinanceRepository::getCategoryRepository() const
{
	return financeRepositoryCategories;
}
CommentRepository FinanceRepository::getCommentRepository() const
{
	return financeRepositoryComments;
}
PayeeRepository FinanceRepository::getPayeeRepository() const
{
	return financeRepositoryPayees;
}
AccountRepository FinanceRepository::getAccountRepository() const
{
	return financeRepositoryAccounts;
}
CurrencyRepository FinanceRepository::getCurrencyRepository() const
{
	return financeRepositoryCurrencies;
}
DescriptionRepository FinanceRepository::getDescriptionRepository() const
{
	return financeRepositoryDescriptions;
}
TagRepository FinanceRepository::getTagRepository() const
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
}*/