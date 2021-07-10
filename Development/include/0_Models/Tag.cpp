#include "include/0_Models/Tag.h"

//  Constructor
//  Default (name = "Unspecified")
Tag::Tag():
  Model{ }
{}

//  Constructor
//  With name setting
Tag::Tag(const std::string& name):
  Model{ name }
{}
