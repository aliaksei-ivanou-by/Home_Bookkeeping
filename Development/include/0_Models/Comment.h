#ifndef HOMEBOOKKEEPING_0MODELS_COMMENT_H_
#define HOMEBOOKKEEPING_0MODELS_COMMENT_H_

#include <iostream>
#include <string>

#include "include/0_Models/Model.h"

class Comment : public Model
{
public:
  Comment();
  Comment(const std::string& name);
};

#endif
