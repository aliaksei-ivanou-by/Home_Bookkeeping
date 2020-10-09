#include <string>

namespace Home_Bookkeeping
{
	class DateTime
	{
		// Add class Date and Time
	};

	class Account
	{
	private:
		long long int Account_id;
		std::string Account_name;
	};

	class TransactionType
	{
	private:
		long long int TransactionType_id;
		enum class TransactionType_name
		{
			Income,
			Expences,
			Transfer
		};
	};

	class TransactionStatus
	{
	private:
		long long int TransactionStatus_id;
		enum class TransactionStatus_name
		{
			Cleared,
			Reconciled,
			Void,
			None
		};
	};

	class Description
	{
	private:
		long long int Description_id;
		std::string Description_name;
	public:
		void add_description();
		void edit_description();
		void delete_description();
		long long int fing_description(Description description);
	};

	class Payee
	{
	private:
		long long int Payee_id;
		std::string Payee_name;
	public:
		void add_payee();
		void edit_payee();
		void delete_payee();
		long long int fing_payee(Payee payee);
	};

	class Amount
	{
	private:
		double Amount_value;
	};

	class Currency
	{
	private:
		long long int Currency_id;
		std::string Currency_name;
		std::string Currency_code;
		std::string Currency_sign;
		bool Currency_active;
		CurrencyExchangeRates Currency_rates;
	public:
		void add_currency();
		void edit_currency();
		void delete_currency();
		void set_currency_active();
		void set_currency_passive();
	};

	class CurrencyExchangeRates
	{
	private:
		long long int CurrencyExchangeRates_id;
		Currency CurrencyExchangeRates_from;
		Currency CurrencyExchangeRates_to;
		DateTime CurrencyExchangeRates_date;
		double CurrencyExchangeRates_rate;
	public:
		void add_CurrencyExchangeRates_server();
		void edit_CurrencyExchangeRates_server();
		void delete_CurrencyExchangeRates_server();
		friend class Currency;
	};

	class Category
	{
	private:
		long long int Category_id;
		std::string Category_name;
	public:
		void add_category();
		void edit_category();
		void delete_category();
		class Subcategory
		{
		private:
			long long int Subcategory_id;
			std::string Subcategory_name;
		public:
			void add_subcategory();
			void edit_subcategory();
			void delete_subcategory();
		};
	};

	class Comment
	{
	private:
		long long int Comment_id;
		std::string Comment_name;
	public:
		void add_comment();
		void edit_comment();
		void delete_comment();
		long long int find_comment(Comment comment);

		friend class Transaction;
		friend class TransactionPlanned;
	};

	class Tag
	{
	private:
		long long int Tag_id;
		std::string Tag_name;
	public:
		void add_tag();
		void edit_tag();
		void delete_tag();
		long long int find_tag(Tag tag);
		
		friend class Transaction;
		friend class TransactionPlanned;
	};

	class Transaction
	{
	private:
		long long int Transaction_id;
		DateTime Transaction_date;
		Account Transaction_account;
		TransactionType Transaction_type;
		TransactionStatus Transaction_status;
		Description Transaction_description;
		Payee Transaction_payee;
		Amount Transaction_amount;
		Currency Transaction_currency;
		Category Transaction_category;
		Comment Transaction_comment;
		Tag Transaction_tag;
	public:
		void add_transaction();
		void edit_transaction();
		void delete_transaction();
		ARRAY find_transaction(); // Date_Time
		ARRAY find_transaction(); // Account
		ARRAY find_transaction(); // TransactionType
		ARRAY find_transaction(); // TransactionStatus
		ARRAY find_transaction(); // Description
		ARRAY find_transaction(); // Payee
		ARRAY find_transaction(); // Amount
		ARRAY find_transaction(); // Currency
		ARRAY find_transaction(); // Category
		ARRAY find_transaction(); // Comment
		ARRAY find_transaction(); // Tag
	};

	class TransactionPlanned
	{
	private:
		long long int TransactionPlanned_id;
		DateTime TransactionPlanned_date;
		Account TransactionPlanned_account;
		TransactionType TransactionPlanned_type;
		TransactionStatus TransactionPlanned_status;
		Description TransactionPlanned_description;
		Payee TransactionPlanned_payee;
		Amount TransactionPlanned_amount;
		Currency TransactionPlanned_currency;
		Category TransactionPlanned_category;
		Comment TransactionPlanned_comment;
		Tag TransactionPlanned_tag;
	public:
		void add_transaction_planned();
		void edit_transaction_planned();
		void delete_transaction_planned();
		ARRAY find_transaction_planned(); // Date_Time
		ARRAY find_transaction_planned(); // Account
		ARRAY find_transaction_planned(); // TransactionType
		ARRAY find_transaction_planned(); // TransactionStatus
		ARRAY find_transaction_planned(); // Description
		ARRAY find_transaction_planned(); // Payee
		ARRAY find_transaction_planned(); // Amount
		ARRAY find_transaction_planned(); // Currency
		ARRAY find_transaction_planned(); // Category
		ARRAY find_transaction_planned(); // Comment
		ARRAY find_transaction_planned(); // Tag
	};
}