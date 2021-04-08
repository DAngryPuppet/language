#include <cstring>
#include <iostream>

#include "class_and_dynamic_mem.h"

int StringBad::num_strings_ = 0;

StringBad::StringBad(const char *str)
{
	len_ = strlen(str);
	str_ = new char[len_+1];
	std::strcpy(str_, str);
	++num_strings_;

	std::cout << "num string " << num_strings_ << std::endl;
}

StringBad::StringBad()
{
	len_ = 4;
	str_ = new char[len_ + 1];
	std::strcpy(str_, "C++");
	++num_strings_;

	std::cout << "num string " << num_strings_ << std::endl;
}

StringBad::~StringBad()
{
	std::cout << " \" "<< str_ <<"\"" << "object deleted" << std::endl;
	--num_strings_;
	std::cout << "num string left "<<num_strings_ << std::endl;
	delete str_;
}

int StringBad::Show()
{
	std::cout << "str " << str_ << std::endl;
	return 0;
}

std::ostream &operator<< (std::ostream &os, const StringBad &st)
{
	os << st.str_;
	return os;
}

StringBad::StringBad(const StringBad &str)/*deep copy.*/
{
	
	++num_strings_;
	len_ = str.len_;
	str_ = new char[len_+1];
	std::strcpy(str_, str.str_);
	std::cout << "num string left " << num_strings_ << std::endl;
	
}

StringBad &StringBad::operator=(const StringBad &str)/*assignment operator invoked.*/
{
	if (this == &str)
	{
		return *this;
	}
	delete[] str_;/*free old string.*/

	len_ = str.len_;
	str_ = new char[len_ + 1];/*get space for new string.*/
	std::strcpy(str_, str.str_);/*copy the string.*/

	return *this;/*return reference to incoking object.*/
}

/*
*@brief        Overloading assignment operator invoked.
*/
StringBad &StringBad::operator=(const char *s)
{
	delete[] str_;
	len_ = std::strlen(s);
	str_ = new char[len_ + 1];
	std::strcpy(str_, s);

	return *this;
}