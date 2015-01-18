#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

queue<pair<int,int>> Record;

void OneLetterChange(string StartWord, string EndWord, vector<string> &Dict, queue<string> &Result, bool &FirstTime)
{
	cout << "hello" << endl;
	if (FirstTime == true)
	{
		FirstTime = false;
		Dict.push_back("#");
		Result.push(StartWord);
		pair<int,int> firstpair(0,0);
		Record.push(firstpair);
	}

	if (Result.empty())
	{
		return;
	}
	Result.pop();
	cout << "im here" << endl;
	for (size_t i = 0; i < StartWord.size(); i++)
	{
		string ref = Dict[0];
		int index = 0;
		while (ref != "#")
		{
			string tmp = ref;
			string start = StartWord;
			/*
			if (Dict[index] == EndWord) 
			{
				cout << "found" << endl;
				Result.push(Dict[index]);
				return;
			}
			*/
			if (StartWord.size() == ref.size() && StartWord[i] != ref[i] && start.erase(i,1) == ref.erase(i,1))
			{
				Result.push(tmp);
				Dict.erase(Dict.begin()+index);
				if (tmp == EndWord)
				{
					cout << "found" << endl;
					return;
				}
			}
			index++;
			ref = Dict[index];
		}
	}
	/*
	queue<string> temp = Result;
	cout << "hi" << endl;
	while(!temp.empty())
	{
		cout << temp.front() << endl;
		temp.pop();
	}
	*/
	string next = Result.front();
	cout << "next:" << next << endl;
	//Result.pop();
	OneLetterChange(next, EndWord, Dict, Result, FirstTime);

	return;
}

pair<string,pair<int,int>> MakePair(string S, int Prev, int Post)
{
	pair<int,int> int_pair(Prev,Post);
	pair<string,pair<int,int>> result(S,int_pair);
	return result;
}

int main()
{
	vector<string> Dict;
	//Dict.push_back("chip");
	Dict.push_back("chop");
	Dict.push_back("shop");
	Dict.push_back("ship");
	Dict.push_back("stop");
	Dict.push_back("chat");
	Dict.push_back("ca");

	string start  = "chip";
	string stop = "stop";

	queue<string> test;
	bool first = true;

	OneLetterChange(start, stop, Dict, test, first);
	
	cout << test.size() << endl;
	
	while(!test.empty())
	{
		cout << test.front() << endl;
		test.pop();
	}
	
	return 0;
}