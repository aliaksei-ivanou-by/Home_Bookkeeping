#ifndef HOMEBOOKKEEPING_0MODELS_TAG_H_
#define HOMEBOOKKEEPING_0MODELS_TAG_H_

//  Class Tag : public Model
//
//  Constructors:
//    Default (name = "Unspecified")
//    With name setting
//
//  Class member functions:
//    Get name
//    Set name
//    Operator < for comparing models (by name)
//    Operator == for comparing models (by name)
//    Operator != for comparing models (by name)
//    Output model (name)
//    Input model (name)
//
//  Variables:
//    name

#include <iostream>
#include <string>

#include "home_bookkeeping/0_Models/Model.h"

class Tag : public Model
{
public:
  Tag();
  Tag(const std::string& name);
};

#endif  //  HOMEBOOKKEEPING_0MODELS_TAG_H_
