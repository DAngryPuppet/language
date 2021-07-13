#pragma once

class Tv
{
public:
	friend class Remote;//Remote can access Tv private parts.
	enum {OFF,ON};
	enum {MIN_VAL,MAX_VAL = 20};
	enum {ANTENNA,CABLE};
	enum {TV,DVD};

	Tv(int state=OFF, int max_channel=20) 
		:m_state(state), m_volume(5),m_max_channel(max_channel)
		,m_channel(2),m_mode(CABLE),m_input(TV)
	{}

	void OnOff()
	{
		m_state = (ON == m_state) ? OFF : ON;
	}

	bool IsOn()const { return (ON == m_state); }
	bool VolUp();
	bool VolDown();
	bool ChanUp();
	bool ChanDown();
	void set_mode() { m_mode == (ANTENNA == m_mode) ? CABLE : ANTENNA; }
	void set_input() { m_input == (TV == m_input) ? DVD : TV; }
	void ShowSetting()const; //Display all setting.

private:
	int m_state;
	int m_volume;
	int m_max_channel;
	int m_channel;
	int m_mode;
	int m_input;
};

class Remote
{
public:
	Remote(int mode=Tv::TV) :m_mode(mode) {}
	bool VolUp(Tv& t) { return t.VolUp(); }
	bool VolDown(Tv& t) { return t.VolDown(); }
	bool ChanUp(Tv& t) { return t.ChanUp(); }
	bool ChanDown(Tv& t) { return t.ChanDown(); }
	void set_chan(Tv& t, int cha) { t.m_channel = cha; }
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }
private:
	int m_mode;
};

