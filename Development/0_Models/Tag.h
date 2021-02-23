#pragma once
#include "../include/stdafx.h"

/*
Class Tag
Includes tag name.

Constructors:
	Default (name of the tag is empty)
	With the setting of the name of the tag

Class member functions:
	Get the name of the tag
	Set the name of the tag
	Operator < for sorting tags
	Print tag
*/

class Tag
{
private:
	std::string tagName;
public:
	Tag();
	Tag(const std::string& tagNameForAdd);

	std::string getTagName() const;

	void setTagName(const std::string& tagNameForUpdate);

	friend bool operator<(const Tag& leftTag, const Tag& rightTag);
	friend std::ostream& operator<<(std::ostream& outputStream, const Tag& tag);
};