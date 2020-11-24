#pragma once

#ifndef TRANSACTION_H
#define TRANSACTION_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef MODELS_H
#include "../include/Models.h"
#endif

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
	Transaction(Account account, Category category, CategorySub categorySub, 
		double amount, Comment comment, Currency currency, 
		CurrencyRate currencyRate, Description description, Payee payee, 
		Tag tag, TransactionStatus transactionStatus, TransactionType transactionType)
		: transactionAccount{ account },
		transactionCategory{ category },
		transactionCategorySub{ categorySub },
		transactionAmount{ amount },
		transactionComment{ comment },
		transactionCurrency{ currency },
		transactionCurrencyRate{ currencyRate },
		transactionDescription{ description },
		transactionPayee{ payee },
		transactionTag{ tag },
		transactionStatus{ transactionStatus },
		transactionType{ transactionType }
	{}
	Transaction(Account account, Category category, CategorySub categorySub,
		double amount, Currency currency)
		: transactionAccount{ account },
		transactionCategory{ category },
		transactionCategorySub{ categorySub },
		transactionAmount{ amount },
		transactionComment{ },
		transactionCurrency{ currency },
		transactionCurrencyRate{ },
		transactionDescription{ },
		transactionPayee{ },
		transactionTag{ },
		transactionStatus{ },
		transactionType{ }
	{}
	Account getTransactionAccount() const
	{
		return this->transactionAccount;
	}
	Category getTransactionCategory() const
	{
		return this->transactionCategory;
	}
	CategorySub getTransactionCategorySub() const
	{
		return this->transactionCategorySub;
	}
	double getTransactionAmount() const
	{
		return this->transactionAmount;
	}
	Comment getTransactionComment() const
	{
		return this->transactionComment;
	}
	Currency getTransactionCurrency() const
	{
		return this->transactionCurrency;
	}
	CurrencyRate getTransactionCurrencyRate() const
	{
		return this->transactionCurrencyRate;
	}
	Description getTransactionDescription() const
	{
		return this->transactionDescription;
	}
	Payee getTransactionPayee() const
	{
		return this->transactionPayee;
	}
	Tag getTransactionTag() const
	{
		return this->transactionTag;
	}
	TransactionStatus getTransactionStatus() const
	{
		return this->transactionStatus;
	}
	TransactionType getTransactionType() const
	{
		return this->transactionType;
	}
	void setTransactionAccount(Account account)
	{
		this->transactionAccount = account;
	}
	void setTransactionCategory(Category category)
	{
		this->transactionCategory = category;
	}
	void setTransactionCategorySub(CategorySub categorySub)
	{
		this->transactionCategorySub = categorySub;
	}
	void setTransactionComment(Comment comment)
	{
		this->transactionComment = comment;
	}
	void setTransactionCurrency(Currency currency)
	{
		this->transactionCurrency = currency;
	}
	void setTransactionCurrencyRate(CurrencyRate currencyRate)
	{
		this->transactionCurrencyRate = currencyRate;
	}
	void setTransactionDescription(Description description)
	{
		this->transactionDescription = description;
	}
	void setTransactionPayee(Payee payee)
	{
		this->transactionPayee = payee;
	}
	void setTransactionTag(Tag tag)
	{
		this->transactionTag = tag;
	}
	void setTransactionTransactionStatus(TransactionStatus transactionStatus)
	{
		this->transactionStatus = transactionStatus;
	}
	void setTransactionTransactionTyoe(TransactionType transactionType)
	{
		this->transactionType = transactionType;
	}
	friend bool operator<(const Transaction& leftTransaction, const Transaction& rightTransaction)
	{
		return (leftTransaction.getTransactionAccount() < rightTransaction.getTransactionAccount());
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const Transaction& transaction)
	{
		return outputStream << transaction.getTransactionAccount() << '\t' <<
								transaction.getTransactionCategory() << '\t' <<
								transaction.getTransactionCategorySub() << '\t' <<
								transaction.getTransactionAmount() << ' ' <<
								transaction.getTransactionCurrency().getCurrencyName();
	}
};

#endif