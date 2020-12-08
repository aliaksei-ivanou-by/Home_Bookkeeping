#include "Description.h"

Description::Description():
	descriptionName{ "" }
{}

Description::Description(std::string descriptionNameNew)
	: descriptionName{ descriptionNameNew }
{}

std::string Description::getDescriptionName() const
{
	return descriptionName;
}

void Description::setDescriptionName(std::string&& descriptionNameNew)
{
	descriptionName = std::move(descriptionNameNew);
}

bool operator<(const Description& leftDescription, const Description& rightDescription)
{
	return (leftDescription.getDescriptionName()) < (rightDescription.getDescriptionName());
}
std::ostream& operator<<(std::ostream& outputStream, const Description& description)
{
	return outputStream << description.getDescriptionName();
}