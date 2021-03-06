#ifndef HOMEBOOKKEEPING_0MODELS_DESCRIPTION_H_
#define HOMEBOOKKEEPING_0MODELS_DESCRIPTION_H_

//  Class Description : public Model
//
//  Constructors:
//    Default (name = "")
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

class Description : public Model
{
public:
  Description();
  Description(const std::string& name);
};

#endif  //  HOMEBOOKKEEPING_0MODELS_DESCRIPTION_H_
