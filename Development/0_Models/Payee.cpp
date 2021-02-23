#include "Payee.h"

// Default constructor
Payee::Payee():
	payeeName{ "" }
{}

// Constructor with the setting of the name of the payee
Payee::Payee(const std::string& payeeNameForAdd):
	payeeName{ payeeNameForAdd }
{}

// Class member function. Get the name of the payee
std::string Payee::getPayeeName() const
{
	return payeeName;
}

// Class member function. Set the name of the payee
void Payee::setPayeeName(const std::string& payeeNameForUpdate)
{
	payeeName = payeeNameForUpdate;
}

// Class member function. Operator < for sorting payees
bool operator<(const Payee& leftPayee, const Payee& rightPayee)
{
	return (leftPayee.getPayeeName()) < (rightPayee.getPayeeName());
}

// Class member function. Print payee
std::ostream& operator<<(std::ostream& outputStream, const Payee& payee)
{
	return outputStream << payee.getPayeeName();
}