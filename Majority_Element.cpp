/*
Problem:
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int> &num) 
    {
        sort(num.begin(),num.end());
        return num[num.size()/2];
    }
};