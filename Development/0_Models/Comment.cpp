#include "Comment.h"

Comment::Comment():
	commentName{ "" }
{}

Comment::Comment(std::string commentNameForAdd):
	commentName{ commentNameForAdd }
{}

std::string Comment::getCommentName() const
{
	return commentName;
}

void Comment::setCommentName(std::string&& commentNameForUpdate)
{
	commentName = std::move(commentNameForUpdate);
}

bool operator<(const Comment& leftComment, const Comment& rightComment)
{
	return (leftComment.getCommentName()) < (rightComment.getCommentName());
}

std::ostream& operator<<(std::ostream& outputStream, const Comment& comment)
{
	return outputStream << comment.getCommentName();
}