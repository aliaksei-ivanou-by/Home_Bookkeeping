#include "Description.h"

Description::Description():
	descriptionName{ "" }
{}

Description::Description(std::string descriptionNameForAdd)
	: descriptionName{ descriptionNameForAdd }
{}

std::string Description::getDescriptionName() const
{
	return descriptionName;
}

void Description::setDescriptionName(std::string&& descriptionNameForUpdate)
{
	descriptionName = std::move(descriptionNameForUpdate);
}

bool operator<(const Description& leftDescription, const Description& rightDescription)
{
	return (leftDescription.getDescriptionName()) < (rightDescription.getDescriptionName());
}
std::ostream& operator<<(std::ostream& outputStream, const Description& description)
{
	return outputStream << description.getDescriptionName();
}