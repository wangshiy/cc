/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> allSol;
        vector<string> sol;
        vector<int> col;
        solveNQ(n, 0, col, sol, allSol);
        return allSol;
    }
    
    void solveNQ(int n, int irow, vector<int> &col, vector<string> &sol, vector<vector<string>> &allSol) {
        if(irow==n) {
            allSol.push_back(sol);
            return;
        }
        
        for(int icol=0; icol<n; icol++) {
            if(validPos(col, irow, icol)) {
                string s(n,'.');
                s[icol] = 'Q';
                sol.push_back(s);
                col.push_back(icol);
                solveNQ(n, irow+1, col, sol, allSol);
                sol.pop_back();
                col.pop_back();
            }
        }
    }
    
    bool validPos(vector<int> &col, int irow, int icol) {
        if(irow<col.size()) return false;
        for(int i=0; i<col.size(); i++) {
            if(icol==col[i] || abs(irow-i)==abs(icol-col[i]))
                return false;
        }
        return true;
    }
};