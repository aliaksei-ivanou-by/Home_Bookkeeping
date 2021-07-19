#include "include/0_Models/Currency.h"

Currency::Currency() :
  Model{ },
  code_{ "Unspecified" },
  activity_{ false }
{}

Currency::Currency(const std::string& name) :
  Model{ name },
  code_{ "Unspecified" },
  activity_{ false }
{}

Currency::Currency(const std::string& name, const std::string& code) :
  Model{ name },
  code_{ code },
  activity_{ true }
{}

Currency::Currency(const std::string& name, const std::string& code, const bool activity) :
  Model{ name },
  code_{ code },
  activity_{ activity }
{}

std::string Currency::GetCode() const
{
  return code_;
}

bool Currency::GetActivity() const
{
  return activity_;
}

void Currency::SetCode(const std::string& code)
{
  code_ = code;
  PLOG_INFO << "Set new code";
}

void Currency::SetActivity(const bool activity)
{
  activity_ = activity;
  PLOG_INFO << "Set new activity";
}

void Currency::Switch()
{
  activity_ = !(activity_);
  PLOG_INFO << "Switch activity";
}

void Currency::SwitchOn()
{
  activity_ = true;
  PLOG_INFO << "Switch on activity";
}

void Currency::SwitchOff()
{
  activity_ = false;
  PLOG_INFO << "Switch off activity";
}

bool operator<(const Currency& model_left, const Currency& model_right)
{
  if (model_left.GetName() < model_right.GetName())
  {
    return true;
  }
  else
  {
    if (model_left.GetName() > model_right.GetName())
    {
      return false;
    }
    else
    {
      if (model_left.code_ < model_right.code_)
      {
        return true;
      }
      else
      {
        if (model_left.code_ > model_right.code_)
        {
          return false;
        }
        else
        {
          return model_left.activity_ < model_right.activity_;
        }
      }
    }
  }
}

bool operator==(const Currency& model_left, const Currency& model_right)
{
  return ((model_left.GetName() == model_right.GetName()) &&
    (model_left.code_ == model_right.code_) &&
    (model_left.activity_ == model_right.activity_));
}

bool operator!=(const Currency& model_left, const Currency& model_right)
{
  return (!(model_left == model_right));
}

std::ostream& operator<<(std::ostream& outputStream, const Currency& model)
{
  return outputStream << model.GetName() << " (" << model.code_ << ", " << model.activity_ << ")";
}

std::istream& operator>>(std::istream& input_stream, Currency& model)
{
  if (!input_stream)
  {
    return input_stream;
  }
  std::string name;
  while (true)
  {
    char ch;
    input_stream.get(ch);
    if (!input_stream)
    {
      return input_stream;
    }
    if (ch == ',')
    {
      break;
    }
    name += ch;
  }
  model.SetName(name);
  std::string code;
  while (true)
  {
    char ch;
    input_stream.get(ch);
    if (!input_stream)
    {
      return input_stream;
    }
    if (ch == ',')
    {
      break;
    }
    code += ch;
  }
  model.SetCode(code);
  bool activity;
  while (true)
  {
    char ch;
    input_stream.get(ch);
    if (!input_stream)
    {
      return input_stream;
    }
    if (ch == ',')
    {
      break;
    }
    activity = ch;
  }
  model.SetActivity(activity);
  return input_stream;
}
