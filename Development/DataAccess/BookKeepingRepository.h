#pragma once

#ifndef BOOKKEEPINGREPOSITORY_H
#define BOOKKEEPINGREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef MODELS_H
#include "../include/Models.h"
#endif

#ifndef DATAACCESS1_H
#include "../include/DataAccess1.h"
#endif

#ifndef DATAACCESS2_H
#include "../include/DataAccess2.h"
#endif

class BookKeepingRepository
{
private:
	TransactionRepository transactions;
	CategoryRepository categories;
	CategorySubRepository categories_sub;
	CommentRepository comments;
	PayeeRepository payees;
	AccountRepository accounts;
	CurrencyRepository currencies;
	CurrencyRateRepository currencies_rate;
	DescriptionRepository descriptions;
	TagRepository tags;
public:
	BookKeepingRepository()
	{
		TransactionRepository();
		CategoryRepository();
		CategorySubRepository();
		CommentRepository();
		PayeeRepository();
		AccountRepository();
		CurrencyRepository();
		CurrencyRateRepository();
		DescriptionRepository();
		TagRepository();
	}
	void add_transaction(Transaction& i)
	{
		this->transactions.add(i);
	}
	TransactionRepository get_transactions() const
	{
		return this->transactions;
	}
	CategoryRepository get_categories() const
	{
		return this->categories;
	}
	CategorySubRepository get_categories_sub() const
	{
		return this->categories_sub;
	}
	CommentRepository get_comments() const
	{
		return this->comments;
	}
	PayeeRepository get_payees() const
	{
		return this->payees;
	}
	AccountRepository get_accounts() const
	{
		return this->accounts;
	}
	CurrencyRepository get_currencies() const
	{
		return this->currencies;
	}
	CurrencyRateRepository get_currencies_rate() const
	{
		return this->currencies_rate;
	}
	DescriptionRepository get_descriptions() const
	{
		return this->descriptions;
	}
	TagRepository get_tags() const
	{
		return this->tags;
	}
	void add_category(Category cat)
	{
		this->categories.add(cat);
	}
	void add_category_sub(CategorySub cat_sub)
	{
		this->categories_sub.add(cat_sub);
	}
	void add_currency(Currency cur)
	{
		this->currencies.add(cur);
	}
	void add_payee(Payee payee)
	{
		this->payees.add(payee);
	}
	void add_tag(Tag tag)
	{
		this->tags.add(tag);
	}
	void add_comment(Comment com)
	{
		this->comments.add(com);
	}
	void add_description(Description desc)
	{
		this->descriptions.add(desc);
	}
	void add_account(Account acc)
	{
		this->accounts.add(acc);
	}
};

#endif