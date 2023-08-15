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
string PrintNum(string s)
{
	string ans;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'p' || s[i] == 'q' || s[i] == 'r' || s[i] == 's')
		{
			ans.push_back('7');
		}
		else if (s[i] == 't' || s[i] == 'u' || s[i] == 'v')
		{
			ans.push_back('8');
		}
		else if (s[i] == 'w' || s[i] == 'x' || s[i] == 'y' || s[i] == 'z')
		{
			ans.push_back('8');
		}
		else {
			int x = (s[i] - 'a') / 3 + 2;
			ans.push_back(48 + x);
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
		string s;
		cin >> s;
		cout << PrintNum(s);

	}
	return 0;
}
