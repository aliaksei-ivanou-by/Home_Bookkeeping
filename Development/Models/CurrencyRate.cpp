#include "CurrencyRate.h"

CurrencyRate::CurrencyRate():
	currencyRateName{ "" }
{}

CurrencyRate::CurrencyRate(std::string currencyRateNameNew):
	currencyRateName{ currencyRateNameNew }
{}

std::string CurrencyRate::getCurrencyRateName() const
{
	return currencyRateName;
}

void CurrencyRate::setCurrencyRateName(std::string&& currencyRateNameNew)
{
	currencyRateName = std::move(currencyRateNameNew);
}

bool operator<(const CurrencyRate& leftCurrencyRate, const CurrencyRate& rightCurrencyRate)
{
	return (leftCurrencyRate.getCurrencyRateName()) < (rightCurrencyRate.getCurrencyRateName());
}
std::ostream& operator<<(std::ostream& outputStream, const CurrencyRate& currencyRate)
{
	return outputStream << currencyRate.getCurrencyRateName();
}