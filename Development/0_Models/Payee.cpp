#include "home_bookkeeping/0_Models/Payee.h"

//  Constructor
//  Default (name = "")
Payee::Payee():
  Model{ "" }
{}

//  Constructor
//  With name setting
Payee::Payee(const std::string& name):
  Model{ name }
{}
