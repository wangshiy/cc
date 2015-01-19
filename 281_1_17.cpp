#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<utility>
#include<stack>

using namespace std;

vector<pair<string,pair<int,int>>> Record;
int position = 0;

pair<string,pair<int,int>> MakePair(string S, int Prev, int Post)
{
	pair<int,int> int_pair(Prev,Post);
	pair<string,pair<int,int>> result(S,int_pair);
	return result;
}

void OneLetterChange(string StartWord, string EndWord, vector<string> &Dict, queue<pair<string,pair<int,int>>> &Result, bool &FirstTime, int &Index, bool &Found)
{
	cout << "hello" << endl;
	if (FirstTime == true)
	{
		FirstTime = false;
		Dict.push_back("#");
		Result.push(MakePair(StartWord,0,0));
		Record.push_back(MakePair(StartWord,0,0));
		//Index = 0;
	}

	if (Result.empty())
	{
		return;
	}
	//Record.push_back(Result.front());
	Result.pop();
	//Record.push(StartWord);
	//cout << "im here" << endl;
	for (size_t i = 0; i < StartWord.size(); i++)
	{
		string ref = Dict[0];
		int index = 0;
		while (ref != "#")
		{
			string tmp = ref;
			string start = StartWord;
			if (StartWord.size() == ref.size() && StartWord[i] != ref[i] && start.erase(i,1) == ref.erase(i,1))
			{
				position++;
				Result.push(MakePair(tmp,Index,position));
				Record.push_back(MakePair(tmp,Index,position));
				if (tmp == EndWord)
				{
					cout << "found" << endl;
					Found = true;
					Record.push_back(MakePair(tmp,Index,position));
					return;
				}
				Dict.erase(Dict.begin()+index);
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
	pair<string,pair<int,int>> next = Result.front();
	//cout << "next:" << next << endl;
	//Result.pop();
	OneLetterChange(next.first, EndWord, Dict, Result, FirstTime,next.second.second, Found);

	return;
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

	queue<pair<string,pair<int,int>>> test;
	bool first = true;
	int first_index = 0;
	bool found = false;

	OneLetterChange(start, stop, Dict, test, first, first_index,found);
	/*
	cout << Record.size() << endl;
	
	while(!Record.empty())
	{
		cout << Record.front() << endl;
		Record.pop();
	}
	*/
	if (found == true)
	{
		stack<string> Final;
		int post = test.back().second.second;
		do
		{
			Final.push(Record[post].first);
			post = Record[post].second.first;
		} while (post != 0);
		Final.push(Record[0].first);

		cout << Final.size() << endl;
		while (!Final.empty())
		{
			cout << Final.top() << endl;
			Final.pop();
		}
	}
	
	return 0;
}