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
	transactionComment{ std::make_shared<Comment>(transactionCommentForAdd) },
	transactionCurrency{ std::make_shared<Currency>(transactionCurrencyForAdd) },
	transactionDescription{ std::make_shared<Description>(transactionDescriptionForAdd) },
	transactionPayee{ std::make_shared<Payee>(transactionPayeeForAdd) },
	transactionTag{ std::make_shared<Tag>(transactionTagForAdd) },
	transactionStatus{ std::make_shared<TransactionStatus>(transactionStatusForAdd) },
	transactionType{ std::make_shared<TransactionType>(transactionTypeForAdd) }
{
	if (*transactionType == TransactionType(TransactionTypeEnum::Expence))
	{
		(*transactionAccountFrom).updateAccountAmount(-transactionAmount);
	}
	if (*transactionType == TransactionType(TransactionTypeEnum::Income))
	{
		(*transactionAccountFrom).updateAccountAmount(transactionAmount);
	}
	if (*transactionType == TransactionType(TransactionTypeEnum::Transfer))
	{
		(*transactionAccountFrom).updateAccountAmount(-transactionAmount);
		(*transactionAccountTo).updateAccountAmount(transactionAmount);
	}
}

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
	transactionAccountTo{ std::make_shared<Account>(transactionAccountToForAdd) },
	transactionCategory{ std::make_shared<Category>(transactionCategoryForAdd) },
	transactionAmount{ transactionAmountForAdd },
	transactionComment{ std::make_shared<Comment>(transactionCommentForAdd) },
	transactionCurrency{ std::make_shared<Currency>(transactionCurrencyForAdd) },
	transactionDescription{ std::make_shared<Description>(transactionDescriptionForAdd) },
	transactionPayee{ std::make_shared<Payee>(transactionPayeeForAdd) },
	transactionTag{ std::make_shared<Tag>(transactionTagForAdd) },
	transactionStatus{ std::make_shared<TransactionStatus>(transactionStatusForAdd) },
	transactionType{ std::make_shared<TransactionType>(transactionTypeForAdd) }
{
	if (*transactionType == TransactionType(TransactionTypeEnum::Expence))
	{
		(*transactionAccountFrom).updateAccountAmount(-transactionAmount);
	}
	if (*transactionType == TransactionType(TransactionTypeEnum::Income))
	{
		(*transactionAccountFrom).updateAccountAmount(transactionAmount);
	}
	if (*transactionType == TransactionType(TransactionTypeEnum::Transfer))
	{
		(*transactionAccountFrom).updateAccountAmount(-transactionAmount);
		(*transactionAccountTo).updateAccountAmount(transactionAmount);
	}
}

// Income or Expense
Transaction::Transaction(
	const Account& transactionAccountFromForAdd,
	const Category& transactionCategoryForAdd,
	const double transactionAmountForAdd,
	const Currency& transactionCurrencyForAdd):

	transactionTime{ Time() },
	transactionAccountFrom{ std::make_shared<Account>(transactionAccountFromForAdd) },
	transactionAccountTo{ std::make_shared<Account>(transactionAccountFromForAdd) },
	transactionCategory{ std::make_shared<Category>(transactionCategoryForAdd) },
	transactionAmount{ transactionAmountForAdd },
	transactionComment{ std::make_shared<Comment>(Comment()) },
	transactionCurrency{ std::make_shared<Currency>(transactionCurrencyForAdd) },
	transactionDescription{ std::make_shared<Description>(Description()) },
	transactionPayee{ std::make_shared<Payee>(Payee()) },
	transactionTag{ std::make_shared<Tag>(Tag()) },
	transactionStatus{ std::make_shared<TransactionStatus>(TransactionStatus()) },
	transactionType{ std::make_shared<TransactionType>(TransactionType()) }
{
	if (*transactionType == TransactionType(TransactionTypeEnum::Expence))
	{
		(*transactionAccountFrom).updateAccountAmount(-transactionAmount);
	}
	if (*transactionType == TransactionType(TransactionTypeEnum::Income))
	{
		(*transactionAccountFrom).updateAccountAmount(transactionAmount);
	}
	if (*transactionType == TransactionType(TransactionTypeEnum::Transfer))
	{
		(*transactionAccountFrom).updateAccountAmount(-transactionAmount);
		(*transactionAccountTo).updateAccountAmount(transactionAmount);
	}
}

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
	transactionComment{ std::make_shared<Comment>(Comment()) },
	transactionCurrency{ std::make_shared<Currency>(transactionCurrencyForAdd) },
	transactionDescription{ std::make_shared<Description>(Description()) },
	transactionPayee{ std::make_shared<Payee>(Payee()) },
	transactionTag{ std::make_shared<Tag>(Tag()) },
	transactionStatus{ std::make_shared<TransactionStatus>(TransactionStatus()) },
	transactionType{ std::make_shared<TransactionType>(TransactionType()) }
{
	if (*transactionType == TransactionType(TransactionTypeEnum::Expence))
	{
		(*transactionAccountFrom).updateAccountAmount(-transactionAmount);
	}
	if (*transactionType == TransactionType(TransactionTypeEnum::Income))
	{
		(*transactionAccountFrom).updateAccountAmount(transactionAmount);
	}
	if (*transactionType == TransactionType(TransactionTypeEnum::Transfer))
	{
		(*transactionAccountFrom).updateAccountAmount(-transactionAmount);
		(*transactionAccountTo).updateAccountAmount(transactionAmount);
	}
}

Time Transaction::getTransactionTime() const
{
	return transactionTime;
}

Account Transaction::getTransactionAccountFrom() const
{
	return *transactionAccountFrom;
}

Account Transaction::getTransactionAccountTo() const
{
	return *transactionAccountTo;
}

Category Transaction::getTransactionCategory() const
{
	return *transactionCategory;
}

double Transaction::getTransactionAmount() const
{
	return transactionAmount;
}

double Transaction::getTransactionAccountAmount() const
{
	return (*transactionAccountFrom).getAccountAmount();
}

Comment Transaction::getTransactionComment() const
{
	return *transactionComment;
}

Currency Transaction::getTransactionCurrency() const
{
	return *transactionCurrency;
}

Description Transaction::getTransactionDescription() const
{
	return *transactionDescription;
}

Payee Transaction::getTransactionPayee() const
{
	return *transactionPayee;
}

Tag Transaction::getTransactionTag() const
{
	return *transactionTag;
}

TransactionStatus Transaction::getTransactionStatus() const
{
	return *transactionStatus;
}

TransactionType Transaction::getTransactionType() const
{
	return *transactionType;
}

void Transaction::setTransactionTime(const Time& timeForUpdate)
{
	transactionTime = timeForUpdate;
}

void Transaction::setTransactionAccountFrom(const Account& accountFromForUpdate)
{
	*transactionAccountFrom = accountFromForUpdate;
}

void Transaction::setTransactionAccountTo(const Account& accountToForUpdate)
{
	*transactionAccountTo = accountToForUpdate;
}

void Transaction::setTransactionCategory(const Category& categoryForUpdate)
{
	*transactionCategory = categoryForUpdate;
}

void Transaction::setTransactionComment(const Comment& commentForUpdate)
{
	*transactionComment = commentForUpdate;
}

void Transaction::setTransactionCurrency(const Currency& currencyForUpdate)
{
	*transactionCurrency = currencyForUpdate;
}

void Transaction::setTransactionDescription(const Description& descriptionForUpdate)
{
	*transactionDescription = descriptionForUpdate;
}

void Transaction::setTransactionPayee(const Payee& payeeForUpdate)
{
	*transactionPayee = payeeForUpdate;
}

void Transaction::setTransactionTag(const Tag& tagForUpdate)
{
	*transactionTag = tagForUpdate;
}

void Transaction::setTransactionTransactionStatus(const TransactionStatus& transactionStatusForUpdate)
{
	*transactionStatus = transactionStatusForUpdate;
}

void Transaction::setTransactionTransactionTyoe(const TransactionType& transactionTypeForUpdate)
{
	*transactionType = transactionTypeForUpdate;
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