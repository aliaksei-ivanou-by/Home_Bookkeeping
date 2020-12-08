#pragma once

#include "../include/stdafx.h"
#include "../include/Models.h"

class Transaction
{
private:
	Account transactionAccount;
	Category transactionCategory;
	CategorySub transactionCategorySub;
	double transactionAmount;
	Comment transactionComment;
	Currency transactionCurrency;
	CurrencyRate transactionCurrencyRate;
	Description transactionDescription;
	Payee transactionPayee;
	Tag transactionTag;
	TransactionStatus transactionStatus;
	TransactionType transactionType;
public:
	Transaction() = delete;
	Transaction(
		Account transactionAccountForAdd, Category transactionCategoryForAdd,
		CategorySub transactionCategorySubForAdd, double transactionAmountForAdd,
		Comment transactionCommentForAdd, Currency transactionCurrencyForAdd,
		CurrencyRate transactionCurrencyRateForAdd, Description transactionDescriptionForAdd,
		Payee transactionPayeeForAdd, Tag transactionTagForAdd,
		TransactionStatus transactionStatusForAdd, TransactionType transactionTypeForAdd);
	Transaction(
		Account transactionAccountForAdd, Category transactionCategoryForAdd,
		CategorySub transactionCategorySubForAdd, double transactionAmountForAdd,
		Currency transactionCurrencyForAdd);
	Account getTransactionAccount() const;
	Category getTransactionCategory() const;
	CategorySub getTransactionCategorySub() const;
	double getTransactionAmount() const;
	Comment getTransactionComment() const;
	Currency getTransactionCurrency() const;
	CurrencyRate getTransactionCurrencyRate() const;
	Description getTransactionDescription() const;
	Payee getTransactionPayee() const;
	Tag getTransactionTag() const;
	TransactionStatus getTransactionStatus() const;
	TransactionType getTransactionType() const;
	void setTransactionAccount(Account&& accountForUpdate);
	void setTransactionCategory(Category&& categoryForUpdate);
	void setTransactionCategorySub(CategorySub&& categorySubForUpdate);
	void setTransactionComment(Comment&& commentForUpdate);
	void setTransactionCurrency(Currency&& currencyForUpdate);
	void setTransactionCurrencyRate(CurrencyRate&& currencyRateForUpdate);
	void setTransactionDescription(Description&& descriptionForUpdate);
	void setTransactionPayee(Payee&& payeeForUpdate);
	void setTransactionTag(Tag&& tagForUpdate);
	void setTransactionTransactionStatus(TransactionStatus&& transactionStatusForUpdate);
	void setTransactionTransactionTyoe(TransactionType&& transactionTypeForUpdate);
	friend bool operator<(const Transaction& leftTransaction, const Transaction& rightTransaction);
	friend std::ostream& operator<<(std::ostream& outputStream, const Transaction& transaction);
};