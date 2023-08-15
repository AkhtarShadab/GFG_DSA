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
int dp[1001][1001];
class Solution {
public:
	int f(int price[], int i, int wt)
	{
		if (i == 0) return dp[i][wt] = wt * price[i];
		if (dp[i][wt] != -1) return dp[i][wt];

		int notTake = f(price, i - 1, wt);
		int take = 0;
		if (i + 1 <= wt) take = price[i] + f(price, i, wt - i - 1);
		return dp[i][wt] = max(take, notTake);

	}
	int cutRod(int price[], int n) {
		//code here
		memset(dp, -1, sizeof(dp));
		return f(price, n - 1, n);
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

		cout << ob.cutRod(a, n) << endl;
	}
	return 0;
}
