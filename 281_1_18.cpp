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

void OneLetterLength(string StartWord, string EndWord, vector<string> &Dict, queue<pair<string,pair<int,int>>> &Result, bool &FirstTime, int &Index, bool &Found)
{
	cout << "This is a new recursion" <<endl;
	if (FirstTime == true)
	{
		FirstTime = false;
		Dict.push_back("#");
		Result.push(MakePair(StartWord,0,0));
		Record.push_back(MakePair(StartWord,0,0));
	}

	if (Result.empty())
	{
		return;
	}
	//Record.push_back(Result.front());
	Result.pop();

	int index = 0;

	while (Dict[index] != "#")
	{
		if (Dict[index].size() == StartWord.size() - 1)
		{
			// to do: this below can be updated into a sub function to call
			for (int i = 0; i < StartWord.size(); i++)
			{
				string temp = StartWord;
				if (temp.erase(i,1) == Dict[index]) // Found the target
				{
					position++;
					cout << "the matched word is: " << Dict[index] << ", at position: " << position << endl;
					Result.push(MakePair(Dict[index], Index, position));
					Record.push_back(MakePair(Dict[index],Index,position));
					if (Dict[index] == EndWord)
					{
						cout << "1found: " << Dict[index] << ", position:" << position << endl;
						Found = true;
						//Record.push_back(MakePair(Dict[index],Index,position));
						return;
					}
					Dict.erase(Dict.begin()+index);
					break;
				}
			}
		}

		else if (Dict[index].size() == StartWord.size() + 1)
		{
			for (int i = 0; i < Dict[index].size(); i++)
			{
				string temp = Dict[index];
				if (temp.erase(i,1) == StartWord)
				{
					position++;
					cout << "the matched word is: " << Dict[index] << ", at position: " << position << endl;
					Result.push(MakePair(Dict[index], Index, position));
					Record.push_back(MakePair(Dict[index],Index,position));
					if (Dict[index] == EndWord)
					{
						cout << "2found: " << Dict[index] << ", position:" << position << endl;
						Found = true;
						//Record.push_back(MakePair(Dict[index],Index,position));
						return;
					}
					Dict.erase(Dict.begin()+index);
					break;
				}
			}
		}

		index++;
	}

	pair<string,pair<int,int>> next = Result.front();
	OneLetterLength(next.first, EndWord, Dict, Result, FirstTime, next.second.second, Found);

	return;
}

int main()
{
	vector<string> Dict;
	Dict.push_back("ca");
	Dict.push_back("kate");
	Dict.push_back("cate");
	Dict.push_back("cae");
	Dict.push_back("cte");
	Dict.push_back("kcte");

	string start  = "cat";
	string end = "kcte";

	queue<pair<string,pair<int,int>>> test;
	bool first = true;
	int first_index = 0;
	bool found = false;

	OneLetterLength(start, end, Dict, test, first, first_index,found);
	
	if (found == true)
	{
		stack<string> Final;
		//cout << Record.size() << endl;
		//cout << test.back().first << endl; //bugs
		int post = test.back().second.second;
		do
		{
			//cout << "post:" << post << endl;
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