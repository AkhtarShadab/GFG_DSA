#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;

int dp[1001];

ll binary_exponentiation(ll a, ll b, ll m)
{
	ll ans = 1;
	while (b)
	{
		if (b % 2 == 1)
		{
			ans = (ans * a) % m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return ans;
}
// } Driver Code Ends
class Solution {


public:
	int f(int arr[], int i)
	{
		if (i == 0) return dp[i] = arr[i];
		if (dp[i] == -1)
		{
			dp[i] = 0;
			for (int j = 0; j < i; ++j)
			{
				int val = f(arr, j);
				if (arr[i] > arr[j])
				{
					dp[i] = max(dp[i], val );
				}
			}
			dp[i] += arr[i];
			return dp[i];
		}
		return dp[i];
	}
	int maxSumIS(int arr[], int n)
	{
		// Your code goes here
		memset(dp, -1, sizeof(dp));
		int ans = f(arr, n - 1);
		for (int i = 0; i < n; i++)
		{
			if (ans < dp[i])  ans = dp[i];
		}
		// cout << binary_exponentiation(323, 21312, mod);
		// cout << endl;
		return ans;
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

		int a[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];



		Solution ob;
		cout << ob.maxSumIS(a, n) << "\n";

	}
	return 0;
}
