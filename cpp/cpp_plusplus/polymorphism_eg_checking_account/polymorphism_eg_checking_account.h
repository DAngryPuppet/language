/*
* 
*@author        LiXianxian 12345678901
*
*
*
*    Many States to achieve and practice.
*/



#pragma once
#include <string>

/*
* Bank checking account.
*
* Sampple usage:
* Brass brass={"brass",1,1.0};
* std::cout<<brass.ViewAcct();
*
*/

class Brass
{
public :
	Brass(const std::string &full_name = "NullBody", long acct_num = -1, double balance = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance()const;
	virtual void ViewAcct()const;
	double Preferential();
	double SetPreferential();
	double SetPreferential(double preferential);
	virtual ~Brass();

private:
	std::string full_name_;
	long acct_num_;
	double balance_;
	double preferential_;
};


/*
* Bank checking account with an overdraf.
*
* Sampple usage:
* BrassPlus brass_plus={"brass_plus",1,1.0,500,0.11125};
* std::cout<<brass_plus.ViewAcct();
*
*/
class BrassPlus :public Brass
{
public:
	BrassPlus(const std::string &full_name = "NullBody", long acct_num = -1, double balance = 0.0, double max_loan = 500, double rate = 0.11125);
	BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { max_loan_ = m; }
	void ResetRate(double r) { rate_ = r; }
	void ResetOwes() { owes_bank_ = 0; }
	double SetPreferential(double preferential);
private:
	double max_loan_;
	double rate_;
	double owes_bank_;
};

/*
* Base Class Using DMA.
*/

class AcctABC
{
protected :
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};

	const std::string &FullName()const { return full_name_; }
	long AcctNum()const { return acct_num_; }
	Formatting SetFormat()const;
	void Restore(Formatting &f)const;

public:
	AcctABC(std::string full_name = "Nullbody",long acct_num = 1,double balance = 0.0f);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;
	double Balance()const { return balance_; }
	virtual void ViewAcct()const = 0;
	virtual ~AcctABC() {};

private:
	std::string full_name_;
	long acct_num_;
	double balance_;
};

class BrassEx :public AcctABC
{
public:
	BrassEx(const std::string &s = "Nullbody", long an = -1, double bal = 0.0f)
		:AcctABC(s, an, bal)
	{}

	virtual void Withdraw(double amt);
	virtual void ViewAcct()const;
	virtual ~BrassEx() {};
};

class BrassPlusEx :public AcctABC
{

public:
	BrassPlusEx(const std::string &s = "Nullbody", long an = -1, double bal = 0.0f
		, double max_loan = 0.0f, double rate = 0.0f, double owes_bank = 0.0f);
	virtual void Withdraw(double amt);
	virtual void ViewAcct()const;

	void ResetMax(double m) { max_loan_ = m; }
	void ResetRate(double r) { rate_ = r; }
	void ResetOwes() { owes_bank_ = 0; }

private:
	double max_loan_;
	double rate_;
	double owes_bank_;
};
