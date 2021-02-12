#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Comment.h"

using CommentRepositoryIterator = std::set<Comment>::iterator;

class CommentRepository
{
private:
	std::set<Comment> commentRepository;
public:
	CommentRepository();
	void addComment(Comment commentForAdd);
	void removeComment(Comment commentForRemove);
	size_t sizeCommentRepository();
	void clearCommentRepository();
	CommentRepositoryIterator findCommentRepository(Comment&& commentForFind);
};