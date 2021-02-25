#include "TransactionRepository.h"

// Default constructor
TransactionRepository::TransactionRepository()
{}

// Class member function. Add transaction to repository
void TransactionRepository::add(Transaction transactionForAdd)
{
	repository.insert(std::make_shared<Transaction>(transactionForAdd));
}

// Class member function. Add shared pointer to transaction to repository
void TransactionRepository::add(std::shared_ptr<Transaction> transactionForAdd)
{
	repository.insert(transactionForAdd);
}

// Class member function. Remove shared pointer to transaction from repository
void TransactionRepository::remove(std::shared_ptr<Transaction> transactionForRemove)
{
	repository.erase(transactionForRemove);
}

// Class member function. Calculate size of repository
size_t TransactionRepository::size() const
{
	return repository.size();
}

// Class member function. Clear repository
void TransactionRepository::clear()
{
	repository.clear();
}

// Class member function. Find shared pointer to transaction in repository
TransactionRepositoryIterator TransactionRepository::find(std::shared_ptr<Transaction> transactionForFind) const
{
	return repository.find(transactionForFind);
}

// Class member function. Find begin iterator of repository
TransactionRepositoryIterator TransactionRepository::begin() const
{
	return repository.begin();
}

// Class member function. Find end iterator of repository
TransactionRepositoryIterator TransactionRepository::end() const
{
	return repository.end();
}