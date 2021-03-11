#ifndef HOMEBOOKKEEPING_0MODELS_STATUS_H_
#define HOMEBOOKKEEPING_0MODELS_STATUS_H_

//  Class Status
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
//    enum class kEnumStatus
//    status

enum class kEnumStatus
{
  Cleared,
  Reconciled,
  Void,
  None
};

class Status
{
public:
  Status();
  Status(const kEnumStatus& status);
  kEnumStatus GetStatus() const;
	void SetStatus(const kEnumStatus& status);
  bool operator==(const Status& status) const;
  bool operator!=(const Status& status) const;
	friend bool operator<(const Status& status_left, const Status& status_right);
private:
  kEnumStatus status_;
};

#endif  //  HOMEBOOKKEEPING_0MODELS_STATUS_H_
