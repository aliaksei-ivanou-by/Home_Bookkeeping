#ifndef HOMEBOOKKEEPING_0MODELS_STATUS_H_
#define HOMEBOOKKEEPING_0MODELS_STATUS_H_

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

#endif
