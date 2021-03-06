#ifndef HOMEBOOKKEEPING_0MODELS_TRANSACTIONTYPE_H_
#define HOMEBOOKKEEPING_0MODELS_TRANSACTIONTYPE_H_

//  Class TransactionType
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
//    enum class TransactionTypeEnum
//    type

enum class kEnumTransactionType
{
  Income,
  Expense,
  Transfer
};

class TransactionType
{
public:
  TransactionType();
  TransactionType(const kEnumTransactionType& type);
  kEnumTransactionType GetType() const;
  void SetType(const kEnumTransactionType& type);
  bool operator==(const TransactionType& type) const;
  bool operator!=(const TransactionType& type) const;
  friend bool operator<(const TransactionType& type_left, const TransactionType& type_right);
private:
  kEnumTransactionType type_;
};
#endif  //  HOMEBOOKKEEPING_0MODELS_TRANSACTIONTYPE_H_
