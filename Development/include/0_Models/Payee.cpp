#include "include/0_Models/Payee.h"

//  Constructor
//  Default (name = "Unspecified")
Payee::Payee():
  Model{ }
{}

//  Constructor
//  With name setting
Payee::Payee(const std::string& name):
  Model{ name }
{}
