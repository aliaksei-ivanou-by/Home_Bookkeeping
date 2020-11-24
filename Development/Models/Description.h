#pragma once

#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Description
{
private:
	std::string descriptionName;
public:
	Description()
		: descriptionName{ "" }
	{}
	Description(std::string descriptionName)
		: descriptionName{ descriptionName }
	{}
	std::string getDescriptionName() const
	{
		return this->descriptionName;
	}
	void setDescriptionName(std::string&& descriptionName)
	{
		this->descriptionName = descriptionName;
	}
	friend bool operator<(const Description& leftDescription, const Description& rightDescription)
	{
		return (leftDescription.getDescriptionName()) < (rightDescription.getDescriptionName());
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const Description& description)
	{
		return outputStream << description.getDescriptionName();
	}
};

#endif