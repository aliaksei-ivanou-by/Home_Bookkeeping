#include "Payee.h"

Payee::Payee():
	payeeName{ "" }
{}

Payee::Payee(const std::string& payeeNameForAdd):
	payeeName{ payeeNameForAdd }
{}

std::string Payee::getPayeeName() const
{
	return payeeName;
}

void Payee::setPayeeName(const std::string& payeeNameForUpdate)
{
	payeeName = payeeNameForUpdate;
}

bool operator<(const Payee& leftPayee, const Payee& rightPayee)
{
	return (leftPayee.getPayeeName()) < (rightPayee.getPayeeName());
}
std::ostream& operator<<(std::ostream& outputStream, const Payee& payee)
{
	return outputStream << payee.getPayeeName();
}