#include "CommentRepository.h"

CommentRepository::CommentRepository()
{}

void CommentRepository::addComment(Comment commentForAdd)
{
	commentRepository.insert(commentForAdd);
}

void CommentRepository::removeComment(Comment commentForRemove)
{
	commentRepository.erase(commentForRemove);
}

size_t CommentRepository::sizeCommentRepository() const
{
	return commentRepository.size();
}

void CommentRepository::clearCommentRepository()
{
	commentRepository.clear();
}

CommentRepositoryIterator CommentRepository::findCommentRepository(Comment&& commentForFind) const
{
	return commentRepository.find(std::move(commentForFind));
}