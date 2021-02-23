#include "Transaction.h"

// Income or Expense
Transaction::Transaction(
	const Account& transactionAccountFromForAdd,
	const Category& transactionCategoryForAdd,
	const double transactionAmountForAdd,
	const Comment& transactionCommentForAdd,
	const Currency& transactionCurrencyForAdd,
	const Description& transactionDescriptionForAdd,
	const Payee& transactionPayeeForAdd,
	const Tag& transactionTagForAdd,
	const TransactionStatus& transactionStatusForAdd,
	const TransactionType& transactionTypeForAdd):

	transactionTime{ Time() },
	transactionAccountFrom{ std::make_shared<Account>(transactionAccountFromForAdd) },
	transactionAccountTo{ std::make_shared<Account>(transactionAccountFromForAdd) },
	transactionCategory{ std::make_shared<Category>(transactionCategoryForAdd) },
	transactionAmount{ transactionAmountForAdd },
	transactionAccountFromCurrentAmount{ 0 },
	transactionAccountToCurrentAmount{ 0 },
	transactionComment{ std::make_shared<Comment>(transactionCommentForAdd) },
	transactionCurrency{ std::make_shared<Currency>(transactionCurrencyForAdd) },
	transactionDescription{ std::make_shared<Description>(transactionDescriptionForAdd) },
	transactionPayee{ std::make_shared<Payee>(transactionPayeeForAdd) },
	transactionTag{ std::make_shared<Tag>(transactionTagForAdd) },
	transactionStatus{ std::make_shared<TransactionStatus>(transactionStatusForAdd) },
	transactionType{ std::make_shared<TransactionType>(transactionTypeForAdd) }
{}

// Income or Expense
Transaction::Transaction(
	const Account& transactionAccountFromForAdd,
	const Category& transactionCategoryForAdd,
	const double transactionAmountForAdd,
	const Comment& transactionCommentForAdd,
	const Currency& transactionCurrencyForAdd,
	const Description& transactionDescriptionForAdd,
	const Payee& transactionPayeeForAdd,
	const Tag& transactionTagForAdd,
	const TransactionStatus& transactionStatusForAdd,
	const TransactionType& transactionTypeForAdd,
	const Account& transactionAccountToForAdd):

	transactionTime{ Time() },
	transactionAccountFrom{ std::make_shared<Account>(transactionAccountFromForAdd) },
	transactionAccountTo{ transactionAccountFrom },
	transactionCategory{ std::make_shared<Category>(transactionCategoryForAdd) },
	transactionAmount{ transactionAmountForAdd },
	transactionAccountFromCurrentAmount{ 0 },
	transactionAccountToCurrentAmount{ 0 },
	transactionComment{ std::make_shared<Comment>(transactionCommentForAdd) },
	transactionCurrency{ std::make_shared<Currency>(transactionCurrencyForAdd) },
	transactionDescription{ std::make_shared<Description>(transactionDescriptionForAdd) },
	transactionPayee{ std::make_shared<Payee>(transactionPayeeForAdd) },
	transactionTag{ std::make_shared<Tag>(transactionTagForAdd) },
	transactionStatus{ std::make_shared<TransactionStatus>(transactionStatusForAdd) },
	transactionType{ std::make_shared<TransactionType>(transactionTypeForAdd) }
{}

// Income or Expense
Transaction::Transaction(
	const Account& transactionAccountFromForAdd,
	const Category& transactionCategoryForAdd,
	const double transactionAmountForAdd,
	const Currency& transactionCurrencyForAdd):

	transactionTime{ Time() },
	transactionAccountFrom{ std::make_shared<Account>(transactionAccountFromForAdd) },
	transactionAccountTo{ transactionAccountFrom },
	transactionCategory{ std::make_shared<Category>(transactionCategoryForAdd) },
	transactionAmount{ transactionAmountForAdd },
	transactionAccountFromCurrentAmount{ 0 },
	transactionAccountToCurrentAmount{ 0 },
	transactionComment{ std::make_shared<Comment>(Comment()) },
	transactionCurrency{ std::make_shared<Currency>(transactionCurrencyForAdd) },
	transactionDescription{ std::make_shared<Description>(Description()) },
	transactionPayee{ std::make_shared<Payee>(Payee()) },
	transactionTag{ std::make_shared<Tag>(Tag()) },
	transactionStatus{ std::make_shared<TransactionStatus>(TransactionStatus()) },
	transactionType{ std::make_shared<TransactionType>(TransactionType()) }
{}

// Transfer
Transaction::Transaction(
	const Account& transactionAccountFromForAdd,
	const Account& transactionAccountToForAdd,
	const Category& transactionCategoryForAdd,
	const double transactionAmountForAdd,
	const Currency& transactionCurrencyForAdd) :

	transactionTime{},
	transactionAccountFrom{ std::make_shared<Account>(transactionAccountFromForAdd) },
	transactionAccountTo{ std::make_shared<Account>(transactionAccountToForAdd) },
	transactionCategory{ std::make_shared<Category>(transactionCategoryForAdd) },
	transactionAmount{ transactionAmountForAdd },
	transactionAccountFromCurrentAmount{ 0 },
	transactionAccountToCurrentAmount{ 0 },
	transactionComment{ std::make_shared<Comment>(Comment()) },
	transactionCurrency{ std::make_shared<Currency>(transactionCurrencyForAdd) },
	transactionDescription{ std::make_shared<Description>(Description()) },
	transactionPayee{ std::make_shared<Payee>(Payee()) },
	transactionTag{ std::make_shared<Tag>(Tag()) },
	transactionStatus{ std::make_shared<TransactionStatus>(TransactionStatus()) },
	transactionType{ std::make_shared<TransactionType>(TransactionType(TransactionTypeEnum::Transfer)) }
{}

Transaction::Transaction(const Transaction& transaction)
{
	transactionTime = Time();
	transactionAccountFrom = std::make_shared<Account>(transaction.getTransactionAccountFrom());
	transactionAccountTo = std::make_shared<Account>(transaction.getTransactionAccountTo());
	transactionCategory = std::make_shared<Category>(transaction.getTransactionCategory());
	transactionAmount = transaction.transactionAmount;
	transactionAccountFromCurrentAmount = transaction.transactionAccountFromCurrentAmount;
	transactionAccountToCurrentAmount = transaction.transactionAccountToCurrentAmount;
	transactionComment = std::make_shared<Comment>(transaction.getTransactionComment());
	transactionCurrency = std::make_shared<Currency>(transaction.getTransactionCurrency());
	transactionDescription = std::make_shared<Description>(transaction.getTransactionDescription());
	transactionPayee = std::make_shared<Payee>(transaction.getTransactionPayee());
	transactionTag = std::make_shared<Tag>(transaction.getTransactionTag());
	transactionStatus = std::make_shared<TransactionStatus>(transaction.getTransactionStatus());
	transactionType = std::make_shared<TransactionType>(transaction.getTransactionType());
}

Transaction& Transaction::operator=(const Transaction& transaction)
{
	transactionTime = Time();
	transactionAccountFrom = std::make_shared<Account>(transaction.getTransactionAccountFrom());
	transactionAccountTo = std::make_shared<Account>(transaction.getTransactionAccountTo());
	transactionCategory = std::make_shared<Category>(transaction.getTransactionCategory());
	transactionAmount = transaction.transactionAmount;
	transactionAccountFromCurrentAmount = transaction.transactionAccountFromCurrentAmount;
	transactionAccountToCurrentAmount = transaction.transactionAccountToCurrentAmount;
	transactionComment = std::make_shared<Comment>(transaction.getTransactionComment());
	transactionCurrency = std::make_shared<Currency>(transaction.getTransactionCurrency());
	transactionDescription = std::make_shared<Description>(transaction.getTransactionDescription());
	transactionPayee = std::make_shared<Payee>(transaction.getTransactionPayee());
	transactionTag = std::make_shared<Tag>(transaction.getTransactionTag());
	transactionStatus = std::make_shared<TransactionStatus>(transaction.getTransactionStatus());
	transactionType = std::make_shared<TransactionType>(transaction.getTransactionType());
}

Time Transaction::getTransactionTime() const
{
	return transactionTime;
}

Account Transaction::getTransactionAccountFrom() const
{
	return *transactionAccountFrom;
}

std::shared_ptr<Account> Transaction::getTransactionAccountPtrFrom() const
{
	return transactionAccountFrom;
}

Account Transaction::getTransactionAccountTo() const
{
	return *transactionAccountTo;
}

std::shared_ptr<Account> Transaction::getTransactionAccountPtrTo() const
{
	return transactionAccountTo;
}

Category Transaction::getTransactionCategory() const
{
	return *transactionCategory;
}

std::shared_ptr<Category> Transaction::getTransactionCategoryPtr() const
{
	return transactionCategory;
}

double Transaction::getTransactionAmount() const
{
	return transactionAmount;
}

double Transaction::getTransactionAccountFromCurrentAmount() const
{
	return transactionAccountFromCurrentAmount;
}

double Transaction::getTransactionAccountToCurrentAmount() const
{
	return transactionAccountToCurrentAmount;
}

double Transaction::getTransactionAccountFromLastAmount() const
{
	return (*transactionAccountFrom).getAccountAmount();
}

double Transaction::getTransactionAccountToLastAmount() const
{
	return (*transactionAccountTo).getAccountAmount();
}

Comment Transaction::getTransactionComment() const
{
	return *transactionComment;
}

std::shared_ptr<Comment> Transaction::getTransactionCommentPtr() const
{
	return transactionComment;
}

Currency Transaction::getTransactionCurrency() const
{
	return *transactionCurrency;
}

std::shared_ptr<Currency> Transaction::getTransactionCurrencyPtr() const
{
	return transactionCurrency;
}

Description Transaction::getTransactionDescription() const
{
	return *transactionDescription;
}

std::shared_ptr<Description> Transaction::getTransactionDescriptionPtr() const
{
	return transactionDescription;
}

Payee Transaction::getTransactionPayee() const
{
	return *transactionPayee;
}

std::shared_ptr<Payee> Transaction::getTransactionPayeePtr() const
{
	return transactionPayee;
}

Tag Transaction::getTransactionTag() const
{
	return *transactionTag;
}

std::shared_ptr<Tag> Transaction::getTransactionTagPtr() const
{
	return transactionTag;
}

TransactionStatus Transaction::getTransactionStatus() const
{
	return *transactionStatus;
}

std::shared_ptr<TransactionStatus> Transaction::getTransactionStatusPtr() const
{
	return transactionStatus;
}

TransactionType Transaction::getTransactionType() const
{
	return *transactionType;
}

std::shared_ptr<TransactionType> Transaction::getTransactionTypePtr() const
{
	return transactionType;
}

void Transaction::setTransactionTime(const Time& timeForUpdate)
{
	transactionTime = timeForUpdate;
}

void Transaction::setTransactionAccountFrom(const Account& accountFromForUpdate)
{
	*transactionAccountFrom = accountFromForUpdate;
}

void Transaction::setTransactionAccountPtrFrom(std::shared_ptr<Account> accountFromForUpdate)
{
	transactionAccountFrom = accountFromForUpdate;
}

void Transaction::setTransactionAccountTo(const Account& accountToForUpdate)
{
	*transactionAccountTo = accountToForUpdate;
}

void Transaction::setTransactionAccountPtrTo(std::shared_ptr<Account> accountFromForUpdate)
{
	transactionAccountTo = accountFromForUpdate;
}

void Transaction::setTransactionCategory(const Category& categoryForUpdate)
{
	*transactionCategory = categoryForUpdate;
}

void Transaction::setTransactionCategoryPtr(std::shared_ptr<Category> categoryForUpdate)
{
	transactionCategory = categoryForUpdate;
}

void Transaction::setTransactionAmount(const double amountForUpdate)
{
	transactionAmount = amountForUpdate;
}

void Transaction::setTransactionAccountFromCurrentAmount(const double amountForUpdate)
{
	transactionAccountFromCurrentAmount = amountForUpdate;
}

void Transaction::setTransactionAccountToCurrentAmount(const double amountForUpdate)
{
	transactionAccountToCurrentAmount = amountForUpdate;
}

void Transaction::setTransactionAccountFromLastAmount(const double amountForUpdate)
{
	(*transactionAccountFrom).setAccountAmount(amountForUpdate);
}

void Transaction::setTransactionAccountToLastAmount(const double amountForUpdate)
{
	(*transactionAccountTo).setAccountAmount(amountForUpdate);
}

void Transaction::setTransactionComment(const Comment& commentForUpdate)
{
	*transactionComment = commentForUpdate;
}

void Transaction::setTransactionCommentPtr(std::shared_ptr<Comment> commentForUpdate)
{
	transactionComment = commentForUpdate;
}

void Transaction::setTransactionCurrency(const Currency& currencyForUpdate)
{
	*transactionCurrency = currencyForUpdate;
}

void Transaction::setTransactionCurrencyPtr(std::shared_ptr<Currency> currencyForUpdate)
{
	transactionCurrency = currencyForUpdate;
}

void Transaction::setTransactionDescription(const Description& descriptionForUpdate)
{
	*transactionDescription = descriptionForUpdate;
}

void Transaction::setTransactionDescriptionPtr(std::shared_ptr<Description> descriptionForUpdate)
{
	transactionDescription = descriptionForUpdate;
}

void Transaction::setTransactionPayee(const Payee& payeeForUpdate)
{
	*transactionPayee = payeeForUpdate;
}

void Transaction::setTransactionPayeePtr(std::shared_ptr<Payee> payeeForUpdate)
{
	transactionPayee = payeeForUpdate;
}

void Transaction::setTransactionTag(const Tag& tagForUpdate)
{
	*transactionTag = tagForUpdate;
}

void Transaction::setTransactionTagPtr(std::shared_ptr<Tag> tagForUpdate)
{
	transactionTag = tagForUpdate;
}

void Transaction::setTransactionTransactionStatus(const TransactionStatus& transactionStatusForUpdate)
{
	*transactionStatus = transactionStatusForUpdate;
}

void Transaction::setTransactionTransactionStatusPtr(std::shared_ptr<TransactionStatus> transactionStatusForUpdate)
{
	transactionStatus = transactionStatusForUpdate;
}

void Transaction::setTransactionTransactionType(const TransactionType& transactionTypeForUpdate)
{
	*transactionType = transactionTypeForUpdate;
}

void Transaction::setTransactionTransactionTypePtr(std::shared_ptr<TransactionType> transactionTypeForUpdate)
{
	transactionType = transactionTypeForUpdate;
}

bool operator<(const Transaction& leftTransaction, const Transaction& rightTransaction)
{
	if (leftTransaction.getTransactionTime() < rightTransaction.getTransactionTime())
	{
		return true;
	}
	else
	{
		if (rightTransaction.getTransactionTime() < leftTransaction.getTransactionTime())
		{
			return false;
		}
		else
		{
			if (leftTransaction.getTransactionAccountFrom() < rightTransaction.getTransactionAccountFrom())
			{
				return true;
			}
			else
			{
				if (rightTransaction.getTransactionAccountFrom() < leftTransaction.getTransactionAccountFrom())
				{
					return false;
				}
				else
				{
					if (leftTransaction.getTransactionCategory() < rightTransaction.getTransactionCategory())
					{
						return true;
					}
					else
					{
						if (rightTransaction.getTransactionCategory() < leftTransaction.getTransactionCategory())
						{
							return false;
						}
						else
						{
							if (leftTransaction.getTransactionAmount() < rightTransaction.getTransactionAmount())
							{
								return true;
							}
							else
							{
								if (rightTransaction.getTransactionAmount() < leftTransaction.getTransactionAmount())
								{
									return false;
								}
								else
								{
									if (leftTransaction.getTransactionComment() < rightTransaction.getTransactionComment())
									{
										return true;
									}
									else
									{
										if (rightTransaction.getTransactionComment() < leftTransaction.getTransactionComment())
										{
											return false;
										}
										else
										{
											if (leftTransaction.getTransactionCurrency() < rightTransaction.getTransactionCurrency())
											{
												return true;
											}
											else
											{
												if (rightTransaction.getTransactionCurrency() < leftTransaction.getTransactionCurrency())
												{
													return false;
												}
												else
												{
													if (leftTransaction.getTransactionDescription() < rightTransaction.getTransactionDescription())
													{
														return true;
													}
													else
													{
														if (rightTransaction.getTransactionDescription() < leftTransaction.getTransactionDescription())
														{
															return false;
														}
														else
														{
															if (leftTransaction.getTransactionPayee() < rightTransaction.getTransactionPayee())
															{
																return true;
															}
															else
															{
																if (rightTransaction.getTransactionPayee() < leftTransaction.getTransactionPayee())
																{
																	return false;
																}
																else
																{
																	if (leftTransaction.getTransactionTag() < rightTransaction.getTransactionTag())
																	{
																		return true;
																	}
																	else
																	{
																		if (rightTransaction.getTransactionTag() < leftTransaction.getTransactionTag())
																		{
																			return false;
																		}
																		else
																		{
																			if (leftTransaction.getTransactionStatus() < rightTransaction.getTransactionStatus())
																			{
																				return true;
																			}
																			else
																			{
																				if (rightTransaction.getTransactionStatus() < leftTransaction.getTransactionStatus())
																				{
																					return false;
																				}
																				else
																				{
																					if (leftTransaction.getTransactionType() < rightTransaction.getTransactionType())
																					{
																						return true;
																					}
																					else
																					{
																						return false;
																					}
																				}
																			}
																		}
																		
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

std::ostream& operator<<(std::ostream& outputStream, const Transaction& transaction)
{
	return outputStream << transaction.getTransactionTime() << '\t' <<
		transaction.getTransactionAccountFrom() << '\t' <<
		transaction.getTransactionCategory() << '\t' <<
		transaction.getTransactionAmount() << ' ' <<
		transaction.getTransactionCurrency().getCurrencyName();
}