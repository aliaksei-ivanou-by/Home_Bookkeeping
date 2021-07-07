#ifndef HOMEBOOKKEEPING_0MODELS_PAYEE_H_
#define HOMEBOOKKEEPING_0MODELS_PAYEE_H_

//  Class Payee
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

#include "Home_Bookkeeping/0_Models/Model.h"

class Payee : public Model
{
public:
  Payee();
  Payee(const std::string& name);
};

#endif  //  HOMEBOOKKEEPING_0MODELS_PAYEE_H_
