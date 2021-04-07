#pragma once
class StringBad
{
public:
	StringBad(const char *str);
	StringBad();
	~StringBad();
	friend std::ostream &operator<< (std::ostream &os, const StringBad &st);
	StringBad(const StringBad &str);/*copy.*/
	StringBad &operator=(const StringBad &str);/*assignment.*/
	int Show();
private:

	char *str_;
	int len_;
	static int num_strings_;
};