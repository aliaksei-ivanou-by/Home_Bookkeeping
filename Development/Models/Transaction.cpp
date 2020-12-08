#include "Transaction.h"

Transaction::Transaction(
	Account transactionAccountNew, Category transactionCategoryNew, 
	CategorySub transactionCategorySubNew, double transactionAmountNew,
	Comment transactionCommentNew, Currency transactionCurrencyNew,
	CurrencyRate transactionCurrencyRateNew, Description transactionDescriptionNew,
	Payee transactionPayeeNew, Tag transactionTagNew,
	TransactionStatus transactionStatusNew, TransactionType transactionTypeNew):
	transactionAccount{ transactionAccountNew },
	transactionCategory{ transactionCategoryNew },
	transactionCategorySub{ transactionCategorySubNew },
	transactionAmount{ transactionAmountNew },
	transactionComment{ transactionCommentNew },
	transactionCurrency{ transactionCurrencyNew },
	transactionCurrencyRate{ transactionCurrencyRateNew },
	transactionDescription{ transactionDescriptionNew },
	transactionPayee{ transactionPayeeNew },
	transactionTag{ transactionTagNew },
	transactionStatus{ transactionStatusNew },
	transactionType{ transactionTypeNew }
{}

Transaction::Transaction(
	Account transactionAccountNew, Category transactionCategoryNew, 
	CategorySub transactionCategorySubNew, double transactionAmountNew,
	Currency transactionCurrencyNew):
	transactionAccount{ transactionAccountNew },
	transactionCategory{ transactionCategoryNew },
	transactionCategorySub{ transactionCategorySubNew },
	transactionAmount{ transactionAmountNew },
	transactionComment{ },
	transactionCurrency{ transactionCurrencyNew },
	transactionCurrencyRate{ },
	transactionDescription{ },
	transactionPayee{ },
	transactionTag{ },
	transactionStatus{ },
	transactionType{ }
{}

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

void Transaction::setTransactionAccount(Account&& accountNew)
{
	transactionAccount = std::move(accountNew);
}

void Transaction::setTransactionCategory(Category&& categoryNew)
{
	transactionCategory = std::move(categoryNew);
}

void Transaction::setTransactionCategorySub(CategorySub&& categorySubNew)
{
	transactionCategorySub = std::move(categorySubNew);
}

void Transaction::setTransactionComment(Comment&& commentNew)
{
	transactionComment = std::move(commentNew);
}

void Transaction::setTransactionCurrency(Currency&& currencyNew)
{
	transactionCurrency = std::move(currencyNew);
}

void Transaction::setTransactionCurrencyRate(CurrencyRate&& currencyRateNew)
{
	transactionCurrencyRate = std::move(currencyRateNew);
}

void Transaction::setTransactionDescription(Description&& descriptionNew)
{
	transactionDescription = std::move(descriptionNew);
}

void Transaction::setTransactionPayee(Payee&& payeeNew)
{
	transactionPayee = std::move(payeeNew);
}

void Transaction::setTransactionTag(Tag&& tagNew)
{
	transactionTag = std::move(tagNew);
}

void Transaction::setTransactionTransactionStatus(TransactionStatus&& transactionStatusNew)
{
	transactionStatus = std::move(transactionStatusNew);
}

void Transaction::setTransactionTransactionTyoe(TransactionType&& transactionTypeNew)
{
	transactionType = std::move(transactionTypeNew);
}

bool operator<(const Transaction& leftTransaction, const Transaction& rightTransaction)
{
	return (leftTransaction.getTransactionAccount() < rightTransaction.getTransactionAccount());
}

std::ostream& operator<<(std::ostream& outputStream, const Transaction& transaction)
{
	return outputStream << transaction.getTransactionAccount() << '\t' <<
		transaction.getTransactionCategory() << '\t' <<
		transaction.getTransactionCategorySub() << '\t' <<
		transaction.getTransactionAmount() << ' ' <<
		transaction.getTransactionCurrency().getCurrencyName();
}