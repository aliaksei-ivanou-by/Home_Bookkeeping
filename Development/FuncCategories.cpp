#include "FuncCategories.h"

// Transactions
void select_transactions_by_account(Accounts account);
// void select_transactions_by_date(DateTime date_time);
void select_transactions_by_type(TransactionTypes transaction_type);
void select_transactions_by_status(TransactionStatuses transaction_status);
void select_transactions_by_description(Descriptions description);
void select_transactions_by_payee(Payees payee);
void select_transactions_by_amount(double amount);
void select_transactions_by_currency(Currencies currency);
void select_transactions_by_comment(Comments comment);
void select_transactions_by_tag(Tags tag);

// Planned transactions
void select_planned_transactions_by_account(Accounts account);
// void select_planned_transactions_by_date(DateTime date_time);
void select_planned_transactions_by_type(TransactionTypes transaction_type);
void select_planned_transactions_by_status(TransactionStatuses transaction_status);
void select_planned_transactions_by_description(Descriptions description);
void select_planned_transactions_by_payee(Payees payee);
void select_planned_transactions_by_amount(double amount);
void select_planned_transactions_by_currency(Currencies currency);
void select_planned_transactions_by_comment(Comments comment);
void select_planned_transactions_by_tag(Tags tag);

