#include "include/0_Models/Type.h"

Type::Type():
  Model{ static_cast<std::string>(magic_enum::enum_name(kEnumType::Expense)) },
  type_{ kEnumType::Expense }
{}

Type::Type(const kEnumType& type):
  Model{ static_cast<std::string>(magic_enum::enum_name(type)) },
  type_{ type }
{}

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

kEnumType Type::GetType() const
{
  return type_;
}

void Type::SetType(const kEnumType& type)
{
  type_ = type;
  SetName(static_cast<std::string>(magic_enum::enum_name(type)));
}

bool operator==(const Type& type_left, const Type& type_right)
{
  return type_left.type_ == type_right.type_;
}

bool operator!=(const Type& type_left, const Type& type_right)
{
  return !(type_left == type_right);
}

bool operator<(const Type& type_left, const Type& type_right)
{
  return type_left.type_ < type_right.type_;
}

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
