#include "include/0_Models/Model.h"

Model::Model() :
  name_{ "Unspecified" }
{}

Model::Model(const std::string& name) :
  name_{ name }
{}

std::string Model::GetName() const
{
  return name_;
}

void Model::SetName(const std::string& name)
{
  name_ = name;
  PLOG_INFO << "Set new name";
}

bool operator<(const Model& model_left, const Model& model_right)
{
  return (model_left.name_) < (model_right.name_);
}

bool operator==(const Model& model_left, const Model& model_right)
{
  return (model_left.name_) == (model_right.name_);
}

bool operator!=(const Model& model_left, const Model& model_right)
{
  return (!(model_left == model_right));
}

std::ostream& operator<<(std::ostream& output_stream, const Model& model)
{
  return output_stream << model.name_;
}

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
