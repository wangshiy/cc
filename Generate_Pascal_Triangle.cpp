/*
Problem:
********************************************************************************** 
* 
* Given numRows, generate the first numRows of Pascal's triangle.
* 
* For example, given numRows = 5,
* Return
* 
* [
*      [1],
*     [1,1],
*    [1,2,1],
*   [1,3,3,1],
*  [1,4,6,4,1]
* ]
* 
*               
**********************************************************************************
*/

#include<vector>
#include<iostream>

using namespace std;

vector<vector<int>> Generate(int row)
{
	vector<vector<int>> Pascal;
	for(int i=0; i<row; i++)
	{
		vector<int> v;
		if(i==0)
		{
			v.push_back(1);
		}
		else
		{
			v.push_back(1);
			for(int j=0; j<Pascal[i-1].size()-1; j++)
			{
				int temp = Pascal[i-1][j] + Pascal[i-1][j+1];
				v.push_back(temp);
			}
			v.push_back(1);
		}
		Pascal.push_back(v);
	}
	return Pascal;
}

int main()
{
	vector<vector<int>> test;
	int n = 3;
	test = Generate(n);
	cout << test[0][0] << endl;
	cout << test[1][0] << endl;
	cout << test[1][1] << endl;
	cout << test[2][0] << endl;
	cout << test[2][1] << endl;
	cout << test[2][2] << endl;
	return 0;
}
