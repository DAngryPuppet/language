#include "student.h"

Student::~Student()
{
	name_ = "null";
	scores_ = 0.0;
}

double Student::Averange() const
{
	if (scores_.size() > 0)
	{
		return scores_.sum() / scores_.size();
	}
	else
	{
		return 0;
	}
}
const std::string Student::Name() const
{
	return name_;
}

double &Student::operator[](int i)
{
	return scores_[i];
}

double Student::operator[](int i) const
{
	return scores_[i];
}

std::ostream &Student::ArrOut(std::ostream &os) const
{
	int i = 0;
	int lim = scores_.size();
	if (lim > 0)
	{
		for (i = 0; i < scores_.size(); i++)
		{
			os << scores_[i] << "";
			if (i % 5 == 4)
			{
				os << std::endl;
			}
		}

		if (i % 5 != 0)
		{
			os << std::endl;
		}
	}
	else
	{
		os << "empty array ";
	}

	return os;
}

std::istream &operator>>(std::istream &is, Student &stu)
{
	is >> stu.name_;
	return is;
}

std::istream &getline(std::istream &is, Student &stu)
{
	 getline(is, stu.name_);
	 return is;
}

std::ostream &operator<<(std::ostream os, const Student &stu)
{
	os << "Scores for " << stu.name_ << ":\n";
	stu.ArrOut(os);
	return os;
}