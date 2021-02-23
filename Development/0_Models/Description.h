#pragma once
#include "../include/stdafx.h"

/*
Class Description
Includes description name.

Constructors:
	Default (name of the description is empty)
	With the setting of the name of the description

Class member functions:
	Get the name of the description
	Set the name of the description
	Operator < for sorting descriptions
	Print description
*/

class Description
{
private:
	std::string descriptionName;
public:
	Description();
	Description(const std::string& descriptionNameForAdd);

	std::string getDescriptionName() const;

	void setDescriptionName(const std::string& descriptionNameForUpdate);

	friend bool operator<(const Description& leftDescription, const Description& rightDescription);
	friend std::ostream& operator<<(std::ostream& outputStream, const Description& description);
};