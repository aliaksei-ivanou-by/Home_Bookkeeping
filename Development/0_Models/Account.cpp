#include "home_bookkeeping/0_Models/Account.h"

//  Constructor
//  Default (name = "")
Account::Account():
  Model{ "" },
  amount_{ 0 }
{}

//  Constructor
//  With name setting
Account::Account(const std::string& name):
  Model{ name },
  amount_{ 0 }
{}

//  Constructor
//  With name setting and amount setting
Account::Account(const std::string& name, double amount):
  Model{ name },
  amount_{ amount }
{}

//  Class member function
//  Get amount
double Account::GetAmount() const
{
  return amount_;
}

//  Class member function
//  Set amount
void Account::SetAmount(const double amount)
{
  amount_ = amount;
}

//  Class member function
//  Update amount
void Account::AppendAmount(const double amount)
{
  amount_ += amount;
}

//  Friend class member function
//  Operator < for sorting models (by name (1), amount (2))
bool operator<(const Account& model_left, const Account& model_right)
{
  if (model_left.GetName() < model_right.GetName())
  {
    return true;
  }
  else
  {
    if (model_left.GetName() > model_right.GetName())
    {
      return false;
    }
    else
    {
      if (model_left.amount_ < model_right.amount_)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }
}

//  Friend class member function
//  Output model (name, amount -> "name (amount)")
std::ostream& operator<<(std::ostream& outputStream, const Account& model)
{
  return outputStream << model.GetName() << " (" << model.amount_ << ")";
}

//  Friend class member function
//  Input model (name, amount -> "name, amount")
std::istream& operator>>(std::istream& input_stream, Account& model)
{
  if (!input_stream)
  {
    return input_stream;
  }
  std::string name;
  while (true)
  {
    char ch;
    input_stream.get(ch);
    if (!input_stream)
    {
      return input_stream;
    }
    if (ch == ',')
    {
      break;
    }
    name += ch;
  }
  model.SetName(name);
  double amount;
  input_stream >> amount;
  if (!input_stream)
  {
    return input_stream;
  }
  model.amount_ = amount;
  return input_stream;
}
