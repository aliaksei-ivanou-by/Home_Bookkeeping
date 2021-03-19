#include "home_bookkeeping/0_Models/Category.h"

//  Constructor
//  Default (name = "Unspecified")
Category::Category():
  Model{ }
{}

//  Constructor
//  With name setting
Category::Category(const std::string& name):
  Model{ name }
{}
