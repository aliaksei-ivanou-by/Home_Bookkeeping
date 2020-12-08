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
		Account transactionAccountNew, Category transactionCategoryNew,
		CategorySub transactionCategorySubNew, double transactionAmountNew,
		Comment transactionCommentNew, Currency transactionCurrencyNew,
		CurrencyRate transactionCurrencyRateNew, Description transactionDescriptionNew,
		Payee transactionPayeeNew, Tag transactionTagNew,
		TransactionStatus transactionStatusNew, TransactionType transactionTypeNew);
	Transaction(
		Account transactionAccountNew, Category transactionCategoryNew,
		CategorySub transactionCategorySubNew, double transactionAmountNew,
		Currency transactionCurrencyNew);
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
	void setTransactionAccount(Account&& accountNew);
	void setTransactionCategory(Category&& categoryNew);
	void setTransactionCategorySub(CategorySub&& categorySubNew);
	void setTransactionComment(Comment&& commentNew);
	void setTransactionCurrency(Currency&& currencyNew);
	void setTransactionCurrencyRate(CurrencyRate&& currencyRateNew);
	void setTransactionDescription(Description&& descriptionNew);
	void setTransactionPayee(Payee&& payeeNew);
	void setTransactionTag(Tag&& tagNew);
	void setTransactionTransactionStatus(TransactionStatus&& transactionStatusNew);
	void setTransactionTransactionTyoe(TransactionType&& transactionTypeNew);
	friend bool operator<(const Transaction& leftTransaction, const Transaction& rightTransaction);
	friend std::ostream& operator<<(std::ostream& outputStream, const Transaction& transaction);
};