#pragma once

#include "../include/stdafx.h"
#include "../include/0_Models.h"

class Transaction
{
private:
	Time transactionTime;
	Account transactionAccount;
	Category transactionCategory;
	double transactionAmount;
	Comment transactionComment;
	Currency transactionCurrency;
	Description transactionDescription;
	Payee transactionPayee;
	Tag transactionTag;
	TransactionStatus transactionStatus;
	TransactionType transactionType;
	Account transactionAccountTo;
public:
	Transaction() = delete;
	Transaction(Account transactionAccountFromForAdd, Category transactionCategoryForAdd,
		double transactionAmountForAdd,
		Comment transactionCommentForAdd, Currency transactionCurrencyForAdd,
		Description transactionDescriptionForAdd,
		Payee transactionPayeeForAdd, Tag transactionTagForAdd,
		TransactionStatus transactionStatusForAdd, TransactionType transactionTypeForAdd);
	Transaction(Account transactionAccountFromForAdd, Category transactionCategoryForAdd,
		double transactionAmountForAdd,
		Comment transactionCommentForAdd, Currency transactionCurrencyForAdd,
		Description transactionDescriptionForAdd,
		Payee transactionPayeeForAdd, Tag transactionTagForAdd,
		TransactionStatus transactionStatusForAdd, TransactionType transactionTypeForAdd,
		Account transactionAccountToForAdd);
	Transaction(
		Account transactionAccountFromForAdd, Category transactionCategoryForAdd,
		double transactionAmountForAdd,
		Currency transactionCurrencyForAdd);
	Transaction(
		Account transactionAccountFromForAdd, Category transactionCategoryForAdd,
		double transactionAmountForAdd,
		Currency transactionCurrencyForAdd, Account transactionAccountToForAdd);
	Time getTransactionTime() const;
	Account getTransactionAccount() const;
	Category getTransactionCategory() const;
	double getTransactionAmount() const;
	Comment getTransactionComment() const;
	Currency getTransactionCurrency() const;
	Description getTransactionDescription() const;
	Payee getTransactionPayee() const;
	Tag getTransactionTag() const;
	TransactionStatus getTransactionStatus() const;
	TransactionType getTransactionType() const;
	void setTransactionTime(Time&& timeForUpdate);
	void setTransactionAccount(Account&& accountForUpdate);
	void setTransactionCategory(Category&& categoryForUpdate);
	void setTransactionComment(Comment&& commentForUpdate);
	void setTransactionCurrency(Currency&& currencyForUpdate);
	void setTransactionDescription(Description&& descriptionForUpdate);
	void setTransactionPayee(Payee&& payeeForUpdate);
	void setTransactionTag(Tag&& tagForUpdate);
	void setTransactionTransactionStatus(TransactionStatus&& transactionStatusForUpdate);
	void setTransactionTransactionTyoe(TransactionType&& transactionTypeForUpdate);
	friend bool operator<(const Transaction& leftTransaction, const Transaction& rightTransaction);
	friend std::ostream& operator<<(std::ostream& outputStream, const Transaction& transaction);
};