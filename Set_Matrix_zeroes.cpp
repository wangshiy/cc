/*
Problem:
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

/*
Solution:
http://blog.csdn.net/fightforyourdream/article/details/14220585
*/

#include<iostream>
#include<vector>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
	bool rowZero = false;
	bool colZero = false;

	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i][0] == 0)
		{
			colZero = true;
			break;
		}
	}

	for (int j = 0; j < matrix[0].size(); j++)
	{
		if (matrix[0][j] == 0)
		{
			rowZero = true;
			break;
		}
	}

	// 标记对应第一行与第一列的元素为0
	for (int i = 1; i < matrix.size(); i++)
	{
		for (int j = 1; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for (int i = 1; i < matrix.size(); i++)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	for (int j = 1; j < matrix[0].size(); j++)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 0; i < matrix.size(); i++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	if (rowZero)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			matrix[0][j] = 0;
		}
	}

	if (colZero)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			matrix[i][0] = 0;
		}
	}
}
