#include "tv.h"
#include <iostream>
bool Tv::VolUp()
{
	if (m_volume < MAX_VAL)
	{
		++m_volume;
		return true;
	}
	else
	{
		return false;
	}
}

bool Tv::VolDown()
{
	if (m_volume > MIN_VAL)
	{
		--m_volume;
		return true;
	}
	else
	{
		return false;
	}
}

bool Tv::ChanUp()
{
	if (m_channel < m_max_channel)
	{
		++m_channel;
		return true;
	}
	else
	{
		m_channel = 1;
		return true;
	}
}

bool Tv::ChanDown()
{
	if (m_channel >1)
	{
		--m_channel;
		return true;
	}
	else
	{
		m_channel = m_max_channel;
		return true;
	}
}

void Tv::ShowSetting()const
{
	using std::cout;
	using std::endl;
	cout << "TV is " << (m_state == OFF ? "Off" : "On") << endl;
	if (ON == m_state)
	{
		cout << "Volume setting = " << m_volume << endl;
		cout << "Channel setting = " << m_channel << endl;
		cout << "Mode = " << (m_mode == ANTENNA ? "antenna" : "cable") << endl;
		cout << "Input = " << (m_input == TV ? "TV" : "DVD") << endl;
	}
}