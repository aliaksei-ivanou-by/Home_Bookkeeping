#ifndef HOMEBOOKKEEPING_0MODELS_TRANSACTION_H_
#define HOMEBOOKKEEPING_0MODELS_TRANSACTION_H_

#include <iostream>
#include <string>

#include "include/0_Models/Account.h"
#include "include/0_Models/Category.h"
#include "include/0_Models/Comment.h"
#include "include/0_Models/Currency.h"
#include "include/0_Models/Description.h"
#include "include/0_Models/Payee.h"
#include "include/0_Models/Tag.h"
#include "include/0_Models/TimeDate.h"
#include "include/0_Models/Status.h"
#include "include/0_Models/Type.h"

class Transaction
{
public:
  Transaction() = delete;
  Transaction(
    const Account& account_from,
    const Category& category,
    const double amount,
    const Comment& comment,
    const Currency& currency,
    const Description& description,
    const Payee& payee,
    const Tag& tag,
    const Status& status,
    const Type& type);
  Transaction(
    const Account& account_from,
    const Account& account_to,
    const Category& category,
    const double amount,
    const Comment& comment,
    const Currency& currency,
    const Description& description,
    const Payee& payee,
    const Tag& tag,
    const Status& status,
    const Type& type);
  Transaction(
    const Account& account_from,
    const Category& category,
    const double amount);
  Transaction(
    const Account& account_from,
    const Account& account_to,
    const Category& category,
    const double amount);
  Transaction(const Transaction& transaction);
  TimeDate GetTime() const;
  std::string GetStringTime() const;
  Account GetAccountFrom() const;
  Account GetAccountTo() const;
  Category GetCategory() const;
  NUM GetAmount() const;
  NUM GetAmountAccountFrom() const;
  NUM GetAmountAccountTo() const;
  NUM GetAmountLastestAccountFrom() const;
  NUM GetAmountLastestAccountTo() const;
  Comment GetComment() const;
  Currency GetCurrency() const;
  Description GetDescription() const;
  Payee GetPayee() const;
  Tag GetTag() const;
  Status GetStatus() const;
  Type GetType() const;
  std::shared_ptr<Account> GetAccountFromPtr() const;
  std::shared_ptr<Account> GetAccountToPtr() const;
  std::shared_ptr<Category> GetCategoryPtr() const;
  std::shared_ptr<Comment> GetCommentPtr() const;
  std::shared_ptr<Currency> GetCurrencyPtr() const;
  std::shared_ptr<Description> GetDescriptionPtr() const;
  std::shared_ptr<Payee> GetPayeePtr() const;
  std::shared_ptr<Tag> GetTagPtr() const;
  std::shared_ptr<Status> GetStatusPtr() const;
  std::shared_ptr<Type> GetTypePtr() const;
  void SetTime(const TimeDate& time);
  void SetAccountFrom(const Account& account_from);
  void SetAccountTo(const Account& account_to);
  void SetCategory(const Category& category);
  void SetAmount(const NUM amount);
  void SetAmountLastestAccountFrom(const NUM amount);
  void SetAmountLastestAccountTo(const NUM amount);
  void SetAmountAccountFrom(const NUM amount);
  void SetAmountAccountTo(const NUM amount);
  void SetComment(const Comment& comment);
  void SetCurrency(const Currency& currency);
  void SetDescription(const Description& description);
  void SetPayee(const Payee& payee);
  void SetTag(const Tag& tag);
  void SetStatus(const Status& status);
  void SetType(const Type& type);
  void SetAccountFromPtr(std::shared_ptr<Account> account_from);
  void SetAccountToPtr(std::shared_ptr<Account> account_to);
  void SetCategoryPtr(std::shared_ptr<Category> category);
  void SetCommentPtr(std::shared_ptr<Comment> comment);
  void SetCurrencyPtr(std::shared_ptr<Currency> currency);
  void SetDescriptionPtr(std::shared_ptr<Description> description);
  void SetPayeePtr(std::shared_ptr<Payee> payee);
  void SetTagPtr(std::shared_ptr<Tag> tag);
  void SetStatusPtr(std::shared_ptr<Status> status);
  void SetTypePtr(std::shared_ptr<Type> type);
  Transaction& operator=(const Transaction& transaction);
  friend bool operator<(const Transaction& transaction_left, const Transaction& transaction_right);
  friend std::ostream& operator<<(std::ostream& output_stream, const Transaction& transaction);
private:
  TimeDate time_;
  std::shared_ptr<Account> account_from_;
  std::shared_ptr<Account> account_to_;
  std::shared_ptr<Category> category_;
  NUM amount_;
  NUM amount_account_from_;
  NUM amount_account_to_;
  std::shared_ptr<Comment> comment_;
  std::shared_ptr<Currency> currency_;
  std::shared_ptr<Description> description_;
  std::shared_ptr<Payee> payee_;
  std::shared_ptr<Tag> tag_;
  std::shared_ptr<Status> status_;
  std::shared_ptr<Type> type_;
};

#endif
