#pragma once
#include <string>
#include <valarray>


class Student
{
public:
	typedef std::valarray<double> ArrayDb;

	Student() :name_("Null student"), scores_() {}
	explicit Student(const std::string &s)
		:name_(s), scores_()
	{

	}
	explicit Student(size_t n)
		:name_("NULL Student"),scores_(n)
	{}
	Student(const std::string &s, size_t n)
		:name_(s), scores_(n)
	{

	}
	Student(const std::string &s, const ArrayDb &a)
		:name_(s), scores_(a)
	{

	}

	Student(const char *str, const double *pd, size_t n)
		:name_(str), scores_(pd,n)
	{

	}

	~Student();

	double Averange() const;
	const std::string Name() const;
	double &operator[](int i);
	double operator[](int i) const;
	friend std::istream &operator>>(std::istream &is, Student &stu);
	friend std::istream &getline(std::istream &is, Student &stu);
	friend std::ostream &operator<<(std::ostream, const Student &stu);

private:
	std::string name_;
	ArrayDb scores_;
	std::ostream &ArrOut(std::ostream &os) const;
};