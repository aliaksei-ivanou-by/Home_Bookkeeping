#include "home_bookkeeping/0_Models/Status.h"

//  Constructor
//  Default (status = "None")
Status::Status():
  Model{ static_cast<std::string>(magic_enum::enum_name(kEnumStatus::None)) },
  status_{ kEnumStatus::None }
{}

//  Constructor
//  With status setting
Status::Status(const kEnumStatus& status):
  Model{ static_cast<std::string>(magic_enum::enum_name(status)) },
  status_{ status }
{}

//  Class member function
//  Set name
void Status::SetName(const std::string& name)
{
  auto name_new = magic_enum::enum_cast<kEnumStatus>(name);
  if (name_new.has_value())
  {
    SetStatus(name_new.value());
    Model::SetName(name);
  }
}

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

//  Friend class member function
//  Input model (name)
std::istream& operator>>(std::istream& input_stream, Status& model)
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
