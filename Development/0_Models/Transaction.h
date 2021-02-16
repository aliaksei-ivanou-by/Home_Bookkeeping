#pragma once

#include "../include/stdafx.h"
#include "../include/0_Models.h"

class Transaction
{
private:
	Time transactionTime;
	std::shared_ptr<Account> transactionAccountFrom;
	std::shared_ptr<Account> transactionAccountTo;
	std::shared_ptr<Category> transactionCategory;
	double transactionAmount;
	std::shared_ptr<Comment> transactionComment;
	std::shared_ptr<Currency> transactionCurrency;
	std::shared_ptr<Description> transactionDescription;
	std::shared_ptr<Payee> transactionPayee;
	std::shared_ptr<Tag> transactionTag;
	std::shared_ptr<TransactionStatus> transactionStatus;
	std::shared_ptr<TransactionType> transactionType;
public:
	Transaction() = delete;
	Transaction( // Income or Expense
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
	Transaction( // Income or Expense
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
	Transaction( // Income or Expense
		const Account& transactionAccountFromForAdd,
		const Category& transactionCategoryForAdd,
		const double transactionAmountForAdd,
		const Currency& transactionCurrencyForAdd);
	Transaction( // Transfer
		const Account& transactionAccountFromForAdd,
		const Account& transactionAccountToForAdd,
		const Category& transactionCategoryForAdd,
		const double transactionAmountForAdd,
		const Currency& transactionCurrencyForAdd);
	Time getTransactionTime() const;
	Account getTransactionAccountFrom() const;
	Account getTransactionAccountTo() const;
	Category getTransactionCategory() const;
	double getTransactionAmount() const;
	double getTransactionAccountAmount() const;
	Comment getTransactionComment() const;
	Currency getTransactionCurrency() const;
	Description getTransactionDescription() const;
	Payee getTransactionPayee() const;
	Tag getTransactionTag() const;
	TransactionStatus getTransactionStatus() const;
	TransactionType getTransactionType() const;
	void setTransactionTime(const Time& timeForUpdate);
	void setTransactionAccountFrom(const Account& accountFromForUpdate);
	void setTransactionAccountTo(const Account& accountToForUpdate);
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