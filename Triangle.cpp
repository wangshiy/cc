/*
Problem:
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* Greedy Algorithm (which is wrong)
******************************************************
    int minimumTotal(vector<vector<int> > &triangle) {
        int result;
		int index = 0;
		vector<vector<int>> v;
        for (int i=0; i<triangle.size();i++)
        {
            if (i==0)
            {
                v.push_back(triangle[i]);
                result = v[i][0];
                continue;
            }
            vector<int> tmp;
            int min = 0x7FFF;
			int local_index = 0;
            for (int j=index; j<=(index+1); j++)
            {
                if(triangle[i][j] < min)
                {
                    min = triangle[i][j];
					local_index = j;
                }
            }
			index = local_index;
            tmp.push_back(min);
            v.push_back(tmp);
            result += v[i][0];
        }
        return result;
    }

	int main()
	{
		vector< vector<int> > v;
    vector<int> i;
    i.push_back(-1);
    v.push_back(i);
    
    i.clear();
    i.push_back(2);
    i.push_back(3);
    v.push_back(i);

    i.clear();
    i.push_back(1);
    i.push_back(-1);
    i.push_back(-3);
    v.push_back(i);

    int s=minimumTotal(v);
    cout << s << endl;

    return 0;
	}
*/

int minimumTotal(vector<vector<int>> &triangle) 
{
	vector<vector<int>> v;
	for (int i = 0; i < triangle.size(); i++)
	{
		if (i == 0)
		{
			v.push_back(triangle[i]);
			continue;
		}

		vector<int> tmp;
		for (int j = 0; j < triangle[i].size(); j++)
		{
			if (j == 0)
			{
				tmp.push_back(triangle[i][j] + v[i-1][j]);
			}
			else if (j == triangle[i].size()-1)
			{
				tmp.push_back(triangle[i][j] + v[i-1][j-1]);
			}
			else
			{
				tmp.push_back(triangle[i][j] + min(v[i-1][j-1],v[i-1][j]));
			}
		}
		v.push_back(tmp);
	}

	int min_value = 0x7FFF;
	for (int i = 0; i < v[triangle.size()-1].size(); i++)
	{
		if (v[triangle.size()-1][i] < min_value)
		{
			min_value = v[triangle.size()-1][i];
		}
	}

	return min_value;
}

int main()
	{
		vector< vector<int> > v;
    vector<int> i;
    i.push_back(-1);
    v.push_back(i);
    
    i.clear();
    i.push_back(2);
    i.push_back(3);
    v.push_back(i);

    i.clear();
    i.push_back(1);
    i.push_back(-1);
    i.push_back(-3);
    v.push_back(i);

    int s=minimumTotal(v);
    cout << s << endl;

    return 0;
	}