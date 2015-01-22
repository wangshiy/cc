/*
Problem:
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include<iostream>
#include<vector>

using namespace std;

    int maxProfit(vector<int> &prices) 
    {
        if (prices.size() <= 1) return 0;
        prices.push_back(0);
        
        int a = 0;
        int b = 0;
        int c = 0;
        
        bool buy = false;
        bool sell = false;
        
        int min = 0;
        if (prices[0] < prices[1])
        {
            min = prices[0];
            buy = true;
        }
        int max = 0;
        int profit = 0;
        
        size_t i = 0;
        
        while (i < prices.size()-2)
        {
			//cout << "i'm" << endl;
            a = prices[i];
            b = prices[i+1];
            c = prices[i+2];
            
            if (a >= b && b <= c && sell == false)
            {
				//cout << "buy" << endl;
                min = b;
                buy = true;
            }
            
            else if (b >= a && b >= c && buy == true)
            {
				//cout << "sell" << endl;
                max = b;
                sell = true;
            }
            
            if (buy == true && sell == true)
            {
                profit += max - min;
				//cout << profit << endl;
                sell = false;
                buy = false;
            }
            
            i++;
        }
        
        if (c >= b) profit += c-min;
        
        return profit;
    }

	int main()
	{
		vector<int> result;
		result.push_back(2);
		result.push_back(2);
		result.push_back(5);
		//result.push_back(1);

		int test;

		test = maxProfit(result);

		cout << test << endl;

		return 0;
	}

//Another Method
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p = 0;
        for(int i = 1; i < prices.size() ; ++i) {
            int delta = prices[i] - prices[i-1];
            if(delta > 0 ) {
                p += delta;
            }
        }
        return p;
    }
};