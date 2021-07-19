#ifndef HOMEBOOKKEEPING_0MODELS_TAG_H_
#define HOMEBOOKKEEPING_0MODELS_TAG_H_

#include <iostream>
#include <string>

#include "include/0_Models/Model.h"

class Tag : public Model
{
public:
  Tag();
  Tag(const std::string& name);
};

#endif
