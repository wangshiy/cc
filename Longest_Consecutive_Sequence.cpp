/*
Problem:
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) 
    {
        if (num.size() == 0) return 0;
        unordered_set<int> ht;
        for (int i = 0; i < num.size(); i++)
        {
            ht.insert(num[i]);
        }
        int length = 1;
        
        for (int i = 0; i < num.size(); i++)
        {
            int cur_length = 0;
            int cur_num = num[i];
            
            while (ht.count(cur_num))
            {
                ht.erase(cur_num);
                cur_length++;
                cur_num++;
            }
            
            cur_num = num[i] - 1;
            while (ht.count(cur_num))
            {
                ht.erase(cur_num);
                cur_length++;
                cur_num--;
            }
            
            length = max(length, cur_length);
        }
        
        return length;
    }
};