#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Combination(vector<vector<int>> &result, int element);

vector<vector<int>> Subsets(vector<int> &S) 
{
	sort(S.begin(),S.end());
	vector<vector<int>> result;
	vector<int> temp;
	temp.push_back(S[0]);
	result.push_back(temp);
	for (int i = 1; i < S.size(); i++)
	{
		Combination(result, S[i]);
	}
	vector<int> emp;
	result.push_back(emp);
	return result;
}

void Combination(vector<vector<int>> &result, int element)
{
	int result_size = result.size();
	for (int i = 0; i < result_size; i++)
	{
		vector<int> temp = result[i];
		temp.push_back(element);
		result.push_back(temp);
	}
	vector<int> current_element;
	current_element.push_back(element);
	result.push_back(current_element);
}

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	vector<vector<int>> test;
	test = Subsets(v);
	cout << test[0][0] << endl;
	cout << test[1][0] << endl;
	cout << test[1][1] << endl;
	cout << test[2][0] << endl;
	cout << test[3][0] << endl;
	cout << test[4][0] << endl;
	cout << test[5][0] << endl;
	cout << test[6][0] << endl;
	//cout << test[7][0] << endl;
	return 0;
}