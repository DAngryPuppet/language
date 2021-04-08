#include "student.h"

#include <iostream>


int main(int argc, char *argv)
{

	Student tom = Student("123456",1.0);

	std::cout << std::endl << tom[0];
}

