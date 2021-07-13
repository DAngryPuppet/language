#pragma once
#include <ostream>

class Time
{
public:
	Time();
	Time(int hour, int min = 0);
	~Time();
	int Init(int hour, int min = 0);
	void UnInit();

	void AddMin(int min = 0);
	void AddHr(int hour = 0);
	void Reset(int hour = 0, int min = 0);
	//Time Sum(const Time& time)const;
	Time operator+(const Time& time)const;
	Time operator-(const Time& time)const;
	Time operator*(double mult)const;
	friend Time operator*(double mult, const Time& time);
	friend std::ostream& operator<<(std::ostream& os, const Time& time);
	//void Show() const;

private:
	int m_hours;
	int m_minutes;
	int m_init_success;
};


