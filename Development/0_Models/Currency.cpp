#include "home_bookkeeping/0_Models/Currency.h"

//  Constructor
//  Default (name = "", code = "", activity = false)
Currency::Currency():
  Model{ "" },
  code_{ "" },
  activity_{ false }
{}

//  Constructor
//  With name setting (code = "", activity = true)
Currency::Currency(const std::string& name):
  Model{ name },
  code_{ "" },
  activity_{ true }
{}

//  Constructor
//  With name setting and code setting (activity = true)
Currency::Currency(const std::string& name, const std::string& code):
  Model{ name },
  code_{ code },
  activity_{ true }
{}

//  Constructor
//  With name setting, code setting and activity setting
Currency::Currency(const std::string& name, const std::string& code, bool activity):
  Model{ name },
  code_{ code },
  activity_{ activity }
{}

//  Class member function
//  Get code
std::string Currency::GetCode() const
{
  return code_;
}

//  Class member function
//  Get activity
bool Currency::GetActivity() const
{
  return activity_;
}

//  Class member function
//  Set code
void Currency::SetCode(const std::string& code)
{
  code_ = code;
}

//  Class member function
//  Set activity
void Currency::SetActivity(const bool activity)
{
  activity_ = activity;
}

//  Friend class member function
//  Operator < for sorting models (by name (1), code (2), activity (3))
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
          if ((model_left.activity_ < model_right.activity_))
          {
            return true;
          }
          else
          {
            return false;
          }
        }
      }
    }
  }
}

//  Friend class member function
//  Output model (name, code, activity -> "name (code, activity)")
std::ostream& operator<<(std::ostream& outputStream, const Currency& model)
{
  return outputStream << model.GetName() << " ("<< model.code_ << ", " << model.activity_ << ")";
}

//  Friend class member function
//  Input model (name, code, activity -> "name, amount, activity")
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
  input_stream >> activity;
  if (!input_stream)
  {
    return input_stream;
  }
  model.SetActivity(activity);
  return input_stream;
}