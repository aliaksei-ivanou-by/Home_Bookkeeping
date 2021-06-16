#ifndef HOMEBOOKKEEPING_0MODELS_MODEL_H_
#define HOMEBOOKKEEPING_0MODELS_MODEL_H_

//  Class Model
//
//  Constructors:
//    Default (name = "Unspecified")
//    With name setting
//
//  Class member functions:
//    Get name
//    Set name
//    Operator < for comparing models (by name)
//    Operator == for comparing models (by name)
//    Operator != for comparing models (by name)
//    Output model (name)
//    Input model (name)
//
//  Variables:
//    name

#include <iostream>
#include <string>

#include "home_bookkeeping/lib/logger/Log.h"
#include "home_bookkeeping/lib/logger/Initializers/RollingFileInitializer.h"
#include "home_bookkeeping/lib/decimal/decimal.h"

using NUM = dec::decimal<6>;

class Model
{
public:
  Model();
  Model(const std::string& name);
  virtual std::string GetName() const;
  virtual void SetName(const std::string& name);
  friend bool operator<(const Model& model_left, const Model& model_right);
  friend bool operator==(const Model& model_left, const Model& model_right);
  friend bool operator!=(const Model& model_left, const Model& model_right);
  friend std::ostream& operator<<(std::ostream& output_stream, const Model& model);
  friend std::istream& operator>>(std::istream& input_stream, Model& model);
private:
  std::string name_;
};

#endif  //  HOMEBOOKKEEPING_0MODELS_MODEL_H_
