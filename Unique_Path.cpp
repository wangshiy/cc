#include<iostream>

using namespace std;

typedef int* Intptr;

int uniquePaths(int m, int n) 
{
	// Multi-dimensional dynamic array
	Intptr *a = new Intptr[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}

	if (m == 0 || n == 0)
	{
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		a[0][i] = 1;
	}

	for (int j = 0; j < m; j++)
	{
		a[j][0] = 1;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			a[i][j] = a[i-1][j] + a[i][j-1];
		}
	}

	return a[m-1][n-1];
}

int main()
{
	int test;
	test = uniquePaths(2,2);
	cout << test << endl;
	return 0;
}