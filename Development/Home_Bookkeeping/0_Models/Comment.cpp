#include "Home_Bookkeeping/0_Models/Comment.h"

//  Constructor
//  Default (name = "Unspecified")
Comment::Comment():
  Model{ }
{}

//  Constructor
//  With name setting
Comment::Comment(const std::string& name):
  Model{ name }
{}
