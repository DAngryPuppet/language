#include <iostream>
#include <string>

#include "polymorphism_eg_checking_account.h"

const int kClients = 2;

void UserABC();

int main(int argc, char *argv[])
{
	using std::cin;
	using std::cout;
	using std::endl;

	Brass *p_clients[kClients] = {nullptr};

	std::string temp;
	long temp_num = 0;
	double temp_balance = 0.0f;
	char kind = 0;

	for (int i = 0; i < kClients; i++)
	{
		cout << "Enter client's account number: '";
		getline(cin, temp);
		cout << "Enter opening balance: $";
		cin >> temp_num;
		cout << "Enter 1 for Barss Account or "
			<< "2 for BassPlus Account: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
		{
			cout << "Enter either 1 or 2" << endl;
		}

		if ('1' == kind)
		{
			p_clients[i] = new Brass(temp, temp_num, temp_balance);
		}
		else
		{
			double t_max = 0.0f, t_rate = 0.0f;
			cout << "Enter the overdraf limit: $";
			cin >> t_max;
			cout << "Enter the interest rate "
				<< "as a decimal fraction ";
			cin >> t_rate;
			p_clients[i] = new BrassPlus(temp, temp_num, temp_balance, t_max, t_rate);
		}

		while (cin.get() != '\n')
		{
			continue;
		}
	}

	cout << endl;

	for (int i = 0; i < kClients; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < kClients; i++)
	{
		delete p_clients[i];
	}

	UserABC();

	cout << "Done.\n";

	return 0;
}

void UserABC()
{
	using std::cin;
	using std::cout;
	using std::endl;

	AcctABC *p_clients[kClients] = { nullptr };

	std::string temp;
	long temp_num = 0;
	double temp_balance = 0.0f;
	char kind = 0;

	for (int i = 0; i < kClients; i++)
	{
		cout << "Enter client's account number: '";
		getline(cin, temp);
		cout << "Enter opening balance: $";
		cin >> temp_num;
		cout << "Enter 1 for Barss Account or "
			<< "2 for BassPlus Account: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
		{
			cout << "Enter either 1 or 2" << endl;
		}

		if ('1' == kind)
		{
			p_clients[i] = new BrassEx(temp, temp_num, temp_balance);
		}
		else
		{
			double t_max = 0.0f, t_rate = 0.0f;
			cout << "Enter the overdraf limit: $";
			cin >> t_max;
			cout << "Enter the interest rate "
				<< "as a decimal fraction ";
			cin >> t_rate;
			p_clients[i] = new BrassPlusEx(temp, temp_num, temp_balance, t_max, t_rate);
		}

		while (cin.get() != '\n')
		{
			continue;
		}
	}

	cout << endl;

	for (int i = 0; i < kClients; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < kClients; i++)
	{
		delete p_clients[i];
	}

	cout << "Done.\n";

	return ;
}