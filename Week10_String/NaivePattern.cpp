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
bool search(string txt, string pat)
{

	for (int i = 0; i < txt.size() - pat.size(); i++)
	{
		while (txt[i] != pat[0]) i++;
		if (i > txt.size() - pat.size()) return false;
		int count = 0;
		for (int j = i; j < pat.size() + i; j++)
		{
			if (pat[j - i] == txt[j]) count++;

		}
		if (count == pat.size()) {cout << i << endl; return true;}

	}
	return false;
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
		string txt, pat;
		cin >> txt;
		getchar();
		cin >> pat;
		cout << search(txt, pat);

	}
	return 0;
}
