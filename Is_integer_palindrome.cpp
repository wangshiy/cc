/*Problem:
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

/*Solution:
* Determine whether an integer is a palindrome. Do this without extra space.
* 
* 
* Some hints:
* 
* Could negative integers be palindromes? (ie, -1)
* 
* If you are thinking of converting the integer to string, note the restriction of using extra space.
* 
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
* you know that the reversed integer might overflow. How would you handle such case?
* 
* There is a more generic way of solving this problem.
*/

#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:

    bool isPalindrome(int x) {
        if (x<0) {
            return false;
        }
        
        int len=1;
        for (len=1; (x/len) >= 10; len*=10 );
       // cout << "len:" << len << endl;
        while (x != 0 ) {
            int left = x / len;
            int right = x % 10;
            
            if(left!=right){
                return false;
            }
            
            x = (x%len) / 10;
            len /= 100;
        }
        return true;
    }
};



int main()
{
    Solution s;
    printf("%d is %d\n", 0, s.isPalindrome(0) );
    printf("%d is %d\n", -101, s.isPalindrome(-101) );
    printf("%d is %d\n", 1001, s.isPalindrome(1001) );
    printf("%d is %d\n", 1234321, s.isPalindrome(1234321) );
    printf("%d is %d\n", 2147447412, s.isPalindrome(2147447412) );
    printf("%d is %d\n", 2142, s.isPalindrome(2142) );
}