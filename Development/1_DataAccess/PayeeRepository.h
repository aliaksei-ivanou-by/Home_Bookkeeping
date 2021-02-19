#pragma once

#include "../include/stdafx.h"
#include "../0_Models/Payee.h"

using PayeeRepositoryIterator = std::set<std::shared_ptr<Payee>>::iterator;

class PayeeRepository
{
private:
	std::set<std::shared_ptr<Payee>> repository;
public:
	PayeeRepository();
	void add(Payee payeeForAdd);
	void add(std::shared_ptr<Payee> payeeForAdd);
	void remove(std::shared_ptr<Payee> payeeForRemove);
	size_t size() const;
	void clear();
	PayeeRepositoryIterator find(std::shared_ptr<Payee> payeeForFind) const;
	PayeeRepositoryIterator begin() const;
	PayeeRepositoryIterator end() const;
};