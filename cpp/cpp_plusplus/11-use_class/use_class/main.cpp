#include <iostream>
#include <string>

#include "OperatorOverloading.h"

int main(int argc, char* argv[])
{
	Time time_first(10,10);
	Time time_two(20, 20);

	Time time_sum;


	time_first.Show();
	time_two.Show();

	time_sum = time_first+time_two;

	time_sum.Show();

	return 0;
}