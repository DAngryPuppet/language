#include <iostream>

#include "tv.h"

int main(int argc, char* argv[])
{
	using std::cout;
	using std::endl;

	Tv s42;
	cout << "Initial setting for 42\"TV:\n";
	s42.ShowSetting();
	s42.OnOff();
	s42.ChanUp();
	cout << "\nAdjusted settings for 42\"TV:\n";
	s42.ChanUp();

	cout << "\nAdjusted settings for 42\"TV:\n";
	s42.ShowSetting();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.VolUp(s42);
	grey.VolUp(s42);
	cout << "\n42\"setting after using remote:\n";
	s42.ShowSetting();

	return 0;
}