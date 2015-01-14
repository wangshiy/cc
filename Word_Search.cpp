#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool findword(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, string &word, int index)
{
	if (index == word.size()) return true;
	if (row<0 || col<0 || row>=board.size() || col>=board[0].size() || visited[row][col] || board[row][col] != word[index]) return false;

	visited[row][col] = true;
	if(findword(board, visited, row-1, col, word, index+1)) return true;
	if(findword(board, visited, row+1, col, word, index+1)) return true;
	if(findword(board, visited, row, col-1, word, index+1)) return true;
	if(findword(board, visited, row, col+1, word, index+1)) return true;
	visited[row][col] = false;

	return false;
}

bool exist(vector<vector<char>> &board, string word) 
{
	if (board.size()<=0 || board[0].size()<=0) return false;

	vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));

	for (int i=0; i<board.size(); i++)
	{
		for (int j=0; j<board[i].size(); j++)
		{
			if (findword(board, visited, i, j, word, 0)) return true;
		}
	}

	return false;
}

int main()
{
	vector<vector<char>> result;
	vector<char> test;
	test.push_back('a');
	test.push_back('a');
	result.push_back(test);

	bool Oh;
	Oh = exist(result,"aa");

	cout << Oh << endl;
	return 0;
}