#include "home_bookkeeping/0_Models/Status.h"

//  Constructor
//  Default (status = "None")
Status::Status():
  status_{ kEnumStatus::None }
{}

//  Constructor
//  With status setting
Status::Status(const kEnumStatus& status):
  status_{ status }
{}

//  Class member function
//  Get status
kEnumStatus Status::GetStatus() const
{
  return status_;
}

//  Class member function
//  Set status
void Status::SetStatus(const kEnumStatus& status)
{
  status_ = status;
}

//  Class member function
//  Operator == for comparing statuses (by status)
bool Status::operator==(const Status& status) const
{
  return status_ == status.status_;
}

//  Class member function
//  Operator != for comparing statuses (by status)
bool Status::operator!=(const Status& status) const
{
  return !(*this == status);
}

//  Class member function
//  Operator < for sorting statuses (by status)
bool operator<(const Status& status_left, const Status& status_right)
{
  return status_left.status_ < status_right.status_;
}
