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
	//Function to count number of ways to reach the nth stair.
	int countWays(int n)
	{
		// your code here
		if (n == 1) return 1;
		if (n == 2) return 2;

		int c1 = 1, c2 = 2;
		for (int i = 3; i <= n; ++i)
		{
			if (i % 2) c1 = (c1 + c2 ) % mod;
			else c2 = (c1 + c2) % mod;
		}

		if (n % 2)  return c1 % mod;
		return c2 % mod;

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
		int m;
		cin >> m;
		Solution ob;
		cout << ob.countWays(m) << endl;

	}
	return 0;
}
