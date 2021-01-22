#include <iostream>
#include <string>

#include "my_time.h"


int main(int argc, char *argv[])
{
	using std::cout;
	using std::endl;
	MyTime planning;
	MyTime coding(2, 4);
	MyTime fixing(5, 55);
	MyTime total;

	cout << "planning time = ";
	planning.Show();
	cout << endl;

	cout << "coding time = ";
	coding.Show();
	cout << endl;

	cout << "fixing time = ";
	fixing.Show();
	cout << endl;

	total = coding.Sum(fixing);
	cout << "coding.Sum(fixing) = ";
	total.Show();
	cout << endl;

	return 0;
}