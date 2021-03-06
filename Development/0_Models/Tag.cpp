#include "home_bookkeeping/0_Models/Tag.h"

//  Constructor
//  Default (name = "")
Tag::Tag():
  Model{ "" }
{}

//  Constructor
//  With name setting
Tag::Tag(const std::string& name):
  Model{ name }
{}
