/*
Problem;
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

#include<iostream>

using namespace std;

class Solution {
public:
int jump(int A[], int n)
{
	if (n == 1) return 0;

	int start = 0;
	int end = 0;
	int count = 0;
	int maxbound = 0;

	while (end < n)
	{
	    count++;
		for (int i = start; i <= end; i++)
		{
			if (A[i] + i >= n-1) return count;
			if (A[i] + i > maxbound) maxbound = A[i] + i; 
		}
		start  = end + 1;
		end = maxbound;
	}
}
};