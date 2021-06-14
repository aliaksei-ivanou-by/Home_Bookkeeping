#ifndef HOMEBOOKKEEPING_0MODELS_CURRECY_H_
#define HOMEBOOKKEEPING_0MODELS_CURRECY_H_

//  Class Currency : public Model
//
//  Constructors:
//    Default (name = "Unspecified", code = "Unspecified", activity = false)
//    With name setting (code = "Unspecified", activity = false)
//    With name setting and code setting (activity = true)
//    With name setting, code setting and activity setting
//    With name setting, code setting, activity setting and precision setting
//
//  Class member functions:
//    Get name
//    Get code
//    Get activity
//    Get precision
//    Set name
//    Set code
//    Set activity
//    Switch activity
//    Switch on activity
//    Switch off activity
//    Set precision
//    Operator < for sorting models (by name (1), code (2), activity (3))
//    Operator == for eqials models (by name (1), code (2), activity (3))
//    Operator != for eqials models (by name (1), code (2), activity (3))
//    Output model (name, code, activity -> "name (code, activity)")
//    Input model (name, code, activity -> "name, amount, activity, precision")
//
//  Variables:
//    name
//    code
//    activity
//    precision

#include <iostream>
#include <string>

#include "home_bookkeeping/0_Models/Model.h"

class Currency : public Model
{
public:
  Currency();
  Currency(const std::string& name);
  Currency(const std::string& name, const std::string& code);
  Currency(const std::string& name, const std::string& code, bool activity);
  Currency(const std::string& name, const std::string& code, bool activity, int precision);
  std::string GetCode() const;
  bool GetActivity() const;
  int GetPrecision() const;
  void SetCode(const std::string& code);
  void SetActivity(const bool activity);
  void Switch();
  void SwitchOn();
  void SwitchOff();
  void SetPrecision(const int precision);
  friend bool operator<(const Currency& model_left, const Currency& model_right);
  friend bool operator==(const Currency& model_left, const Currency& model_right);
  friend bool operator!=(const Currency& model_left, const Currency& model_right);
  friend std::ostream& operator<<(std::ostream& output_stream, const Currency& model);
  friend std::istream& operator>>(std::istream& input_stream, Currency& model);
private:
  std::string code_;
  bool activity_;
  int precision_;
};

#endif  //  HOMEBOOKKEEPING_0MODELS_CURRECY_H_
