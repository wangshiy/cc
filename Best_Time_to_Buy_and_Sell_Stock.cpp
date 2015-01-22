/*
Problem:
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) 
    {
        if (prices.size() < 2) return 0;
        
        int min = prices[0];
        //int max = 0;
        int profit = 0;

        for (size_t i = 0; i < prices.size(); i++)
        {
            int temp = prices[i] - min;
            if (temp > profit) profit = temp;
            if (prices[i] < min) min = prices[i];
        }
        
        return profit;
    }
};