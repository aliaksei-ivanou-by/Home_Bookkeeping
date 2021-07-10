#ifndef HOMEBOOKKEEPING_0MODELS_CATEGORY_H_
#define HOMEBOOKKEEPING_0MODELS_CATEGORY_H_

//  Class Category : public Model
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

#include "include/0_Models/Model.h"

class Category : public Model
{
public:
  Category();
  Category(const std::string& name);
};

#endif  //  HOMEBOOKKEEPING_0MODELS_CATEGORY_H_
