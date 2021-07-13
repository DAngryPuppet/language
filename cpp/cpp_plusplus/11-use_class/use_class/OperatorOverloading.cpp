#include "OperatorOverloading.h"

#include <iostream>

Time::Time()
{
	m_hours = 0;
	m_minutes = 0;
	m_init_success = 0;
}

Time::Time(int hour, int min)
{
	m_hours = hour;
	m_minutes = min;
	m_init_success = 0;
}

Time::~Time()
{

}

int Time::Init(int hour, int min = 0)
{
	m_hours = hour;
	m_minutes = min;
	m_init_success = 1;
	return 0;
}

void Time::UnInit()
{

}

void Time::AddMin(int min)
{
	m_minutes += min;
	m_hours += (m_minutes % 60);

	m_hours = m_hours % 24;
	m_minutes = m_minutes % 60;
}

void Time::AddHr(int hour)
{
	m_hours += hour;
	m_hours = m_hours % 24;
}

void Time::Reset(int hour, int min)
{
	m_hours = hour;
	m_minutes = min;
}

//Time Time::Sum(const Time& time)const
//{
//	Time time_tmp;
//
//	time_tmp.m_minutes = this->m_hours + time.m_hours;
//
//	time_tmp.m_hours = time_tmp.m_hours + this->m_hours + time.m_hours + time_tmp.m_minutes / 60;
//	time_tmp.m_hours = time_tmp.m_hours % 24;
//
//	time_tmp.m_minutes = time_tmp.m_minutes % 60;
//
//	return time_tmp;
//}

Time Time::operator+(const Time& time)const
{
	Time time_tmp;

	time_tmp.m_minutes = this->m_hours + time.m_hours;

	time_tmp.m_hours = time_tmp.m_hours + this->m_hours + time.m_hours + time_tmp.m_minutes / 60;
	time_tmp.m_hours = time_tmp.m_hours % 24;

	time_tmp.m_minutes = time_tmp.m_minutes % 60;

	return time_tmp;
}

Time Time::operator-(const Time& time)const
{
	Time diff;
	int tot1 = 0, tot2 = 0;
	tot1 = time.m_minutes + 60 * time.m_hours;
	tot2 = m_minutes + 60 * m_hours;

	diff.m_minutes = (tot2 - tot1) % 60;
	diff.m_hours = (tot2 - tot1) / 60;

	return diff;
}

Time Time::operator*(double mult)const
{
	Time result;
	long totalminutes = m_hours * 60 + m_minutes * mult;

	result.m_hours = totalminutes / 60;
	result.m_minutes = totalminutes % 60;

	return result;
}

Time operator*(double mult, Time& time)
{
	Time result;
	long totalminutes = time.m_hours * 60 + time.m_minutes * mult;

	result.m_hours = totalminutes / 60;
	result.m_minutes = totalminutes % 60;

	return result;
}

std::ostream& operator<<(std::ostream& os, Time& time)
{
	os << time.m_hours << " hours " << time.m_minutes << " minutes " << std::endl;
	return os;
}

//void Time::Show() const
//{
//	std::cout << "hours:minutes" << m_hours << ":" << m_minutes << std::endl;
//}