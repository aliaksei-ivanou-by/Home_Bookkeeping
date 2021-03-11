#ifndef HOMEBOOKKEEPING_0MODELS_TRANSACTION_H_
#define HOMEBOOKKEEPING_0MODELS_TRANSACTION_H_

//  Class Transaction
//
//  Constructors:
//    With account from setting, category setting, amount setting, comment setting, currency setting, 
//      description setting, payee setting, tag setting,
//      transaction status setting, transaction type setting
//      (income / expense)
//    With account from setting, account to setting, category setting, amount setting, comment setting, 
//      currency setting, description setting, payee setting, tag setting,
//      transaction status setting, transaction type setting
//      (transfer)
//    With account from setting, category setting, amount setting
//      (income / expense)
//    With account from setting, account to setting, category setting, amount setting
//      (transfer)
//    Copy
//
//  Class member functions:
//    Get time
//    Get account from
//    Get account to
//    Get category
//    Get amount
//    Get amount of the account from
//    Get amount of the account to
//    Get lastest amount of the account from
//    Get lastest amount of the account to
//    Get comment
//    Get currency
//    Get description
//    Get payee
//    Get tag
//    Get transaction status
//    Get transaction type
//    Get account from (shared pointer)
//    Get account to (shared pointer)
//    Get category (shared pointer)
//    Get comment (shared pointer)
//    Get currency (shared pointer)
//    Get description (shared pointer)
//    Get payee (shared pointer)
//    Get tag (shared pointer)
//    Get status (shared pointer)
//    Get type (shared pointer)
//    Set time
//    Set account from
//    Set account to
//    Set category
//    Set amount
//    Set amount of the account from
//    Set amount of the account to
//    Set lastest amount of the account from
//    Set lastest amount of the account to
//    Set comment
//    Set currency
//    Set description
//    Set payee
//    Set tag
//    Set status
//    Set type
//    Set account from (shared pointer)
//    Set account to (shared pointer)
//    Set category (shared pointer)
//    Set comment (shared pointer)
//    Set currency (shared pointer)
//    Set description (shared pointer)
//    Set payee (shared pointer)
//    Set tag (shared pointer)
//    Set status (shared pointer)
//    Set type (shared pointer)
//    Copy assignment operator
//    Operator < for sorting models (by time)
//    Output model (time \t account from \t category \t amount \t currency)
//
//  Variables:
//    time
//    account from (shared pointer)
//    account to (shared pointer)
//    category (shared pointer)
//    amount
//    amount for account from
//    amount for account to
//    comment (shared pointer)
//    currency (shared pointer)
//    desctiption (shared pointer)
//    payee, tag (shared pointer)
//    transaction status (shared pointer)
//    transaction type (shared pointer)

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
#include "home_bookkeeping/0_Models/Status.h"
#include "home_bookkeeping/0_Models/Type.h"

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
  Time GetTime() const;
  Account GetAccountFrom() const;
  Account GetAccountTo() const;
  Category GetCategory() const;
  double GetAmount() const;
  double GetAmountAccountFrom() const;
  double GetAmountAccountTo() const;
  double GetAmountLastestAccountFrom() const;
  double GetAmountLastestAccountTo() const;
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
  void SetTime(const Time& time);
  void SetAccountFrom(const Account& account_from);
  void SetAccountTo(const Account& account_to);
  void SetCategory(const Category& category);
  void SetAmount(const double amount);
  void SetAmountLastestAccountFrom(const double amount);
  void SetAmountLastestAccountTo(const double amount);
  void SetAmountAccountFrom(const double amount);
  void SetAmountAccountTo(const double amount);
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
  Time time_;
  std::shared_ptr<Account> account_from_;
  std::shared_ptr<Account> account_to_;
  std::shared_ptr<Category> category_;
  double amount_;
  double amount_account_from_;
  double amount_account_to_;
  std::shared_ptr<Comment> comment_;
  std::shared_ptr<Currency> currency_;
  std::shared_ptr<Description> description_;
  std::shared_ptr<Payee> payee_;
  std::shared_ptr<Tag> tag_;
  std::shared_ptr<Status> status_;
  std::shared_ptr<Type> type_;
};

#endif  //  HOMEBOOKKEEPING_0MODELS_TRANSACTION_H_
