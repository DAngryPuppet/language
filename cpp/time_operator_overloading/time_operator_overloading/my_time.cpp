#include <iostream>
#include <string>

#include "my_time.h"

MyTime::MyTime()
{
	hours_ = minutes_ = 0;
}

MyTime::MyTime(int hours, int minutes)
{
	hours_ = hours;
	minutes_ = minutes;
}

void MyTime::AddMin(int minutes)
{
	minutes_ += minutes;
	hours_ += minutes_ / 60;
	minutes_ %= 60;
}

void MyTime::AddHours(int hours)
{
	hours_ += hours;
}

void MyTime::Reset(int hours, int minutes)
{
	hours_ = hours;
	minutes_ = minutes;
}

MyTime MyTime::Sum(const MyTime &time) const
{
	MyTime sum;
	sum.minutes_ = minutes_ + time.minutes_;
	sum.hours_ = (sum.minutes_ / 60) + time.hours_;
	sum.minutes_ %= 60;

	return sum;
}

void MyTime::Show() const
{
	std::cout << hours_ << "hours, " << minutes_ << "minutes, " << std::endl;
}