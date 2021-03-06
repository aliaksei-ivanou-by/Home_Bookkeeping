#include "TransactionType.h"

//  Constructor
//  Default (type = "Expense")
TransactionType::TransactionType():
  type_{ kEnumTransactionType::Expense }
{}

//  Constructor
//  With type setting
TransactionType::TransactionType(const kEnumTransactionType& type):
  type_{ type }
{}

//  Class member function
//  Get type
kEnumTransactionType TransactionType::GetType() const
{
  return type_;
}

//  Class member function
//  Set type
void TransactionType::SetType(const kEnumTransactionType& type)
{
  type_ = type;
}

//  Class member function
//  Operator == for comparing types (by type)
bool TransactionType::operator==(const TransactionType& type) const
{
  return type_ == type.type_;
}

//  Class member function
//  Operator != for comparing types (by type)
bool TransactionType::operator!=(const TransactionType& type) const
{
  return !(*this == type);
}

//  Class member function
//  Operator < for sorting transaction type (by type)
bool operator<(const TransactionType& type_left, const TransactionType& type_right)
{
  return type_left.type_ < type_right.type_;
}
