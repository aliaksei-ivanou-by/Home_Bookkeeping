#ifndef HOMEBOOKKEEPING_0MODELS_ACCOUNT_H_
#define HOMEBOOKKEEPING_0MODELS_ACCOUNT_H_

//  Class Account : public Model
//
//  Constructors:
//    Default (name = "")
//    With name setting
//    With name setting and amount setting
//
//  Class member functions:
//    Get name
//    Get amount
//    Set name
//    Set amount
//    Update amount
//    Operator < for sorting models (by name (1), amount (2))
//    Output model (name, amount -> "name (amount)")
//    Input model (name, amount -> "name, amount")
//
//  Variables:
//    name
//    amount

#include <iostream>
#include <string>

#include "home_bookkeeping/0_Models/Model.h"

class Account : public Model
{
public:
  Account();
  Account(const std::string& name);
  Account(const std::string& name, double amount);
  double GetAmount() const;
  void SetAmount(const double amount);
  void AppendAmount(const double amount);
  friend bool operator<(const Account& model_left, const Account& model_right);
  friend std::ostream& operator<<(std::ostream& output_stream, const Account& model);
  friend std::istream& operator>>(std::istream& input_stream, Account& model);
private:
  double amount_;
};

#endif  //  HOMEBOOKKEEPING_0MODELS_ACCOUNT_H_
