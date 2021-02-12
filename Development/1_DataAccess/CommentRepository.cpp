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

size_t CommentRepository::sizeCommentRepository()
{
	return commentRepository.size();
}

void CommentRepository::clearCommentRepository()
{
	commentRepository.clear();
}

CommentRepositoryIterator CommentRepository::findCommentRepository(Comment&& commentForFind)
{
	return commentRepository.find(std::move(commentForFind));
}