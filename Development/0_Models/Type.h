#ifndef HOMEBOOKKEEPING_0MODELS_TYPE_H_
#define HOMEBOOKKEEPING_0MODELS_TYPE_H_

//  Class Type
//
//  Constructors:
//    Default (type = "Expense")
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
//    enum class kEnumType
//    type

enum class kEnumType
{
  Income,
  Expense,
  Transfer
};

class Type
{
public:
  Type();
  Type(const kEnumType& type);
  kEnumType GetType() const;
  void SetType(const kEnumType& type);
  bool operator==(const Type& type) const;
  bool operator!=(const Type& type) const;
  friend bool operator<(const Type& type_left, const Type& type_right);
private:
  kEnumType type_;
};
#endif  //  HOMEBOOKKEEPING_0MODELS_TYPE_H_
