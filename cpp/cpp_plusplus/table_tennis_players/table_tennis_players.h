#ifndef __TABLE_TENNIS_PLAYERS_H
#define __TABLE_TENNIS_PLAYERS_H
#include <string>

class TableTenisPlayer
{
public:
	TableTenisPlayer();
	TableTenisPlayer(const std::string first_name, const std::string last_name,const bool has_table)
	{ m_first_name_ = first_name; m_last_name_ = last_name; m_has_table_ = has_table; }
	~TableTenisPlayer();
	void Name() const;
	bool has_tanle() const { return m_has_table_; }
	void reset_table(bool table){ m_has_table_ = table; }
private:
	std::string m_first_name_;
	std::string m_last_name_;
	bool m_has_table_;
};

class RatedPlayer :public TableTenisPlayer
{
public:
	RatedPlayer(unsigned int rating, const std::string first_name, const std::string last_name,const bool has_table);
	RatedPlayer(unsigned int rating, const TableTenisPlayer & tp);
	~RatedPlayer();

	unsigned int rating();
	void rset_rating(unsigned int rating);
private:
	unsigned int rating_;
};


#endif