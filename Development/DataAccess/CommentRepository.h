#pragma once

#ifndef COMMENTREPOSITORY_H
#define COMMENTREPOSITORY_H

#ifndef STDAFX_H
#include "../include/stdafx.h"
#endif

#ifndef COMMENT_H
#include "../Models/Comment.h"
#endif

class CommentRepository
{
private:
	std::set<Comment> commentRepository;
public:
	CommentRepository()
	{}
	void addComment(Comment comment)
	{
		commentRepository.insert(comment);
	}
	void removeComment(Comment comment)
	{
		commentRepository.erase(comment);
	}
	std::set<Comment> getCommentRepository() const
	{
		return commentRepository;
	}
	void setCommentRepository(std::set<Comment>&& comments)
	{
		commentRepository = comments;
	}
};

#endif