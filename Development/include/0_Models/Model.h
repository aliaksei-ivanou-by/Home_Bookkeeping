#ifndef HOMEBOOKKEEPING_0MODELS_MODEL_H_
#define HOMEBOOKKEEPING_0MODELS_MODEL_H_

#include <iostream>
#include <string>

#include "lib/logger/Log.h"
#include "lib/logger/Initializers/RollingFileInitializer.h"

using NUM = double;

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

#endif
