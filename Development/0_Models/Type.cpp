#include "home_bookkeeping/0_Models/Type.h"

//  Constructor
//  Default (type = "Expense")
Type::Type():
  Model{ static_cast<std::string>(magic_enum::enum_name(kEnumType::Expense)) },
  type_{ kEnumType::Expense }
{}

//  Constructor
//  With type setting
Type::Type(const kEnumType& type):
  Model{ static_cast<std::string>(magic_enum::enum_name(type)) },
  type_{ type }
{}

//  Class member function
//  Set name
void Type::SetName(const std::string& name)
{
  auto name_new = magic_enum::enum_cast<kEnumType>(name);
  if (name_new.has_value())
  {
    SetType(name_new.value());
    Model::SetName(name);
    PLOG_INFO << "Set new type";
  }
}

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
  SetName(static_cast<std::string>(magic_enum::enum_name(type)));
}

//  Class member function
//  Operator == for comparing types (by type)
bool operator==(const Type& type_left, const Type& type_right)
{
  return type_left.type_ == type_right.type_;
}

//  Class member function
//  Operator != for comparing types (by type)
bool operator!=(const Type& type_left, const Type& type_right)
{
  return !(type_left == type_right);
}

//  Friend class member function
//  Operator < for sorting transaction type (by type)
bool operator<(const Type& type_left, const Type& type_right)
{
  return type_left.type_ < type_right.type_;
}

//  Friend class member function
//  Input model (name)
std::istream& operator>>(std::istream& input_stream, Type& model)
{
  if (!input_stream)
  {
    return input_stream;
  }
  std::string name;
  getline(input_stream, name);
  if (!input_stream)
  {
    return input_stream;
  }
  model.SetName(name);
  return input_stream;
}
