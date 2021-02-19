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
	double transactionAccountFromCurrentAmount;
	double transactionAccountToCurrentAmount;
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
	Transaction(const Transaction& transaction);
	Time getTransactionTime() const;
	Account getTransactionAccountFrom() const;
	std::shared_ptr<Account> getTransactionAccountPtrFrom() const;
	Account getTransactionAccountTo() const;
	std::shared_ptr<Account> getTransactionAccountPtrTo() const;
	Category getTransactionCategory() const;
	std::shared_ptr<Category> getTransactionCategoryPtr() const;
	double getTransactionAmount() const;
	double getTransactionAccountFromCurrentAmount() const;
	double getTransactionAccountToCurrentAmount() const;
	double getTransactionAccountFromLastAmount() const;
	double getTransactionAccountToLastAmount() const;
	Comment getTransactionComment() const;
	std::shared_ptr<Comment> getTransactionCommentPtr() const;
	Currency getTransactionCurrency() const;
	std::shared_ptr<Currency> getTransactionCurrencyPtr() const;
	Description getTransactionDescription() const;
	std::shared_ptr<Description> getTransactionDescriptionPtr() const;
	Payee getTransactionPayee() const;
	std::shared_ptr<Payee> getTransactionPayeePtr() const;
	Tag getTransactionTag() const;
	std::shared_ptr<Tag> getTransactionTagPtr() const;
	TransactionStatus getTransactionStatus() const;
	std::shared_ptr<TransactionStatus> getTransactionStatusPtr() const;
	TransactionType getTransactionType() const;
	std::shared_ptr<TransactionType> getTransactionTypePtr() const;

	void setTransactionTime(const Time& timeForUpdate);
	void setTransactionAccountFrom(const Account& accountFromForUpdate);
	void setTransactionAccountPtrFrom(std::shared_ptr<Account> accountFromForUpdate);
	void setTransactionAccountTo(const Account& accountToForUpdate);
	void setTransactionAccountPtrTo(std::shared_ptr<Account> accountFromForUpdate);
	void setTransactionCategory(const Category& categoryForUpdate);
	void setTransactionCategoryPtr(std::shared_ptr<Category> categoryForUpdate);
	void setTransactionAmount(const double amountForUpdate);
	void setTransactionAccountFromLastAmount(const double amountForUpdate);
	void setTransactionAccountToLastAmount(const double amountForUpdate);
	void setTransactionAccountFromCurrentAmount(const double amountForUpdate);
	void setTransactionAccountToCurrentAmount(const double amountForUpdate);
	void setTransactionComment(const Comment& commentForUpdate);
	void setTransactionCommentPtr(std::shared_ptr<Comment> commentForUpdate);
	void setTransactionCurrency(const Currency& currencyForUpdate);
	void setTransactionCurrencyPtr(std::shared_ptr<Currency> currencyForUpdate);
	void setTransactionDescription(const Description& descriptionForUpdate);
	void setTransactionDescriptionPtr(std::shared_ptr<Description> descriptionForUpdate);
	void setTransactionPayee(const Payee& payeeForUpdate);
	void setTransactionPayeePtr(std::shared_ptr<Payee> payeeForUpdate);
	void setTransactionTag(const Tag& tagForUpdate);
	void setTransactionTagPtr(std::shared_ptr<Tag> tagForUpdate);
	void setTransactionTransactionStatus(const TransactionStatus& transactionStatusForUpdate);
	void setTransactionTransactionStatusPtr(std::shared_ptr<TransactionStatus> transactionStatusForUpdate);
	void setTransactionTransactionType(const TransactionType& transactionTypeForUpdate);
	void setTransactionTransactionTypePtr(std::shared_ptr<TransactionType> transactionTypeForUpdate);

	friend bool operator<(const Transaction& leftTransaction, const Transaction& rightTransaction);
	friend std::ostream& operator<<(std::ostream& outputStream, const Transaction& transaction);
};