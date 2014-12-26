/*Problem:
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/*Solution:
O(n2) runtime, O(1) space – Brute force:

The brute force approach is simple. Loop through each element x and find if there is another value that equals to target – x. As finding another value requires looping through the rest of array, its runtime complexity is O(n2).

O(n) runtime, O(n) space – Hash table:

We could reduce the runtime complexity of looking up a value to O(1) using a hash map that maps a value to its index.
*/

#include <iostream>
#include <utility>
#include<map>

using namespace std;

pair<int,int> result;
int target = 8;
bool f = false;

void Twosum_brute(int a[])
{
	for(int i=0; i<5; i++)
	{
		for(int j=i+1; j<5; j++)
		{
			if((a[i]+a[j])==target)
			{
				result.first = i;
				result.second = j;
				f = true;
				break;
			}
		}
		if(f==true)
		{
			break;
		}
	}
	if(f==true)
	{
		cout<<"the first index:"<<result.first<<endl;
		cout<<"the second index:"<<result.second<<endl;
	}
	else
	{
		cout<<"result not found"<<endl;
	}
}

void Twosum_hash(int a[])
{
	map<int,int> m;
	for (int i=0;i<5;i++)
	{
		m[target-a[i]]=i;
	}
	for (int i=0;i<5;i++)
	{
		if(m.find(a[i])==m.end())
		{
			continue;
		}
		else
		{
			result.first = i;
			result.second = m[a[i]];
			f=true;
			break;
		}
	}
	if(f==true)
	{
		cout<<"the first index:"<<result.first<<endl;
		cout<<"the second index:"<<result.second<<endl;
	}
	else
	{
		cout<<"result not found"<<endl;
	}
}

int main()
{
	int a[5]={1,2,4,7,9};
	Twosum_brute(a);
	Twosum_hash(a);
	return 0;
}