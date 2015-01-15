#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

queue<string> OneLetterChange(string StartWord, vector<string> &Dict)
{
	queue<string> result;
	Dict.push_back("#");
	
	for (size_t i = 0; i < StartWord.size(); i++)
	{
		string ref = Dict[0];
		int index = 0;
		while (ref != "#")
		{
			string tmp = ref;
			string start = StartWord;
			//cout << "StartWord.erase(i,1):" << start.erase(i,1) << endl;
			//cout << "ref.erase(i,1):" << ref.erase(i,1) << endl;
			if (StartWord.size() == ref.size() && StartWord[i] != ref[i] && start.erase(i,1) == ref.erase(i,1))
			{
				result.push(tmp);
			}
			index++;
			ref = Dict[index];
		}
	}

	return result;
}

int main()
{
	vector<string> Dict;
	Dict.push_back("chip");
	Dict.push_back("ship");
	Dict.push_back("shop");
	Dict.push_back("ca");
	string start  = "chop";

	queue<string> test;

	test = OneLetterChange(start, Dict);
	cout << test.size() << endl;
	
	while(!test.empty())
	{
		cout << test.front() << endl;
		test.pop();
	}
	
	return 0;
}