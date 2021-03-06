#include "home_bookkeeping/0_Models/Model.h"

//  Constructor
//  Default (name = "")
Model::Model() :
  name_{ "" }
{}

//  Constructor
//  With name setting
Model::Model(const std::string& name):
  name_{ name }
{}

//  Class member function
//  Get name
std::string Model::GetName() const
{
  return name_;
}

//  Class member function
//  Set name
void Model::SetName(const std::string& name)
{
  name_ = name;
}

//  Class member function
//  Operator < for sorting models (by name)
bool operator<(const Model& model_left, const Model& model_right)
{
  return (model_left.name_) < (model_right.name_);
}

//  Class member function
//  Output model (name)
std::ostream& operator<<(std::ostream& output_stream, const Model& model)
{
  return output_stream << model.name_;
}

//  Class member function
//  Input model (name)
std::istream& operator>>(std::istream& input_stream, Model& model)
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
  model.name_ = name;
  return input_stream;
}
