#include "include/0_Models/Description.h"

//  Constructor
//  Default (name = "Unspecified")
Description::Description():
  Model{ }
{}

//  Constructor
//  With name setting
Description::Description(const std::string& name):
  Model{ name }
{}
