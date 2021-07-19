#ifndef HOMEBOOKKEEPING_0MODELS_DESCRIPTION_H_
#define HOMEBOOKKEEPING_0MODELS_DESCRIPTION_H_

#include <iostream>
#include <string>

#include "include/0_Models/Model.h"

class Description : public Model
{
public:
  Description();
  Description(const std::string& name);
};

#endif
