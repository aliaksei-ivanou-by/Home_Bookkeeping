#ifndef HOMEBOOKKEEPING_0MODELS_TRANSACTION_H_
#define HOMEBOOKKEEPING_0MODELS_TRANSACTION_H_

/*
Class Transaction
Includes time, account from, account to, category, amount, current amount for account from, 
current amount for account to, comment, currency, desctiption, payee, tag, transaction status, transaction type.

Constructors:
	With the setting of the account from, category, amount, comment, currency, 
		description, payee, tag, transaction status, transaction type (income or expense)
	With the setting of the account from, account to, category, amount, comment, 
		currency, description, payee, tag, transaction status, transaction type (transfer)
	With the setting of the account from, category, amount (income or expense)
	With the setting of the account from, account to, category, amount (transfer)
	Copy

Class member functions:
	Get the time of the transaction
	Get the account from of the transaction
	Get the account to of the transaction
	Get the category of the transaction
	Get the amount of the transaction
	Get the current amount of the account from of the transaction
	Get the current amount of the account to of the transaction
	Get the lastest amount of the account from of the transaction
	Get the lastest amount of the account to of the transaction
	Get the comment of the transaction
	Get the currency of the transaction
	Get the description of the transaction
	Get the payee of the transaction
	Get the tag of the transaction
	Get the transaction status of the transaction
	Get the transaction type of the transaction
	Get the shared pointer to the account from of the transaction
	Get the shared pointer to the account to of the transaction
	Get the shared pointer to the category of the transaction
	Get the shared pointer to the comment of the transaction
	Get the shared pointer to the currency of the transaction
	Get the shared pointer to the description of the transaction
	Get the shared pointer to the payee of the transaction
	Get the shared pointer to the tag of the transaction
	Get the shared pointer to the transaction status of the transaction
	Get the shared pointer to the transaction type of the transaction
	Set the time of the transaction
	Set the account from of the transaction
	Set the account to of the transaction
	Set the category of the transaction
	Set the amount of the transaction
	Set the current amount of the account from of the transaction
	Set the current amount of the account to of the transaction
	Set the lastest amount of the account from of the transaction
	Set the lastest amount of the account to of the transaction
	Set the comment of the transaction
	Set the currency of the transaction
	Set the description of the transaction
	Set the payee of the transaction
	Set the tag of the transaction
	Set the transaction status of the transaction
	Set the transaction type of the transaction
	Set the shared pointer to the account from of the transaction
	Set the shared pointer to the account to of the transaction
	Set the shared pointer to the category of the transaction
	Set the shared pointer to the comment of the transaction
	Set the shared pointer to the currency of the transaction
	Set the shared pointer to the description of the transaction
	Set the shared pointer to the payee of the transaction
	Set the shared pointer to the tag of the transaction
	Set the shared pointer to the transaction status of the transaction
	Set the shared pointer to the transaction type of the transaction
	Copy assignment operator
	Operator < for sorting transactions
	Print transaction
*/

#include <iostream>
#include <string>

#include "home_bookkeeping/0_Models/Account.h"
#include "home_bookkeeping/0_Models/Category.h"
#include "home_bookkeeping/0_Models/Comment.h"
#include "home_bookkeeping/0_Models/Currency.h"
#include "home_bookkeeping/0_Models/Description.h"
#include "home_bookkeeping/0_Models/Payee.h"
#include "home_bookkeeping/0_Models/Tag.h"
#include "home_bookkeeping/0_Models/Time.h"
#include "home_bookkeeping/0_Models/TransactionStatus.h"
#include "home_bookkeeping/0_Models/TransactionType.h"

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
		const Account& transactionAccountToForAdd,
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
		const double transactionAmountForAdd);
	Transaction(
		const Account& transactionAccountFromForAdd,
		const Account& transactionAccountToForAdd,
		const Category& transactionCategoryForAdd,
		const double transactionAmountForAdd);

	Transaction(const Transaction& transaction);

	Time getTransactionTime() const;
	Account getTransactionAccountFrom() const;
	Account getTransactionAccountTo() const;
	Category getTransactionCategory() const;
	double getTransactionAmount() const;
	double getTransactionAccountFromCurrentAmount() const;
	double getTransactionAccountToCurrentAmount() const;
	double getTransactionAccountFromLastAmount() const;
	double getTransactionAccountToLastAmount() const;
	Comment getTransactionComment() const;
	Currency getTransactionCurrency() const;
	Description getTransactionDescription() const;
	Payee getTransactionPayee() const;
	Tag getTransactionTag() const;
	TransactionStatus getTransactionStatus() const;
	TransactionType getTransactionType() const;

	std::shared_ptr<Account> getTransactionAccountPtrFrom() const;
	std::shared_ptr<Account> getTransactionAccountPtrTo() const;
	std::shared_ptr<Category> getTransactionCategoryPtr() const;
	std::shared_ptr<Comment> getTransactionCommentPtr() const;
	std::shared_ptr<Currency> getTransactionCurrencyPtr() const;
	std::shared_ptr<Description> getTransactionDescriptionPtr() const;
	std::shared_ptr<Payee> getTransactionPayeePtr() const;
	std::shared_ptr<Tag> getTransactionTagPtr() const;
	std::shared_ptr<TransactionStatus> getTransactionStatusPtr() const;
	std::shared_ptr<TransactionType> getTransactionTypePtr() const;

	void setTransactionTime(const Time& timeForUpdate);
	void setTransactionAccountFrom(const Account& accountFromForUpdate);
	void setTransactionAccountTo(const Account& accountToForUpdate);
	void setTransactionCategory(const Category& categoryForUpdate);
	void setTransactionAmount(const double amountForUpdate);
	void setTransactionAccountFromLastAmount(const double amountForUpdate);
	void setTransactionAccountToLastAmount(const double amountForUpdate);
	void setTransactionAccountFromCurrentAmount(const double amountForUpdate);
	void setTransactionAccountToCurrentAmount(const double amountForUpdate);
	void setTransactionComment(const Comment& commentForUpdate);
	void setTransactionCurrency(const Currency& currencyForUpdate);
	void setTransactionDescription(const Description& descriptionForUpdate);
	void setTransactionPayee(const Payee& payeeForUpdate);
	void setTransactionTag(const Tag& tagForUpdate);
	void setTransactionTransactionStatus(const TransactionStatus& transactionStatusForUpdate);
	void setTransactionTransactionType(const TransactionType& transactionTypeForUpdate);

	void setTransactionAccountPtrFrom(std::shared_ptr<Account> accountFromForUpdate);
	void setTransactionAccountPtrTo(std::shared_ptr<Account> accountFromForUpdate);
	void setTransactionCategoryPtr(std::shared_ptr<Category> categoryForUpdate);
	void setTransactionCommentPtr(std::shared_ptr<Comment> commentForUpdate);
	void setTransactionCurrencyPtr(std::shared_ptr<Currency> currencyForUpdate);
	void setTransactionDescriptionPtr(std::shared_ptr<Description> descriptionForUpdate);
	void setTransactionPayeePtr(std::shared_ptr<Payee> payeeForUpdate);
	void setTransactionTagPtr(std::shared_ptr<Tag> tagForUpdate);
	void setTransactionTransactionStatusPtr(std::shared_ptr<TransactionStatus> transactionStatusForUpdate);
	void setTransactionTransactionTypePtr(std::shared_ptr<TransactionType> transactionTypeForUpdate);

	Transaction& operator=(const Transaction& transaction);
	friend bool operator<(const Transaction& leftTransaction, const Transaction& rightTransaction);
	friend std::ostream& operator<<(std::ostream& outputStream, const Transaction& transaction);
};

#endif  //  HOMEBOOKKEEPING_0MODELS_TRANSACTION_H_
