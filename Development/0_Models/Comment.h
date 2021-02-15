#pragma once

#include "../include/stdafx.h"

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