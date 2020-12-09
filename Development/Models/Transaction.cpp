#include "Transaction.h"

Transaction::Transaction(
	Account transactionAccountForAdd, Category transactionCategoryForAdd, 
	CategorySub transactionCategorySubForAdd, double transactionAmountForAdd,
	Comment transactionCommentForAdd, Currency transactionCurrencyForAdd,
	CurrencyRate transactionCurrencyRateForAdd, Description transactionDescriptionForAdd,
	Payee transactionPayeeForAdd, Tag transactionTagForAdd,
	TransactionStatus transactionStatusForAdd, TransactionType transactionTypeForAdd):
	transactionTime{},
	transactionAccount{ transactionAccountForAdd },
	transactionCategory{ transactionCategoryForAdd },
	transactionCategorySub{ transactionCategorySubForAdd },
	transactionAmount{ transactionAmountForAdd },
	transactionComment{ transactionCommentForAdd },
	transactionCurrency{ transactionCurrencyForAdd },
	transactionCurrencyRate{ transactionCurrencyRateForAdd },
	transactionDescription{ transactionDescriptionForAdd },
	transactionPayee{ transactionPayeeForAdd },
	transactionTag{ transactionTagForAdd },
	transactionStatus{ transactionStatusForAdd },
	transactionType{ transactionTypeForAdd }
{}

Transaction::Transaction(
	Account transactionAccountForAdd, Category transactionCategoryForAdd,
	CategorySub transactionCategorySubForAdd, double transactionAmountForAdd,
	Currency transactionCurrencyForAdd):
	transactionTime{},
	transactionAccount{ transactionAccountForAdd },
	transactionCategory{ transactionCategoryForAdd },
	transactionCategorySub{ transactionCategorySubForAdd },
	transactionAmount{ transactionAmountForAdd },
	transactionComment{ },
	transactionCurrency{ transactionCurrencyForAdd },
	transactionCurrencyRate{ },
	transactionDescription{ },
	transactionPayee{ },
	transactionTag{ },
	transactionStatus{ },
	transactionType{ }
{}

Time Transaction::getTransactionTime() const
{
	return transactionTime;
}

Account Transaction::getTransactionAccount() const
{
	return transactionAccount;
}

Category Transaction::getTransactionCategory() const
{
	return transactionCategory;
}

CategorySub Transaction::getTransactionCategorySub() const
{
	return transactionCategorySub;
}

double Transaction::getTransactionAmount() const
{
	return transactionAmount;
}

Comment Transaction::getTransactionComment() const
{
	return transactionComment;
}

Currency Transaction::getTransactionCurrency() const
{
	return transactionCurrency;
}

CurrencyRate Transaction::getTransactionCurrencyRate() const
{
	return transactionCurrencyRate;
}

Description Transaction::getTransactionDescription() const
{
	return transactionDescription;
}

Payee Transaction::getTransactionPayee() const
{
	return transactionPayee;
}

Tag Transaction::getTransactionTag() const
{
	return transactionTag;
}

TransactionStatus Transaction::getTransactionStatus() const
{
	return transactionStatus;
}

TransactionType Transaction::getTransactionType() const
{
	return transactionType;
}

void Transaction::setTransactionTime(Time&& timeForUpdate)
{
	transactionTime = std::move(timeForUpdate);
}

void Transaction::setTransactionAccount(Account&& accountForUpdate)
{
	transactionAccount = std::move(accountForUpdate);
}

void Transaction::setTransactionCategory(Category&& categoryForUpdate)
{
	transactionCategory = std::move(categoryForUpdate);
}

void Transaction::setTransactionCategorySub(CategorySub&& categorySubForUpdate)
{
	transactionCategorySub = std::move(categorySubForUpdate);
}

void Transaction::setTransactionComment(Comment&& commentForUpdate)
{
	transactionComment = std::move(commentForUpdate);
}

void Transaction::setTransactionCurrency(Currency&& currencyForUpdate)
{
	transactionCurrency = std::move(currencyForUpdate);
}

void Transaction::setTransactionCurrencyRate(CurrencyRate&& currencyRateForUpdate)
{
	transactionCurrencyRate = std::move(currencyRateForUpdate);
}

void Transaction::setTransactionDescription(Description&& descriptionForUpdate)
{
	transactionDescription = std::move(descriptionForUpdate);
}

void Transaction::setTransactionPayee(Payee&& payeeForUpdate)
{
	transactionPayee = std::move(payeeForUpdate);
}

void Transaction::setTransactionTag(Tag&& tagForUpdate)
{
	transactionTag = std::move(tagForUpdate);
}

void Transaction::setTransactionTransactionStatus(TransactionStatus&& transactionStatusForUpdate)
{
	transactionStatus = std::move(transactionStatusForUpdate);
}

void Transaction::setTransactionTransactionTyoe(TransactionType&& transactionTypeForUpdate)
{
	transactionType = std::move(transactionTypeForUpdate);
}

bool operator<(const Transaction& leftTransaction, const Transaction& rightTransaction)
{
	return (leftTransaction.getTransactionAccount() < rightTransaction.getTransactionAccount());
}

std::ostream& operator<<(std::ostream& outputStream, const Transaction& transaction)
{
	return outputStream << transaction.getTransactionTime() << '\t' <<
		transaction.getTransactionAccount() << '\t' <<
		transaction.getTransactionCategory() << '\t' <<
		transaction.getTransactionCategorySub() << '\t' <<
		transaction.getTransactionAmount() << ' ' <<
		transaction.getTransactionCurrency().getCurrencyName();
}