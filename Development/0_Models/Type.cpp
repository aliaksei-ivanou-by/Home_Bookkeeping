#include "home_bookkeeping/0_Models/Type.h"

//  Constructor
//  Default (type = "Expense")
Type::Type():
  type_{ kEnumType::Expense }
{}

//  Constructor
//  With type setting
Type::Type(const kEnumType& type):
  type_{ type }
{}

//  Class member function
//  Get type
kEnumType Type::GetType() const
{
  return type_;
}

//  Class member function
//  Set type
void Type::SetType(const kEnumType& type)
{
  type_ = type;
}

//  Class member function
//  Operator == for comparing types (by type)
bool Type::operator==(const Type& type) const
{
  return type_ == type.type_;
}

//  Class member function
//  Operator != for comparing types (by type)
bool Type::operator!=(const Type& type) const
{
  return !(*this == type);
}

//  Class member function
//  Operator < for sorting transaction type (by type)
bool operator<(const Type& type_left, const Type& type_right)
{
  return type_left.type_ < type_right.type_;
}
