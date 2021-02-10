#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Comment.h"

class CommentRepository
{
private:
	std::set<Comment> commentRepository;
public:
	CommentRepository();
	void addComment(Comment commentForAdd);
	void removeComment(Comment commentForRemove);
	std::set<Comment> getCommentRepository() const;
	void setCommentRepository(std::set<Comment>&& commentsForAdd);
};