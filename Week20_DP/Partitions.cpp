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
	//Function to count the number of different ways in which n can be
	//written as a sum of two or more positive integers.

	int countWays(int n)
	{
		// your code here
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = i; j <= n; ++j)
			{
				dp[j] = (dp[j] % mod + dp[j - i] % mod) % mod;
			}
		}
		return dp[n];



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
		int n;
		cin >> n;
		Solution ob;
		cout << ob.countWays(n) << endl;

	}
	return 0;
}
