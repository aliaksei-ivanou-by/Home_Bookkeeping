#ifndef HOMEBOOKKEEPING_0MODELS_PAYEE_H_
#define HOMEBOOKKEEPING_0MODELS_PAYEE_H_

#include <iostream>
#include <string>

#include "include/0_Models/Model.h"

class Payee : public Model
{
public:
  Payee();
  Payee(const std::string& name);
};

#endif
