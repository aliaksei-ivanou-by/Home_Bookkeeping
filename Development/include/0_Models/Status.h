#ifndef HOMEBOOKKEEPING_0MODELS_STATUS_H_
#define HOMEBOOKKEEPING_0MODELS_STATUS_H_

//  Class Status : public Model
//
//  Constructors:
//    Default (status = "None", name = "None")
//    With status setting
//
//  Class member functions:
//    Get name
//    Set name
//    Get status
//    Set status
//    Operator < for comparing statuses (by status)
//    Operator == for comparing statuses (by status)
//    Operator != for comparing statuses (by status)
//    Output model (name)
//    Input model (name)
//
//  Variables:
//    name
//    enum class kEnumStatus
//    status

#include "lib/enum/magic_enum.hpp"

#include "include/0_Models/Model.h"

enum class kEnumStatus
{
  Cleared,
  Reconciled,
  Void,
  None
};

class Status : public Model
{
public:
  Status();
  Status(const kEnumStatus& status);
  void SetName(const std::string& name) override;
  kEnumStatus GetStatus() const;
  void SetStatus(const kEnumStatus& status);
  friend bool operator<(const Status& status_left, const Status& status_right);
  friend bool operator==(const Status& status_left, const Status& status_right);
  friend bool operator!=(const Status& status_left, const Status& status_right);
  friend std::istream& operator>>(std::istream& input_stream, Status& model);
private:
  kEnumStatus status_;
};

#endif  //  HOMEBOOKKEEPING_0MODELS_STATUS_H_
