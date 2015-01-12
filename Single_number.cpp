class Solution {
public:
    int singleNumber(int A[], int n) 
    {
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s = s^A[i]; // XOR 有且只有一个为真才能为真， XOR 出现为偶数次数的话，效果抵消，奇数次数保留原数值
        }
        return s;
    }
};