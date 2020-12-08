#pragma once

#include "../include/stdafx.h"

class Description
{
private:
	std::string descriptionName;
public:
	Description();
	Description(std::string descriptionNameForAdd);
	std::string getDescriptionName() const;
	void setDescriptionName(std::string&& descriptionNameForUpdate);
	friend bool operator<(const Description& leftDescription, const Description& rightDescription);
	friend std::ostream& operator<<(std::ostream& outputStream, const Description& description);
};