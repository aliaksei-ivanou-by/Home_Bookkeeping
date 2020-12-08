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

std::set<Comment> CommentRepository::getCommentRepository() const
{
	return commentRepository;
}

void CommentRepository::setCommentRepository(std::set<Comment>&& commentsForAdd)
{
	commentRepository = commentsForAdd;
}