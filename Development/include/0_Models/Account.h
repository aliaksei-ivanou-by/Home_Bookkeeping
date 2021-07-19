#ifndef HOMEBOOKKEEPING_0MODELS_ACCOUNT_H_
#define HOMEBOOKKEEPING_0MODELS_ACCOUNT_H_

#include <iostream>
#include <string>

#include "include/0_Models/Model.h"
#include "include/0_Models/Currency.h"

class Account : public Model
{
public:
  Account();
  Account(const std::string& name);
  Account(const std::string& name, const double amount);
  Account(const std::string& name, const double amount, const Currency& currency);
  NUM GetAmount() const;
  Currency GetCurrency() const;
  void SetCurrency(Currency&& currency);
  void SetAmount(const NUM amount);
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

#endif
