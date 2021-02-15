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
	Transaction(
		const Account& transactionAccountFromForAdd,
		const Category& transactionCategoryForAdd,
		const double transactionAmountForAdd,
		const Comment& transactionCommentForAdd,
		const Currency& transactionCurrencyForAdd,
		const Description& transactionDescriptionForAdd,
		const Payee& transactionPayeeForAdd,
		const Tag& transactionTagForAdd,
		const TransactionStatus& transactionStatusForAdd,
		const TransactionType& transactionTypeForAdd);
	Transaction(
		const Account& transactionAccountFromForAdd,
		const Category& transactionCategoryForAdd,
		const double transactionAmountForAdd,
		const Comment& transactionCommentForAdd,
		const Currency& transactionCurrencyForAdd,
		const Description& transactionDescriptionForAdd,
		const Payee& transactionPayeeForAdd,
		const Tag& transactionTagForAdd,
		const TransactionStatus& transactionStatusForAdd,
		const TransactionType& transactionTypeForAdd,
		const Account& transactionAccountToForAdd);
	Transaction(
		const Account& transactionAccountFromForAdd,
		const Category& transactionCategoryForAdd,
		const double transactionAmountForAdd,
		const Currency& transactionCurrencyForAdd);
	Transaction(
		const Account& transactionAccountFromForAdd,
		const Category& transactionCategoryForAdd,
		const double transactionAmountForAdd,
		const Currency& transactionCurrencyForAdd,
		const Account& transactionAccountToForAdd);
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
	void setTransactionTime(const Time& timeForUpdate);
	void setTransactionAccount(const Account& accountForUpdate);
	void setTransactionCategory(const Category& categoryForUpdate);
	void setTransactionComment(const Comment& commentForUpdate);
	void setTransactionCurrency(const Currency& currencyForUpdate);
	void setTransactionDescription(const Description& descriptionForUpdate);
	void setTransactionPayee(const Payee& payeeForUpdate);
	void setTransactionTag(const Tag& tagForUpdate);
	void setTransactionTransactionStatus(const TransactionStatus& transactionStatusForUpdate);
	void setTransactionTransactionTyoe(const TransactionType& transactionTypeForUpdate);
	friend bool operator<(const Transaction& leftTransaction, const Transaction& rightTransaction);
	friend std::ostream& operator<<(std::ostream& outputStream, const Transaction& transaction);
};