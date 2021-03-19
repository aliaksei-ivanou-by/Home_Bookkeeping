#ifndef HOMEBOOKKEEPING_0MODELS_COMMENT_H_
#define HOMEBOOKKEEPING_0MODELS_COMMENT_H_

//  Class Comment : public Model
//
//  Constructors:
//    Default (name = "Unspecified")
//    With name setting
//
//  Class member functions:
//    Get name
//    Set name
//    Operator < for sorting models (by name)
//    Output model (name)
//    Input model (name)
//
//  Variables:
//    name

#include <iostream>
#include <string>

#include "home_bookkeeping/0_Models/Model.h"

class Comment : public Model
{
public:
  Comment();
  Comment(const std::string& name);
};

#endif  //  HOMEBOOKKEEPING_0MODELS_COMMENT_H_
