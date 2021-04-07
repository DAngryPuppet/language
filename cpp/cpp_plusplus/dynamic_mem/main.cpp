#include <iostream>
#include <string>

#include "class_and_dynamic_mem.h"

int main(int argc, char *argv[])
{

	StringBad head_line_1;
	StringBad *head_line_2 = new StringBad("head_line_2");
	StringBad head_line_3 = *head_line_2;
	head_line_1 = *head_line_2;

	delete head_line_2;

	head_line_1.Show();
	head_line_3.Show();


	return 0;
}