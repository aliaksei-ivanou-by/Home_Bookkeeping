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
	std::set<Comment> repository;
public:
	CommentRepository() {}
	void add(Comment name)
	{
		repository.insert(name);
	}
	void remove(Comment name)
	{
		repository.erase(name);
	}
	std::set<Comment> get_comment_repository() const
	{
		return repository;
	}
	void set_comment_repository(std::set<Comment>&& comments)
	{
		repository = comments;
	}
};

#endif