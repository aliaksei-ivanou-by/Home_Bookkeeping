#pragma once

#ifndef COMMENT_H
#define COMMENT_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

class Comment
{
private:
	std::string commentName;
public:
	Comment()
		: commentName{ "" }
	{}
	Comment(std::string commentName)
		: commentName{ commentName }
	{}
	std::string getCommentName() const
	{
		return this->commentName;
	}
	void setCommentName(std::string&& commentName)
	{
		this->commentName = commentName;
	}
	friend bool operator<(const Comment& leftComment, const Comment& rightComment)
	{
		return (leftComment.getCommentName()) < (rightComment.getCommentName());
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const Comment& comment)
	{
		return outputStream << comment.getCommentName();
	}
};

#endif