/*
Problem:
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/*
class Solution {
public:
    int maxProfit(vector<int> &prices) 
    {
        int max = 0;
        int max1;
        int max2;
        
        for (int i = 0; i < prices.size(); i++)
        {
            max1 = searchmax(prices,0,i);
            max2 = searchmax(prices,i+1,prices.size()-1);
            if (max < max1+max2) max = max1+max2;
        }
        
        return max;
    }
    
    int searchmax(vector<int> &prices, int start, int end)
    {
        int min = INT_MAX;
        int max = 0;
        int diff = 0;
        for (int i = start; i <= end; i++)
        {
            if (min > prices[i]) min = prices[i];
            diff = prices[i] - min;
            if (diff > max) max = diff;
        }
        return max;
    }
};
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size() <= 1)
            return 0;
            
        //stores the max profit in [0, ... , i] subarray in prices
        vector<int> maxEndWith;
        {//build the maxEndWith.
            int lowest = prices[0];
            int maxprofit = 0;
            maxEndWith.push_back(0);
            for(int i = 1; i < prices.size(); ++i) {
                int profit = prices[i] - lowest;
                if(profit > maxprofit) {
                    maxprofit = profit;
                }
                maxEndWith.push_back(maxprofit);
                if(prices[i] < lowest) lowest = prices[i];
            }
        }
        
        int ret = maxEndWith[prices.size() - 1];
        {//reverse to see what is the maxprofit of [i, ... , n-1] subarray in prices
        //and meanwhile calculate the final result
            int highest = prices[prices.size() - 1];
            int maxprofit = 0;
            for(int i = prices.size() - 2; i >= 0; --i) {
                int profit = highest - prices[i];
                if(profit > maxprofit)  maxprofit = profit;
                int finalprofit = maxprofit + maxEndWith[i];
                if(finalprofit > ret) ret = finalprofit;
                if(prices[i] > highest) highest = prices[i];
            }
        }

        return ret;
    }
};