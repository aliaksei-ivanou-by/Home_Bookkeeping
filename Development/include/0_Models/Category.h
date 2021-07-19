#ifndef HOMEBOOKKEEPING_0MODELS_CATEGORY_H_
#define HOMEBOOKKEEPING_0MODELS_CATEGORY_H_

#include <iostream>
#include <string>

#include "include/0_Models/Model.h"

class Category : public Model
{
public:
  Category();
  Category(const std::string& name);
};

#endif
