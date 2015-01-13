#include<iostream>
#include<string>

using namespace std;

int c2n(char a)
{
	switch(a)
	{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
}
// 每一个小SECTION中一定是递增的
int change(string s)
{
	int result = 0;
	for (int i = 0; i < (s.size()-1); i++)
	{
		if (c2n(s[i]) < c2n(s[i+1]))
		{
			result -= c2n(s[i]);
		}
		else
		{
			result += c2n(s[i]);
		}
	}

	result += c2n(s.back());

	return result;
}

int romanToInt(string s) 
{
	int result = 0;
	int first = 0;

	for (int i = 1; i < s.size(); i++)
	{
		if (c2n(s[i]) < c2n(s[i-1]))
		{
			result += change(s.substr(first, i-first));
			first = i;
		}
	}

	result += change(s.substr(first, s.size()));

	return result;
}

int main()
{
	string s = "DCXXI";
	int test;
	test = romanToInt(s);
	cout << test << endl;
	return 0;
}