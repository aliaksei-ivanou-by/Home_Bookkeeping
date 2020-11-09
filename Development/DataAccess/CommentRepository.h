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
	void add(std::string name)
	{
		repository.insert(name);
	}
	void remove(std::string name)
	{
		repository.erase(name);
	}
};

#endif