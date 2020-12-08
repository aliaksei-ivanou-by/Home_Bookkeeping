#pragma once

#include "../include/stdafx.h"

class Comment
{
private:
	std::string commentName;
public:
	Comment();
	Comment(std::string commentNameNew);
	std::string getCommentName() const;
	void setCommentName(std::string&& commentNameNew);
	friend bool operator<(const Comment& leftComment, const Comment& rightComment);
	friend std::ostream& operator<<(std::ostream& outputStream, const Comment& comment);
};