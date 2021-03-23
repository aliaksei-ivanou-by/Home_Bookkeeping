#include "home_bookkeeping/0_Models/Payee.h"

//  Constructor
//  Default (name = "Unspecified")
Payee::Payee():
  Model{ "Unspecified" }
{}

//  Constructor
//  With name setting
Payee::Payee(const std::string& name):
  Model{ name }
{}
