#ifndef HOMEBOOKKEEPING_0MODELS_TYPE_H_
#define HOMEBOOKKEEPING_0MODELS_TYPE_H_

//  Class Type
//
//  Constructors:
//    Default (type = "Expense", name = "Expense")
//    With type setting
//
//  Class member functions:
//    Get type
//    Set type
//    Operator == for comparing types (by type)
//    Operator != for comparing types (by type)
//    Operator < for sorting types (by type)
//
//  Variables:
//    name
//    enum class kEnumType
//    type

#include "home_bookkeeping/0_Models/Model.h"
#include "home_bookkeeping/include/magic_enum.hpp"

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
  Type(std::string name) = delete;
  Type(const kEnumType& type);
  void SetName(std::string name);
  kEnumType GetType() const;
  void SetType(const kEnumType& type);
  bool operator==(const Type& type) const;
  bool operator!=(const Type& type) const;
  friend bool operator<(const Type& type_left, const Type& type_right);
private:
  kEnumType type_;
};
#endif  //  HOMEBOOKKEEPING_0MODELS_TYPE_H_
