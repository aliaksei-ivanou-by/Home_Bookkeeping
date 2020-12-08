#include "Payee.h"

Payee::Payee():
	payeeName{ "" }
{}

Payee::Payee(std::string payeeNameNew):
	payeeName{ payeeNameNew }
{}

std::string Payee::getPayeeName() const
{
	return payeeName;
}

void Payee::setPayeeName(std::string&& payeeNameNew)
{
	payeeName = std::move(payeeNameNew);
}

bool operator<(const Payee& leftPayee, const Payee& rightPayee)
{
	return (leftPayee.getPayeeName()) < (rightPayee.getPayeeName());
}
std::ostream& operator<<(std::ostream& outputStream, const Payee& payee)
{
	return outputStream << payee.getPayeeName();
}