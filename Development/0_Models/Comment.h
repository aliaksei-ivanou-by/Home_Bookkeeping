#pragma once
#include "../include/stdafx.h"

/*
Class Comment
Includes comment name.

Constructors:
	Default (name of the comment is empty)
	With the setting of the name of the comment

Class member functions:
	Get the name of the comment
	Set the name of the comment
	Operator < for sorting comments
	Print comment
*/

class Comment
{
private:
	std::string commentName;
public:
	Comment();
	Comment(const std::string& commentNameForAdd);

	std::string getCommentName() const;

	void setCommentName(const std::string& commentNameForUpdate);

	friend bool operator<(const Comment& leftComment, const Comment& rightComment);
	friend std::ostream& operator<<(std::ostream& outputStream, const Comment& comment);
};