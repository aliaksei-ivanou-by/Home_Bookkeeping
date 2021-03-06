#include "home_bookkeeping/0_Models/Comment.h"

//  Constructor
//  Default (name = "")
Comment::Comment():
  Model{ "" }
{}

//  Constructor
//  With name setting
Comment::Comment(const std::string& name):
  Model{ name }
{}
