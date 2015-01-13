/*
Problem:
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int sqrt(int x) 
    {
        int start = 0;
        int end;
        end = x/2 < std::sqrt(INT_MAX) ? (x/2+1):(std::sqrt(INT_MAX));
        while (start <= end)
        {
            int mid = (start + end)/2;
            int sqr = mid*mid;
            if (x == sqr)
            {
                return mid;
            }
            if (x < sqr)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return (start+end)/2;
    }
};