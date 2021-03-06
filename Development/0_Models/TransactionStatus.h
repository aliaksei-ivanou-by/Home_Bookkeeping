#ifndef HOMEBOOKKEEPING_0MODELS_TRANSACTIONSTATUS_H_
#define HOMEBOOKKEEPING_0MODELS_TRANSACTIONSTATUS_H_

//  Class TransactionStatus
//
//  Constructors:
//    Default (status = "None")
//    With status setting
//
//  Class member functions:
//    Get status
//    Set status
//    Operator == for comparing statuses (by status)
//    Operator != for comparing statuses (by status)
//    Operator < for sorting statuses (by status)
//
//  Variables:
//    enum class TransactionStatusEnum
//    status

enum class kEnumTransactionStatus
{
  Cleared,
  Reconciled,
  Void,
  None
};

class TransactionStatus
{
public:
	TransactionStatus();
	TransactionStatus(const kEnumTransactionStatus& status);
  kEnumTransactionStatus GetStatus() const;
	void SetStatus(const kEnumTransactionStatus& status);
  bool operator==(const TransactionStatus& status) const;
  bool operator!=(const TransactionStatus& status) const;
	friend bool operator<(const TransactionStatus& status_left, const TransactionStatus& status_right);
private:
  kEnumTransactionStatus status_;
};

#endif  //  HOMEBOOKKEEPING_0MODELS_TRANSACTIONSTATUS_H_
