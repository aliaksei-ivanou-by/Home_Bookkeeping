#include "Comment.h"

// Default constructor
Comment::Comment():
	commentName{ "" }
{}

// Constructor with the setting of the name of the comment
Comment::Comment(const std::string& commentNameForAdd):
	commentName{ commentNameForAdd }
{}

// Class member function. Get the name of the comment
std::string Comment::getCommentName() const
{
	return commentName;
}

// Class member function. Set the name of the comment
void Comment::setCommentName(const std::string& commentNameForUpdate)
{
	commentName = commentNameForUpdate;
}

// Class member function. Operator < for sorting comments
bool operator<(const Comment& leftComment, const Comment& rightComment)
{
	return (leftComment.getCommentName()) < (rightComment.getCommentName());
}

// Class member function. Print comment
std::ostream& operator<<(std::ostream& outputStream, const Comment& comment)
{
	return outputStream << comment.getCommentName();
}