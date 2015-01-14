/*
Problem:
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

#include<iostream>

using namespace std;

int lengthOfLastWord(const char *s) 
{
	int len = strlen(s);
	int count = 0;

	for (int i = len-1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
		    if (count == 0) continue;
		    else
			return count;
		}
		else
		{
			count++;
		}
	}

	return count;
}

int main()
{
	char* s = "abc";
	//cout << s.size() << endl;
	return 0;
}