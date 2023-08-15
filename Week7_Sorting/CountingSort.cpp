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
string LexSort(string s, int n)
{
	vector<int> a(26);
	for (int i = 0; i < n; ++i)
	{
		a[s[i] - 'a']++;
	}
	string ans;
	for (int i = 0; i < 26; ++i)
	{
		if (a[i] != 0)
		{
			for (int j = a[i]; j > 0; --j)
			{
				ans.push_back('a' + i);
			}
		}
	}
	return ans;
}
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
		getchar();
		string s, ans;
		cin >> s;
		ans = LexSort(s, n);
		cout << ans;

	}
	return 0;
}
