#ifndef HOMEBOOKKEEPING_0MODELS_CURRECY_H_
#define HOMEBOOKKEEPING_0MODELS_CURRECY_H_

#include <iostream>
#include <string>

#include "include/0_Models/Model.h"

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

#endif
