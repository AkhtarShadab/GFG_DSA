#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
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

class Solution {

public:
	int minDifference(int arr[], int n)  {
		// Your code goes here
		int totalSum = 0;
		for (int i = 0; i < n; ++i)
		{
			totalSum += arr[i];
		}
		bool dp[n][totalSum + 1];
		memset(dp, false, sizeof(dp));
		for (int i = 0; i < n; ++i)
		{
			dp[i][0] = true;
		}
		if (arr[0] <= totalSum) dp[0][arr[0]] = true;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < totalSum + 1; ++j)
			{
				bool notTake = dp[i - 1][j];
				bool take = false;
				if (arr[i] <= j) take = dp[i - 1][j - arr[i]];
				dp[i][j] = notTake | take;
			}
		}
		int mini = INT_MAX;
		for (int i = 0; i <= totalSum / 2; ++i)
		{
			if (dp[n - 1][i])
			{
				int s1 = i;
				int s2 = totalSum - i;
				mini = min(mini, abs(s1 - s2));
			}
		}
		return mini;


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
		cout << ob.minDifference(a, n) << "\n";

	}
	return 0;
}
