/*
Problem:
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int numDecodings(string s) 
{
	if (s.empty()) return 0;
	if (s[0] == '0') return 0;
	vector<int> result(s.size()+1,0);
	result[0] = 1;
	result[1] = 1;

	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] != '0') 
		{
			result[i+1] += result[i];
			int v = (s[i-1]-'0')*10 + (s[i]-'0');
			if (v <= 26 && v >9) result[i+1] += result[i-1];
		}
		else
		{
			int v = (s[i-1]-'0')*10 + (s[i]-'0');
			if (v <= 26 && v >9) result[i+1] += result[i-1];
		}

		if (result[i+1] == 0) return 0;
	}

	return result[s.size()];
}

int main()
{
	string s = "12120";
	cout << numDecodings(s) << endl;
	return 0;
}