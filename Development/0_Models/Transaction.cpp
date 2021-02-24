#include "Transaction.h"

// Constructor with the setting of the account from, category, amount, comment, currency, 
// description, payee, tag, transaction status, transaction type(income or expense)
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

// Constructor with the setting of the account from, account to, category, amount, comment, currency, 
// description, payee, tag, transaction status, transaction type (transfer)
Transaction::Transaction(
	const Account& transactionAccountFromForAdd,
	const Account& transactionAccountToForAdd,
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

// Constructor with the setting of the account from, category, amount (income or expense)
Transaction::Transaction(
	const Account& transactionAccountFromForAdd,
	const Category& transactionCategoryForAdd,
	const double transactionAmountForAdd):

	transactionTime{ Time() },
	transactionAccountFrom{ std::make_shared<Account>(transactionAccountFromForAdd) },
	transactionAccountTo{ transactionAccountFrom },
	transactionCategory{ std::make_shared<Category>(transactionCategoryForAdd) },
	transactionAmount{ transactionAmountForAdd },
	transactionAccountFromCurrentAmount{ 0 },
	transactionAccountToCurrentAmount{ 0 },
	transactionComment{ std::make_shared<Comment>(Comment()) },
	transactionCurrency{ std::make_shared<Currency>(Currency()) },
	transactionDescription{ std::make_shared<Description>(Description()) },
	transactionPayee{ std::make_shared<Payee>(Payee()) },
	transactionTag{ std::make_shared<Tag>(Tag()) },
	transactionStatus{ std::make_shared<TransactionStatus>(TransactionStatus()) },
	transactionType{ std::make_shared<TransactionType>(TransactionType()) }
{}

// Constructor with the setting of the account from, account to, category, amount (transfer)
Transaction::Transaction(
	const Account& transactionAccountFromForAdd,
	const Account& transactionAccountToForAdd,
	const Category& transactionCategoryForAdd,
	const double transactionAmountForAdd):

	transactionTime{},
	transactionAccountFrom{ std::make_shared<Account>(transactionAccountFromForAdd) },
	transactionAccountTo{ std::make_shared<Account>(transactionAccountToForAdd) },
	transactionCategory{ std::make_shared<Category>(transactionCategoryForAdd) },
	transactionAmount{ transactionAmountForAdd },
	transactionAccountFromCurrentAmount{ 0 },
	transactionAccountToCurrentAmount{ 0 },
	transactionComment{ std::make_shared<Comment>(Comment()) },
	transactionCurrency{ std::make_shared<Currency>(Currency()) },
	transactionDescription{ std::make_shared<Description>(Description()) },
	transactionPayee{ std::make_shared<Payee>(Payee()) },
	transactionTag{ std::make_shared<Tag>(Tag()) },
	transactionStatus{ std::make_shared<TransactionStatus>(TransactionStatus()) },
	transactionType{ std::make_shared<TransactionType>(TransactionType(TransactionTypeEnum::Transfer)) }
{}

// Constructor copy
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

// Class member function. Get the time of the transaction
Time Transaction::getTransactionTime() const
{
	return transactionTime;
}

// Class member function. Get the account from of the transaction
Account Transaction::getTransactionAccountFrom() const
{
	return *transactionAccountFrom;
}

// Class member function. Get the account to of the transaction
Account Transaction::getTransactionAccountTo() const
{
	return *transactionAccountTo;
}

// Class member function. Get the category of the transaction
Category Transaction::getTransactionCategory() const
{
	return *transactionCategory;
}

// Class member function. Get the amount of the transaction
double Transaction::getTransactionAmount() const
{
	return transactionAmount;
}

// Class member function. Get the current amount of the account from of the transaction
double Transaction::getTransactionAccountFromCurrentAmount() const
{
	return transactionAccountFromCurrentAmount;
}

// Class member function. Get the current amount of the account to of the transaction
double Transaction::getTransactionAccountToCurrentAmount() const
{
	return transactionAccountToCurrentAmount;
}

// Class member function. Get the lastest amount of the account from of the transaction
double Transaction::getTransactionAccountFromLastAmount() const
{
	return (*transactionAccountFrom).getAccountAmount();
}

// Class member function. Get the lastest amount of the account to of the transaction
double Transaction::getTransactionAccountToLastAmount() const
{
	return (*transactionAccountTo).getAccountAmount();
}

// Class member function. Get the comment of the transaction
Comment Transaction::getTransactionComment() const
{
	return *transactionComment;
}

// Class member function. Get the currency of the transaction
Currency Transaction::getTransactionCurrency() const
{
	return *transactionCurrency;
}

// Class member function. Get the description of the transaction
Description Transaction::getTransactionDescription() const
{
	return *transactionDescription;
}

// Class member function. Get the payee of the transaction
Payee Transaction::getTransactionPayee() const
{
	return *transactionPayee;
}

// Class member function. Get the tag of the transaction
Tag Transaction::getTransactionTag() const
{
	return *transactionTag;
}

// Class member function. Get the transaction status of the transaction
TransactionStatus Transaction::getTransactionStatus() const
{
	return *transactionStatus;
}

// Class member function. Get the transaction type of the transaction
TransactionType Transaction::getTransactionType() const
{
	return *transactionType;
}

// Class member function. Get the shared pointer to the account from of the transaction
std::shared_ptr<Account> Transaction::getTransactionAccountPtrFrom() const
{
	return transactionAccountFrom;
}

// Class member function. Get the shared pointer to the account to of the transaction
std::shared_ptr<Account> Transaction::getTransactionAccountPtrTo() const
{
	return transactionAccountTo;
}

// Class member function. Get the shared pointer to the category of the transaction
std::shared_ptr<Category> Transaction::getTransactionCategoryPtr() const
{
	return transactionCategory;
}

// Class member function. Get the shared pointer to the comment of the transaction
std::shared_ptr<Comment> Transaction::getTransactionCommentPtr() const
{
	return transactionComment;
}

// Class member function. Get the shared pointer to the currency of the transaction
std::shared_ptr<Currency> Transaction::getTransactionCurrencyPtr() const
{
	return transactionCurrency;
}

// Class member function. Get the shared pointer to the description of the transaction
std::shared_ptr<Description> Transaction::getTransactionDescriptionPtr() const
{
	return transactionDescription;
}

// Class member function. Get the shared pointer to the payee of the transaction
std::shared_ptr<Payee> Transaction::getTransactionPayeePtr() const
{
	return transactionPayee;
}

// Class member function. Get the shared pointer to the tag of the transaction
std::shared_ptr<Tag> Transaction::getTransactionTagPtr() const
{
	return transactionTag;
}

// Class member function. Get the shared pointer to the transaction status of the transaction
std::shared_ptr<TransactionStatus> Transaction::getTransactionStatusPtr() const
{
	return transactionStatus;
}

// Class member function. Get the shared pointer to the transaction type of the transaction
std::shared_ptr<TransactionType> Transaction::getTransactionTypePtr() const
{
	return transactionType;
}

// Class member function. Set the time of the transaction
void Transaction::setTransactionTime(const Time& timeForUpdate)
{
	transactionTime = timeForUpdate;
}

// Class member function. Set the account from of the transaction
void Transaction::setTransactionAccountFrom(const Account& accountFromForUpdate)
{
	*transactionAccountFrom = accountFromForUpdate;
}

// Class member function. Set the account to of the transaction
void Transaction::setTransactionAccountTo(const Account& accountToForUpdate)
{
	*transactionAccountTo = accountToForUpdate;
}

// Class member function. Set the category of the transaction
void Transaction::setTransactionCategory(const Category& categoryForUpdate)
{
	*transactionCategory = categoryForUpdate;
}

// Class member function. Set the amount of the transaction
void Transaction::setTransactionAmount(const double amountForUpdate)
{
	transactionAmount = amountForUpdate;
}

// Class member function. Set the current amount of the account from of the transaction
void Transaction::setTransactionAccountFromCurrentAmount(const double amountForUpdate)
{
	transactionAccountFromCurrentAmount = amountForUpdate;
}

// Class member function. Set the current amount of the account to of the transaction
void Transaction::setTransactionAccountToCurrentAmount(const double amountForUpdate)
{
	transactionAccountToCurrentAmount = amountForUpdate;
}

// Class member function. Set the lastest amount of the account from of the transaction
void Transaction::setTransactionAccountFromLastAmount(const double amountForUpdate)
{
	(*transactionAccountFrom).setAccountAmount(amountForUpdate);
}

// Class member function. Set the lastest amount of the account to of the transaction
void Transaction::setTransactionAccountToLastAmount(const double amountForUpdate)
{
	(*transactionAccountTo).setAccountAmount(amountForUpdate);
}

// Class member function. Set the comment of the transaction
void Transaction::setTransactionComment(const Comment& commentForUpdate)
{
	*transactionComment = commentForUpdate;
}

// Class member function. Set the currency of the transaction
void Transaction::setTransactionCurrency(const Currency& currencyForUpdate)
{
	*transactionCurrency = currencyForUpdate;
}

// Class member function. Set the description of the transaction
void Transaction::setTransactionDescription(const Description& descriptionForUpdate)
{
	*transactionDescription = descriptionForUpdate;
}

// Class member function. Set the payee of the transaction
void Transaction::setTransactionPayee(const Payee& payeeForUpdate)
{
	*transactionPayee = payeeForUpdate;
}

// Class member function. Set the tag of the transaction
void Transaction::setTransactionTag(const Tag& tagForUpdate)
{
	*transactionTag = tagForUpdate;
}

// Class member function. Set the transaction status of the transaction
void Transaction::setTransactionTransactionStatus(const TransactionStatus& transactionStatusForUpdate)
{
	*transactionStatus = transactionStatusForUpdate;
}

// Class member function. Set the transaction type of the transaction
void Transaction::setTransactionTransactionType(const TransactionType& transactionTypeForUpdate)
{
	*transactionType = transactionTypeForUpdate;
}

// Class member function. Set the shared pointer to the account from of the transaction
void Transaction::setTransactionAccountPtrFrom(std::shared_ptr<Account> accountFromForUpdate)
{
	transactionAccountFrom = accountFromForUpdate;
}

// Class member function. Set the shared pointer to the account to of the transaction
void Transaction::setTransactionAccountPtrTo(std::shared_ptr<Account> accountFromForUpdate)
{
	transactionAccountTo = accountFromForUpdate;
}

// Class member function. Set the shared pointer to the category of the transaction
void Transaction::setTransactionCategoryPtr(std::shared_ptr<Category> categoryForUpdate)
{
	transactionCategory = categoryForUpdate;
}

// Class member function. Set the shared pointer to the comment of the transaction
void Transaction::setTransactionCommentPtr(std::shared_ptr<Comment> commentForUpdate)
{
	transactionComment = commentForUpdate;
}

// Class member function. Set the shared pointer to the currency of the transaction
void Transaction::setTransactionCurrencyPtr(std::shared_ptr<Currency> currencyForUpdate)
{
	transactionCurrency = currencyForUpdate;
}

// Class member function. Set the shared pointer to the description of the transaction
void Transaction::setTransactionDescriptionPtr(std::shared_ptr<Description> descriptionForUpdate)
{
	transactionDescription = descriptionForUpdate;
}

// Class member function. Set the shared pointer to the payee of the transaction
void Transaction::setTransactionPayeePtr(std::shared_ptr<Payee> payeeForUpdate)
{
	transactionPayee = payeeForUpdate;
}

// Class member function. Set the shared pointer to the tag of the transaction
void Transaction::setTransactionTagPtr(std::shared_ptr<Tag> tagForUpdate)
{
	transactionTag = tagForUpdate;
}

// Class member function. Set the shared pointer to the transaction status of the transaction
void Transaction::setTransactionTransactionStatusPtr(std::shared_ptr<TransactionStatus> transactionStatusForUpdate)
{
	transactionStatus = transactionStatusForUpdate;
}

// Class member function. Set the shared pointer to the transaction type of the transaction
void Transaction::setTransactionTransactionTypePtr(std::shared_ptr<TransactionType> transactionTypeForUpdate)
{
	transactionType = transactionTypeForUpdate;
}

// Class member function. Copy assignment operator
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
	return *this;
}

// Class member function. Operator < for sorting transactions
bool operator<(const Transaction& leftTransaction, const Transaction& rightTransaction)
{
	if (leftTransaction.getTransactionTime() < rightTransaction.getTransactionTime())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Class member function. Print transaction
std::ostream& operator<<(std::ostream& outputStream, const Transaction& transaction)
{
	return outputStream << transaction.getTransactionTime() << '\t' <<
		transaction.getTransactionAccountFrom() << '\t' <<
		transaction.getTransactionCategory() << '\t' <<
		transaction.getTransactionAmount() << ' ' <<
		transaction.getTransactionCurrency().getCurrencyName();
}