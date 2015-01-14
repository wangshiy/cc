/*
Problem:
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code"
*/

/*The below is wrong :

#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict)
{
	bool result = false;
	string test = "#";

	for (int i = 1; i < s.size()+1; i++)
	{
		cout << "s.substr(0,i):" << s.substr(0,i) << endl;
		if (dict.find(s.substr(0,i)) != dict.end())
		{
			cout << "hello" << endl;
			test = s.substr(i);
			cout << "test:" << test << endl;
			if (test.empty())
			{
				return true;
			}
			break;
		}
	}

	if (test == "#")
	{
		cout << "hi" << endl;
		return false;
	}

	result = wordBreak(test, dict);

	return result;
}

int main()
{
	unordered_set<string> myset;
	myset.insert("aaaa");
	myset.insert("aaa");
	//myset.insert("green");
	string test = "aaaaaaa";
	bool result;
	result = wordBreak(test, myset);
	cout << result << endl;
	//string a = test.substr(0);
	//cout << a[a.size()-1] << endl;
	return 0;
}
*/

class Solution {
public:
     bool wordBreak(string s, unordered_set<string> &dict) {
          string s2 = "#" + s;
          int len = s2.size();
          vector<bool> possible(len, 0);
          
          possible[0] = true;
          for(int i =1; i< len; ++i)
          {
              for(int k=0; k<i; ++k)
             {
                 possible[i] = possible[k] && 
                                 dict.find(s2.substr(k+1, i-k)) != dict.end();
                 if(possible[i]) break;
             }
         }
         
         return possible[len-1];
     }
     
};