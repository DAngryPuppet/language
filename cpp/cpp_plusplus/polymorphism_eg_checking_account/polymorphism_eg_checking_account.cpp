#include <iostream>

#include "polymorphism_eg_checking_account.h"

/*
*
*@author        LiXianxian 12345678901
*
*
*
*    Implementation class.
*/

using std::cout;
using std::endl;

typedef std::ios_base::fmtflags Format;
typedef std::streamsize Precis;
Format SetFormat();
void Restore(Format fmt, Precis prcs);

Brass::Brass(const std::string &full_name , long acct_num , double balance)
{
	full_name_ = full_name;
	acct_num_ = acct_num;
	balance_ = balance;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
	{
		cout << "Negative deposit not allow;-"
			<< "deposit is cancelled;" << endl;
	}

	balance_ += amt;
}

void Brass::Withdraw(double amt)
{
	Format initial_state = SetFormat();
	Precis prec = cout.precision(2);

	if (amt < 0)
	{
		cout << "Withdraw amount must be positive;"
			<< "withdraw canceled" << endl;
	}
	else if (amt <= balance_)
	{
		balance_ -= amt;
	}
	else
	{
		cout << "Withdraw amount of $" << amt
			<< "exceeds your balance\n"
			<< "withdraw canceled" << endl;
	}
	
	Restore(initial_state,prec);
}

double Brass::Balance()const
{
	return balance_;
}

void Brass::ViewAcct()const
{
	Format initial_state = SetFormat();
	Precis prec = cout.precision(2);
	cout << "full_name " << full_name_ << endl;
	cout << "acct_num " << acct_num_ << endl;
	cout << "blance " << balance_ << endl;
	Restore(initial_state, prec);
}

Brass::~Brass()
{

}

BrassPlus::BrassPlus(const std::string &full_name, long acct_num, double balance, double max_loan, double rate)
	:Brass(full_name,acct_num,balance)
{
	max_loan_ = max_loan;
	rate_ = rate;
	owes_bank_ = 0.0f;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r)
	:Brass(ba)
{
	max_loan_ = ml;
	rate_ = r;
	owes_bank_ = 0.0f;
}

void BrassPlus::ViewAcct() const
{
	Format initial_state = SetFormat();
	Precis prec = cout.precision(2);

	Brass::ViewAcct();
	cout << "max_loan " << max_loan_ << endl;
	cout << "rate " << rate_ << endl;
	cout << "owes_bank " << owes_bank_ << endl;

	Restore(initial_state, prec);
}

void BrassPlus::Withdraw(double amt)
{
	Format initial_state = SetFormat();
	Precis prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
	{
		Brass::Withdraw(amt);
	}
	else if (amt <= (bal + max_loan_ - owes_bank_))
	{
		double advance = amt - bal;
		owes_bank_ += advance*(1.0 + rate_);
		cout<< "Bank advance:$"<< advance << endl;
		cout << "Finance charge:$" << advance*rate_ << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
	{
		cout << "Credit limit exceded Transaction cancelled.\n";
	}

	Restore(initial_state, prec);
}

Format SetFormat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}


void Restore(Format fmt, Precis prcs)
{
	cout.setf(fmt, std::ios_base::floatfield);
	cout.precision(prcs);
}