/*Problem:
Write a method to generate the nth Fibonacci number.
*/

/*Solution:
f(1) = f(2) = 1;
f(n) = f(n-1) + f(n-2);
*/

#include <iostream>

using namespace std;

typedef long long ll;

ll fib(ll n)
{
	if(n < 1)
	{
		return -1;
	}
	else if(n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return (fib(n-1)+fib(n-2));
	}
}

int main()
{
    ll test = 4;
	ll result;
	result = fib(test);
	cout << "result:" << result << endl;
    return 0;
}