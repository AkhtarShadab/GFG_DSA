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
	//Function to return nCr mod 10^9+7 for given n and r.

	int nCrModp(int n, int r)
	{
		if (r > n) return 0;

		// your code here
		int dp[n + 1][n + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n + 1; ++i)
		{
			dp[i][0] = 1;
		}
		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; j < i + 1; ++j)
			{
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
			}
		}

		// for (int i = 0; i < n + 1; ++i)
		// {
		// 	for (int j = 0; j < i + 1; ++j)
		// 	{
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		return dp[n][r];

	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t, n, r;

	//taking count of testcases
	cin >> t;

	while (t--) {

		//taking n and r
		cin >> n >> r;
		Solution ob;
		//calling method nCrModp()
		cout << ob.nCrModp(n, r) << endl;
	}

	return 0;
}
