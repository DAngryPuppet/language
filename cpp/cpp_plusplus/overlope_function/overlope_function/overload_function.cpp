#include <iostream>
#include <string>

struct  Job
{
	char name[64];
	double salary;
	int floor;
};

//Template.
template <typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

//Overload template.
template <typename T>
void Swap(T *a, T *b,int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

//Specific templates.
template <> void Swap<Job>(Job &a, Job &b)
{
	double t1;
	int t2;

	t1 = a.salary;
	t2 = a.floor;


	a.salary = b.salary;
	a.floor = b.floor;

	b.salary = t1;
	b.floor = t2;
}

void Show(int *a,int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		if (i % 10)
		{
			cout << endl;
		}
		cout << a[i];
	}
	cout << endl;
}

const int lim = 8;

int main(int argc, char *argv[])
{

	int a = 10;
	int b = 20;


	std::cout << "before swaping: a:b " << a <<" "<< b << std::endl;

	Swap(a, b);

	std::cout << "after swaping: a:b " << a <<" "<< b << std::endl;

	return 0;
}