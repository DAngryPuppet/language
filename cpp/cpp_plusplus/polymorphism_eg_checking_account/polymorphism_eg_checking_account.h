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

class BaseDMA
{
public:
	BaseDMA(const char *label = "null",int rating=0);
	BaseDMA(const BaseDMA &bass_DMA);
	virtual ~BaseDMA();
	BaseDMA &operator=(const BaseDMA &bass_DMA);

private:
	char *label_;
	int reting_;
};

class LackDMA :public BaseDMA
{
public:

private:
	char color_[40];
};