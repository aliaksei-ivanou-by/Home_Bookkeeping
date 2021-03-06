#include "home_bookkeeping/0_Models/Description.h"

//  Constructor
//  Default (name = "")
Description::Description():
  Model{ "" }
{}

//  Constructor
//  With name setting
Description::Description(const std::string& name):
  Model{ name }
{}
