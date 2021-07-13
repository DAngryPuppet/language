#include <iostream>
#include <string>

#include "OperatorOverloading.h"

int main(int argc, char* argv[])
{
	Time time_first(10,10);
	Time time_two(20, 20);

	Time time_sum;


	//time_first.Show();
	//time_two.Show();
	//std::cout << time_first;
	//std::cout << time_two;
	std::cout << "time_first " << time_first << "Tuesday" << std::endl;
	std::cout << "time_two " << time_first << "Tuesday" << std::endl;
	time_sum = time_first+time_two;

	//time_sum.Show();
	//std::cout << time_sum;
	std::cout << "time_sum " << time_first << "Tuesday" << std::endl;
	return 0;
}