#include "table_tennis_players.h"

#include <iostream>

TableTenisPlayer::TableTenisPlayer()
{

}

void TableTenisPlayer::Name() const
{
	std::cout << m_last_name_ << "," << m_first_name_ << std::endl;
}

TableTenisPlayer::~TableTenisPlayer()
{

}


RatePlayer::RatePlayer(unsigned int rating, const std::string first_name, const std::string last_name, const bool has_table)
	:TableTenisPlayer(first_name, last_name, has_table)
{
	rating_ = rating;
}

RatePlayer::RatePlayer(unsigned int rating, const TableTenisPlayer & tp)
	: TableTenisPlayer(tp)
{
	rating_ = rating;
}

RatePlayer::~RatePlayer()
{

}

unsigned int RatePlayer::rating()
{
	return rating_;
}

void RatePlayer::rset_rating(unsigned int rating)
{
	rating_ = rating;
}