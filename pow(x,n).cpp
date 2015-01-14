/*
Problem:
Implement pow(x, n).
*/

#include<iostream>

using namespace std;

double Pow(double x, int n)
{
	double result = 1;

	if (x == 1)
	{
		return 1;
	}
	else if (x == -1 && n%2 == 0)
	{
		return 1;
	}
	else if (x == -1 && n%2 != 0)
	{
		return -1;
	}

	if (n < 0)
	{
		return result = 1/Pow(x, -n);
	}

	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return x;
	}
	else if (n == 2)
	{
		return x*x;
	}

	if (n%2 != 0)
	{
		n--;
		result = result * x * Pow(x,n);
	}
	else
	{
		n = n/2;
		result = Pow((Pow(x,n)),2);
	}

	return result;
}

int main()
{
	double test;
	test = Pow(3,-1);
	cout << test << endl;
	return 0;
}