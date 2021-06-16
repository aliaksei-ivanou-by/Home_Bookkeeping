#ifndef HOMEBOOKKEEPING_0MODELS_CURRECY_H_
#define HOMEBOOKKEEPING_0MODELS_CURRECY_H_

//  Class Currency : public Model
//
//  Constructors:
//    Default (name = "Unspecified", code = "Unspecified", activity = false)
//    With name setting (code = "Unspecified", activity = false)
//    With name setting and code setting (activity = true)
//    With name setting, code setting and activity setting
//
//  Class member functions:
//    Get name
//    Get code
//    Get activity
//    Set name
//    Set code
//    Set activity
//    Switch activity
//    Switch on activity
//    Switch off activity
//    Operator < for comparing models (by name (1), code (2), activity (3))
//    Operator == for comparing models (by name, code, activity)
//    Operator != for comparing models (by name, code, activity)
//    Output model (name, code, activity -> "name (code, activity)")
//    Input model (name, code, activity -> "name, amount, activity")
//
//  Variables:
//    name
//    code
//    activity


#include <iostream>
#include <string>

#include "home_bookkeeping/0_Models/Model.h"

class Currency : public Model
{
public:
  Currency();
  Currency(const std::string& name);
  Currency(const std::string& name, const std::string& code);
  Currency(const std::string& name, const std::string& code, const bool activity);
  std::string GetCode() const;
  bool GetActivity() const;
  void SetCode(const std::string& code);
  void SetActivity(const bool activity);
  void Switch();
  void SwitchOn();
  void SwitchOff();
  friend bool operator<(const Currency& model_left, const Currency& model_right);
  friend bool operator==(const Currency& model_left, const Currency& model_right);
  friend bool operator!=(const Currency& model_left, const Currency& model_right);
  friend std::ostream& operator<<(std::ostream& output_stream, const Currency& model);
  friend std::istream& operator>>(std::istream& input_stream, Currency& model);
private:
  std::string code_;
  bool activity_;
};

#endif  //  HOMEBOOKKEEPING_0MODELS_CURRECY_H_
