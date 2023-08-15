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
`
string reverseWords(string S)
{
	// code here
	int n = S.size();
	string check = "";
	vector<string> ans;
	for (auto it = S.begin(); it != S.end(); ++it)
	{
		if (*it == '.')
		{
			check.push_back(*it);
			rev(check, check.size());
			ans.push_back(check);
			check = "";
		}
		else {
			check.push_back(*it);
		}
	}
	check.push_back('.');
	rev(check, check.size());
	ans.push_back(check);
	int k = 0, m = 0;
	for (auto& X : ans)
	{
		for (auto& Y : X)
		{
			if (m != 0)
			{

				S[k] = Y;
				k++;
			}
			m++;
		}
	}
	rev(S, n);
	return S;
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
		getchar();
		string s;
		cin >> s;
		s = reverseWords(s);
		cout << s;

	}
	return 0;
}
