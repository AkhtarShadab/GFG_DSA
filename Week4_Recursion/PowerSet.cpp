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

void powerSets(string s, int index, string y, vector<string> &ans)
{
	int n = s.length();
	if (n == index)
	{
		ans.push_back(y);
		return;
	}
	powerSets(s, index + 1, y + s[index], ans);
	powerSets(s, index + 1, y, ans);
}

vector<string> powerSet(string s)
{
	vector<string> ans;
	string y = "";
	powerSets(s, 0, y, ans);
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

		vector<string> ans;

		ans = powerSet(s);

		sort(ans.begin(), ans.end());

		for (auto x : ans)
		{
			cout << x << endl;
		}
	}
	return 0;
}
