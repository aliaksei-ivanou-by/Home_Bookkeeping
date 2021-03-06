#include "TransactionStatus.h"

//  Constructor
//  Default (status = "None")
TransactionStatus::TransactionStatus():
  status_{ kEnumTransactionStatus::None }
{}

//  Constructor
//  With status setting
TransactionStatus::TransactionStatus(const kEnumTransactionStatus& status):
  status_{ status }
{}

//  Class member function
//  Get status
kEnumTransactionStatus TransactionStatus::GetStatus() const
{
  return status_;
}

//  Class member function
//  Set status
void TransactionStatus::SetStatus(const kEnumTransactionStatus& status)
{
  status_ = status;
}

//  Class member function
//  Operator == for comparing statuses (by status)
bool TransactionStatus::operator==(const TransactionStatus& status) const
{
  return status_ == status.status_;
}

//  Class member function
//  Operator != for comparing statuses (by status)
bool TransactionStatus::operator!=(const TransactionStatus& status) const
{
  return !(*this == status);
}

//  Class member function
//  Operator < for sorting statuses (by status)
bool operator<(const TransactionStatus& status_left, const TransactionStatus& status_right)
{
  return status_left.status_ < status_right.status_;
}
