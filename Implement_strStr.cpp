/*
Problem:
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition
*/

#include<iostream>
#include<cstring>

using namespace std;

int strStr(char *haystack, char *needle) 
    {
        if (haystack == NULL) 
        {
            if (needle == NULL) return 0;
            else cout << "hi" << endl; return -1;
        }
        
        if (needle == NULL) return 0;
        
        int len_haystack = strlen(haystack);
		cout << len_haystack << endl;
        int len_needle = strlen(needle);
		cout << len_needle << endl;
        
        for (int i = 0; i <= len_haystack - len_needle; i++)
        {
            for (int j = 0; j <= len_needle; j++)
            {
                char* a = haystack + i + j;
				cout << "*a:" << *a << endl;
                char* b = needle + j;
				cout << "*b:" << *b << endl;
                if (*b == '\0') return i;
                if (*a != *b) break;
            }
        }
        
        return -1;
    }

int main()
{
	char a[] = {'a','b','c','d','\0'};
	char b[] = {'b','c','\0'};
	int test;
	test = strStr(a,b);
	cout << test << endl;
	return 0;
}