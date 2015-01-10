/*
Problem:
********************************************************************************** 
* 
* Given an array and a value, remove all instances of that value in place and return the new length.
* 
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.
* 
*            
**********************************************************************************
*/

#include<iostream>

using namespace std;

int Remove(int a[], int n, int elem)
{
	int i = 0;
	int tail = n-1;
	while(i <= tail)
	{
		if(a[i] == elem)
		{
			a[i] = a[tail];
			tail--;
			continue;// this is very important if omitted the result will be wrong(this is like hold the position)
		}
		i++;
	}
	return (tail+1);
}

int main()
{
	int a[] = {1,2,3,3,3,3,3,4,5,3};
	int test = Remove(a,10,3);
	cout << "New Length:" << test << endl;
	return 0;
}
