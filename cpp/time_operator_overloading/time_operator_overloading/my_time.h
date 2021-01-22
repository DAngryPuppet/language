#ifndef __MY_TIME_H
#define __MY_TIME_H

class MyTime
{

public:
	MyTime();
	MyTime(int hours, int minutes);
	void AddMin(int minutes);
	void AddHours(int hours);
	void Reset(int hours, int minutes);
	MyTime Sum(const MyTime &time) const;
	void Show() const;

private:
	int hours_;
	int minutes_;
};

#endif