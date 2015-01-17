/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >res;
        vector<int>tmpres;
        helper(1,n,k,tmpres,res);
        return res;
    }
    
    //从[left, right]范围内选取k个数，tmpres是一个临时组合
    void helper(int left, int right, int k, vector<int> &tmpres, vector<vector<int> >&res)
    {
        if(right-left+1 < k)return;
        if(k == 0)
        {
            res.push_back(tmpres);
            return;
        }
        //选择left
        tmpres.push_back(left);
        helper(left+1, right, k-1, tmpres, res);
        tmpres.pop_back();
        //不选择left
        helper(left+1, right, k, tmpres, res);
    }
};