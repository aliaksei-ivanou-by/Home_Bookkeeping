#ifndef HOMEBOOKKEEPING_0MODELS_MODEL_H_
#define HOMEBOOKKEEPING_0MODELS_MODEL_H_

//  Class Model
//
//  Constructors:
//    Default (name = "")
//    With name setting
//
//  Class member functions:
//    Get name
//    Set name
//    Operator < for sorting models (by name)
//    Output model (name)
//    Input model (name)
//
//  Variables:
//    name

#include <iostream>
#include <string>

class Model
{
public:
  Model();
  Model(const std::string& name);
  std::string GetName() const;
  void SetName(const std::string& name);
  friend bool operator<(const Model& model_left, const Model& model_right);
  friend std::ostream& operator<<(std::ostream& output_stream, const Model& model);
  friend std::istream& operator>>(std::istream& input_stream, Model& model);
private:
  std::string name_;
};

#endif  //  HOMEBOOKKEEPING_0MODELS_MODEL_H_