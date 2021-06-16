#ifndef HOMEBOOKKEEPING_0MODELS_ACCOUNT_H_
#define HOMEBOOKKEEPING_0MODELS_ACCOUNT_H_

//  Class Account : public Model
//
//  Constructors:
//    Default (name = "Unspecified")
//    With name setting
//    With name setting and amount setting
//
//  Class member functions:
//    Get name
//    Get amount
//    Get currency
//    Set name
//    Set amount
//    Set currency
//    Append amount
//    Operator < for comparing models (by name (1), amount (2), currency (3))
//    Operator == for comparing models (by name, amount, currency)
//    Operator != for comparing models (by name, amount, currency)
//    Output model (name, amount -> "name (amount)")
//    Input model (name, amount -> "name, amount")
//
//  Variables:
//    name
//    amount

#include <iostream>
#include <string>

#include "home_bookkeeping/0_Models/Model.h"
#include "home_bookkeeping/0_Models/Currency.h"

class Account : public Model
{
public:
  Account();
  Account(const std::string& name);
  Account(const std::string& name, const double amount);
  Account(const std::string& name, const double amount, const Currency& currency);
  NUM GetAmount() const;
  Currency GetCurrency() const;
  void SetAmount(const double amount);
  void SetCurrency(Currency&& currency);
  void SetAmount(const NUM amount);
  void AppendAmount(const double amount);
  void AppendAmount(const NUM amount);
  friend bool operator<(const Account& model_left, const Account& model_right);
  friend bool operator==(const Account& model_left, const Account& model_right);
  friend bool operator!=(const Account& model_left, const Account& model_right);
  friend std::ostream& operator<<(std::ostream& output_stream, const Account& model);
  friend std::istream& operator>>(std::istream& input_stream, Account& model);
private:
  NUM amount_;
  Currency currency_;
};

#endif  //  HOMEBOOKKEEPING_0MODELS_ACCOUNT_H_
