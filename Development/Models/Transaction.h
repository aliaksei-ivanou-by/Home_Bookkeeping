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
	Account account;
	Category category;
	CategorySub category_sub;
	double amount;
	Comment comment;
	Currency currency;
	CurrencyRate currency_rate;
	Description description;
	Payee payee;
	Tag tag;
	TransactionStatus transaction_status;
	TransactionType transaction_type;
public:
	Transaction() = delete;
	Transaction(Account acc, Category cat, CategorySub cat_sub, 
		double am, Comment com, Currency cur, 
		CurrencyRate cur_rate, Description desc, Payee payee, 
		Tag tag, TransactionStatus tr_st, TransactionType tr_t)
		: account{ acc },
		category{ cat },
		category_sub{ cat_sub },
		amount{ am },
		comment{ com },
		currency{ cur },
		currency_rate{ cur_rate },
		description{ desc },
		payee{ payee },
		tag{ tag },
		transaction_status{ tr_st },
		transaction_type{ tr_t }
	{}
	Account get_account() const
	{
		return this->account;
	}
	Category get_category() const
	{
		return this->category;
	}
	CategorySub get_category_sub() const
	{
		return this->category_sub;
	}
	Comment get_comment() const
	{
		return this->comment;
	}
	Currency get_currency() const
	{
		return this->currency;
	}
	CurrencyRate get_currency_rate() const
	{
		return this->currency_rate;
	}
	Description get_description() const
	{
		return this->description;
	}
	Payee get_payee() const
	{
		return this->payee;
	}
	Tag get_tag() const
	{
		return this->tag;
	}
	TransactionStatus get_transaction_status() const
	{
		return this->transaction_status;
	}
	TransactionType get_transaction_type() const
	{
		return this->transaction_type;
	}
	void set_account(Account acc)
	{
		this->account = acc;
	}
	void set_category(Category cat)
	{
		this->category = cat;
	}
	void set_category_sub(CategorySub cat_sub)
	{
		this->category_sub = cat_sub;
	}
	void set_comment(Comment com)
	{
		this->comment = com;
	}
	void set_currency(Currency cur)
	{
		this->currency = cur;
	}
	void set_currency_rate(CurrencyRate cur_rate)
	{
		this->currency_rate = cur_rate;
	}
	void set_description(Description desc)
	{
		this->description = desc;
	}
	void set_payee(Payee payee)
	{
		this->payee = payee;
	}
	void set_tag(Tag tag)
	{
		this->tag = tag;
	}
	void set_transaction_status(TransactionStatus tr_st)
	{
		this->transaction_status = tr_st;
	}
	void set_transaction_type(TransactionType tr_t)
	{
		this->transaction_type = tr_t;
	}
};

bool operator<(const Transaction& lhs, const Transaction& rhs)
{
	return (lhs.get_account() < rhs.get_account()); // change to get_datetime();
}

std::ostream& operator<<(std::ostream& os, const Tag& i)
{
	return os << i.get_name();
}

#endif