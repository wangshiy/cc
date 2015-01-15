/*
Problem:
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
*/

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int titleToNumber(string s)
{
	size_t size_s = s.size();
	int result = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		int t = s[i] - 64;
		result += pow(26,(size_s-1-i))*t;
	}
	return result;
}


int main()
{
	string s = "AAA";
	int test;
	test = titleToNumber(s);
	cout << test << endl;

	return 0;
}