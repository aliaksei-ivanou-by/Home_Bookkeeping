#ifndef HOMEBOOKKEEPING_0MODELS_TYPE_H_
#define HOMEBOOKKEEPING_0MODELS_TYPE_H_

//  Class Type : public Model
//
//  Constructors:
//    Default (type = "Expense", name = "Expense")
//    With type setting
//
//  Class member functions:
//    Get name
//    Set name
//    Get type
//    Set type
//    Operator < for comparing types (by type)
//    Operator == for comparing types (by type)
//    Operator != for comparing types (by type)
//    Output model (name)
//    Input model (name)
//
//  Variables:
//    name
//    enum class kEnumType
//    type

#include "lib/enum/magic_enum.hpp"

#include "include/0_Models/Model.h"

enum class kEnumType
{
  Income,
  Expense,
  Transfer
};

class Type : public Model
{
public:
  Type();
  Type(const kEnumType& type);
  void SetName(const std::string& name) override;
  kEnumType GetType() const;
  void SetType(const kEnumType& type);
  friend bool operator<(const Type& type_left, const Type& type_right);
  friend bool operator==(const Type& type_left, const Type& type_right);
  friend bool operator!=(const Type& type_left, const Type& type_right);
  friend std::istream& operator>>(std::istream& input_stream, Type& model);
private:
  kEnumType type_;
};
#endif  //  HOMEBOOKKEEPING_0MODELS_TYPE_H_
