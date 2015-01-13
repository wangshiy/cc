class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) 
    {
        int N = num.size();
        
        vector<vector<int>> result;
        
        if (N == 1)
        {
            result.push_back(num);
            return result;
        }
        
        vector<int> cur;
        vector<vector<int>> post;
        vector<int> tmp;
        
        for (int i = 0; i < N; i++)
        {
            cur = num;
            cur.erase(cur.begin()+i);
            post = permute(cur);
            for (int j = 0; j < post.size(); j++)
            {
                tmp = post[j];
                tmp.insert(tmp.begin(),num[i]);
                result.push_back(tmp);
            }
        }
        
        return result;
    }
};