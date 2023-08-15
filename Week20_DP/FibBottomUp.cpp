#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
class Solution
{
public:
	//Function to find the nth fibonacci number using bottom-up approach.
	long long findNthFibonacci(int number)
	{
		// Your Code Here
		long long fib[number + 1];
		fib[0] = 1;
		fib[1] = 1;
		for (int i = 2; i < number + 1; ++i)
		{
			fib[i] = fib[i - 1] + fib[i - 2];
		}
		return fib[number - 1];

	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int number;
		cin >> number;

		//calling function findNthFibonacci()
		//and passing number as parameter
		Solution obj;
		cout << obj.findNthFibonacci(number) << endl;
	}
	return 0;
}
