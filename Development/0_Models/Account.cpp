#include "home_bookkeeping/0_Models/Account.h"

//  Constructor
//  Default (name = "Unspecified")
Account::Account():
  Model{ },
  amount_{ NUM(0.0) }
{}

//  Constructor
//  With name setting
Account::Account(const std::string& name):
  Model{ name },
  amount_{ NUM(0.0) },
  currency_{ Currency() }
{}

//  Constructor
//  With name setting and amount setting
Account::Account(const std::string& name, double amount):
  Model{ name },
  amount_{ NUM(amount) },
  currency_{ Currency() }
{}

//  Constructor
//  With name setting, amount setting, currency setting
Account::Account(const std::string& name, double amount, Currency currency) :
  Model{ name },
  amount_{ NUM(amount) },
  currency_{ currency }
{}

//  Class member function
//  Get amount
NUM Account::GetAmount() const
{
  return amount_;
}

//  Class member function
//  Set amount
void Account::SetAmount(const double amount)
{
  amount_ = NUM(amount);
  PLOG_INFO << "Set new amount";
}

//  Class member function
//  Set amount
void Account::SetAmount(const NUM amount)
{
  amount_ = amount;
  PLOG_INFO << "Set new amount";
}

//  Class member function
//  Append amount
void Account::AppendAmount(const double amount)
{
  amount_ += NUM(amount);
  PLOG_INFO << "Append amount";
}

//  Class member function
//  Append amount
void Account::AppendAmount(const NUM amount)
{
  amount_ += amount;
  PLOG_INFO << "Append amount";
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
      return model_left.amount_ < model_right.amount_;
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
