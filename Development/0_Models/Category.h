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
//    Operator < for sorting models (by name)
//    Output model (name)
//    Input model (name)
//
//  Variables:
//    name
//    kNameUnspecified

#include <iostream>
#include <string>

#include "home_bookkeeping/0_Models/Model.h"

class Category : public Model
{
public:
  Category();
  Category(const std::string& name);
private:
  std::string kNameUnspecified = "Unspecified";
};

#endif  //  HOMEBOOKKEEPING_0MODELS_CATEGORY_H_
