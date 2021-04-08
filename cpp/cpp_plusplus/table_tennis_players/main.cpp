#include <iostream>
#include "table_tennis_players.h"


int main(int argc, char *argv[])
{
	using std::cout;

	TableTenisPlayer player1{ "Chuck","Blizzard",true };
	TableTenisPlayer player2{ "Tara","Boomdea",false };

	RatePlayer rate_player1{ 10, "Chuck","Blizzard",true };
	RatePlayer rate_player2{ 11, player2 };

	TableTenisPlayer *p_player1 = NULL;
	TableTenisPlayer &r_player2 = rate_player2;

	p_player1 = &rate_player1;

	player1.Name();
	if (player1.has_tanle())
	{
		cout << " :has a table" << "\n";
	}
	else
	{
		cout << " :has't a table" << "\n";
	}

	player2.Name();
	if (player2.has_tanle())
	{
		cout << " :has a table" << "\n";
	}
	else
	{
		cout << " :has't a table" << "\n";
	}

	rate_player1.Name();
	if (rate_player1.has_tanle())
	{
		cout << " :has a table" << "\n";
	}
	else
	{
		cout << " :has't a table" << "\n";
	}
	cout<<"rating "<< rate_player1.rating()<<"\n";

	rate_player2.Name();
	if (rate_player2.has_tanle())
	{
		cout << " :has a table" << "\n";
	}
	else
	{
		cout << " :has't a table" << "\n";
	}
	cout << "rating " << rate_player2.rating() << "\n";

	p_player1->Name();
	if (p_player1->has_tanle())
	{
		cout << " :point, has a table" << "\n";
	}
	else
	{
		cout << " :point, has't a table" << "\n";
	}
	cout << "point, rating " << rate_player1.rating() << "\n"; /*The base class method calls the base class only.*/

	r_player2.Name();
	if (r_player2.has_tanle())
	{
		cout << " :reference, has a table" << "\n";
	}
	else
	{
		cout << " :reference, has't a table" << "\n";
	}
	cout << "reference, rating " << rate_player2.rating() << "\n"; /*The base class method calls the base class only.*/

	return 0;
}