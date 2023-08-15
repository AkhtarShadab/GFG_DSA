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

	int f(string a, string b, int i, int j)
	{
		if (i == 0) return dp[i][j] = 0;
		if (j == 0) return dp[i][j] = 0;
		if (dp[i][j] != -1) return dp[i][j];

		if (a[i - 1] == b[j - 1]) return dp[i][j] = f(a, b, i - 1, j - 1) + 1;
		else return dp[i][j] = max(f(a, b, i - 1, j), f(a, b, i, j - 1));
	}
	int countMin(string str) {
		//complete the function here
		int n = str.size();
		memset(dp, -1, sizeof(dp));
		string rstr = str;
		reverse(rstr.begin(), rstr.end());
		return  n - f(str, rstr, n, n);
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
		string str;
		cin >> str;
		Solution ob;
		cout << ob.countMin(str) << endl;
	}
	return 0;
}
