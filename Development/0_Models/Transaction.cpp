#include "Transaction.h"

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

	transactionTime{},
	transactionAccount{ transactionAccountFromForAdd },
	transactionCategory{ transactionCategoryForAdd },
	transactionAmount{ transactionAmountForAdd },
	transactionComment{ transactionCommentForAdd },
	transactionCurrency{ transactionCurrencyForAdd },
	transactionDescription{ transactionDescriptionForAdd },
	transactionPayee{ transactionPayeeForAdd },
	transactionTag{ transactionTagForAdd },
	transactionStatus{ transactionStatusForAdd },
	transactionType{ transactionTypeForAdd },
	transactionAccountTo{ transactionAccountFromForAdd }
{}

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

	transactionTime{},
	transactionAccount{ transactionAccountFromForAdd },
	transactionCategory{ transactionCategoryForAdd },
	transactionAmount{ transactionAmountForAdd },
	transactionComment{ transactionCommentForAdd },
	transactionCurrency{ transactionCurrencyForAdd },
	transactionDescription{ transactionDescriptionForAdd },
	transactionPayee{ transactionPayeeForAdd },
	transactionTag{ transactionTagForAdd },
	transactionStatus{ transactionStatusForAdd },
	transactionType{ transactionTypeForAdd },
	transactionAccountTo{ transactionAccountToForAdd }
{}

Transaction::Transaction(
	const Account& transactionAccountFromForAdd,
	const Category& transactionCategoryForAdd,
	const double transactionAmountForAdd,
	const Currency& transactionCurrencyForAdd):

	transactionTime{},
	transactionAccount{ transactionAccountFromForAdd },
	transactionCategory{ transactionCategoryForAdd },
	transactionAmount{ transactionAmountForAdd },
	transactionComment{ },
	transactionCurrency{ transactionCurrencyForAdd },
	transactionDescription{ },
	transactionPayee{ },
	transactionTag{ },
	transactionStatus{ },
	transactionType{ },
	transactionAccountTo{ transactionAccountFromForAdd }
{}

Transaction::Transaction(
	const Account& transactionAccountFromForAdd,
	const Category& transactionCategoryForAdd,
	const double transactionAmountForAdd,
	const Currency& transactionCurrencyForAdd,
	const Account& transactionAccountToForAdd) :

	transactionTime{},
	transactionAccount{ transactionAccountFromForAdd },
	transactionCategory{ transactionCategoryForAdd },
	transactionAmount{ transactionAmountForAdd },
	transactionComment{ },
	transactionCurrency{ transactionCurrencyForAdd },
	transactionDescription{ },
	transactionPayee{ },
	transactionTag{ },
	transactionStatus{ },
	transactionType{ },
	transactionAccountTo{ transactionAccountToForAdd }
{}

Time Transaction::getTransactionTime() const
{
	return transactionTime;
}

Account Transaction::getTransactionAccount() const
{
	return transactionAccount;
}

Category Transaction::getTransactionCategory() const
{
	return transactionCategory;
}

double Transaction::getTransactionAmount() const
{
	return transactionAmount;
}

Comment Transaction::getTransactionComment() const
{
	return transactionComment;
}

Currency Transaction::getTransactionCurrency() const
{
	return transactionCurrency;
}

Description Transaction::getTransactionDescription() const
{
	return transactionDescription;
}

Payee Transaction::getTransactionPayee() const
{
	return transactionPayee;
}

Tag Transaction::getTransactionTag() const
{
	return transactionTag;
}

TransactionStatus Transaction::getTransactionStatus() const
{
	return transactionStatus;
}

TransactionType Transaction::getTransactionType() const
{
	return transactionType;
}

void Transaction::setTransactionTime(const Time& timeForUpdate)
{
	transactionTime = timeForUpdate;
}

void Transaction::setTransactionAccount(const Account& accountForUpdate)
{
	transactionAccount = accountForUpdate;
}

void Transaction::setTransactionCategory(const Category& categoryForUpdate)
{
	transactionCategory = categoryForUpdate;
}

void Transaction::setTransactionComment(const Comment& commentForUpdate)
{
	transactionComment = commentForUpdate;
}

void Transaction::setTransactionCurrency(const Currency& currencyForUpdate)
{
	transactionCurrency = currencyForUpdate;
}

void Transaction::setTransactionDescription(const Description& descriptionForUpdate)
{
	transactionDescription = descriptionForUpdate;
}

void Transaction::setTransactionPayee(const Payee& payeeForUpdate)
{
	transactionPayee = payeeForUpdate;
}

void Transaction::setTransactionTag(const Tag& tagForUpdate)
{
	transactionTag = tagForUpdate;
}

void Transaction::setTransactionTransactionStatus(const TransactionStatus& transactionStatusForUpdate)
{
	transactionStatus = transactionStatusForUpdate;
}

void Transaction::setTransactionTransactionTyoe(const TransactionType& transactionTypeForUpdate)
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
			if (leftTransaction.getTransactionAccount() < rightTransaction.getTransactionAccount())
			{
				return true;
			}
			else
			{
				if (rightTransaction.getTransactionAccount() < leftTransaction.getTransactionAccount())
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
		transaction.getTransactionAccount() << '\t' <<
		transaction.getTransactionCategory() << '\t' <<
		transaction.getTransactionAmount() << ' ' <<
		transaction.getTransactionCurrency().getCurrencyName();
}