#include "Transaction.h"

Transaction::Transaction(
	Account transactionAccountFromForAdd, Category transactionCategoryForAdd,
	double transactionAmountForAdd,
	Comment transactionCommentForAdd, Currency transactionCurrencyForAdd,
	Description transactionDescriptionForAdd,
	Payee transactionPayeeForAdd, Tag transactionTagForAdd,
	TransactionStatus transactionStatusForAdd, TransactionType transactionTypeForAdd):
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
	Account transactionAccountFromForAdd, Category transactionCategoryForAdd,
	double transactionAmountForAdd,
	Comment transactionCommentForAdd, Currency transactionCurrencyForAdd,
	Description transactionDescriptionForAdd,
	Payee transactionPayeeForAdd, Tag transactionTagForAdd,
	TransactionStatus transactionStatusForAdd, TransactionType transactionTypeForAdd, 
	Account transactionAccountToForAdd):
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
	Account transactionAccountFromForAdd, Category transactionCategoryForAdd,
	double transactionAmountForAdd,
	Currency transactionCurrencyForAdd):
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
	Account transactionAccountFromForAdd, Category transactionCategoryForAdd,
	double transactionAmountForAdd,
	Currency transactionCurrencyForAdd, Account transactionAccountToForAdd) :
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

void Transaction::setTransactionTime(Time&& timeForUpdate)
{
	transactionTime = std::move(timeForUpdate);
}

void Transaction::setTransactionAccount(Account&& accountForUpdate)
{
	transactionAccount = std::move(accountForUpdate);
}

void Transaction::setTransactionCategory(Category&& categoryForUpdate)
{
	transactionCategory = std::move(categoryForUpdate);
}

void Transaction::setTransactionComment(Comment&& commentForUpdate)
{
	transactionComment = std::move(commentForUpdate);
}

void Transaction::setTransactionCurrency(Currency&& currencyForUpdate)
{
	transactionCurrency = std::move(currencyForUpdate);
}

void Transaction::setTransactionDescription(Description&& descriptionForUpdate)
{
	transactionDescription = std::move(descriptionForUpdate);
}

void Transaction::setTransactionPayee(Payee&& payeeForUpdate)
{
	transactionPayee = std::move(payeeForUpdate);
}

void Transaction::setTransactionTag(Tag&& tagForUpdate)
{
	transactionTag = std::move(tagForUpdate);
}

void Transaction::setTransactionTransactionStatus(TransactionStatus&& transactionStatusForUpdate)
{
	transactionStatus = std::move(transactionStatusForUpdate);
}

void Transaction::setTransactionTransactionTyoe(TransactionType&& transactionTypeForUpdate)
{
	transactionType = std::move(transactionTypeForUpdate);
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