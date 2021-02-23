#include "Description.h"

// Default constructor
Description::Description():
	descriptionName{ "" }
{}

// Constructor with the setting of the name of the description
Description::Description(const std::string& descriptionNameForAdd):
	descriptionName{ descriptionNameForAdd }
{}

// Class member function. Get the name of the description
std::string Description::getDescriptionName() const
{
	return descriptionName;
}

// Class member function. Set the name of the description
void Description::setDescriptionName(const std::string& descriptionNameForUpdate)
{
	descriptionName = descriptionNameForUpdate;
}

// Class member function. Operator < for sorting descriptions
bool operator<(const Description& leftDescription, const Description& rightDescription)
{
	return (leftDescription.getDescriptionName()) < (rightDescription.getDescriptionName());
}

// Class member function. Print description
std::ostream& operator<<(std::ostream& outputStream, const Description& description)
{
	return outputStream << description.getDescriptionName();
}