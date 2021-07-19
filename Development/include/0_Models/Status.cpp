#include "include/0_Models/Status.h"

Status::Status():
  Model{ static_cast<std::string>(magic_enum::enum_name(kEnumStatus::None)) },
  status_{ kEnumStatus::None }
{}

Status::Status(const kEnumStatus& status):
  Model{ static_cast<std::string>(magic_enum::enum_name(status)) },
  status_{ status }
{}

void Status::SetName(const std::string& name)
{
  auto name_new = magic_enum::enum_cast<kEnumStatus>(name);
  if (name_new.has_value())
  {
    SetStatus(name_new.value());
    Model::SetName(name);
    PLOG_INFO << "Set new status";
  }
}

kEnumStatus Status::GetStatus() const
{
  return status_;
}

void Status::SetStatus(const kEnumStatus& status)
{
  status_ = status;
  PLOG_INFO << "Set new status";
}

bool operator<(const Status& status_left, const Status& status_right)
{
  return status_left.status_ < status_right.status_;
}

bool operator==(const Status& status_left, const Status& status_right)
{
  return status_left.status_ == status_right.status_;
}

bool operator!=(const Status& status_left, const Status& status_right)
{
  return !(status_left.status_ == status_right.status_);
}

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
