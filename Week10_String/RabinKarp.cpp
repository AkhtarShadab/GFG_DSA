#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define d 256
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
void RabinKarp(string pat, string txt, int q)
{
	// Your code here
	int h = 1;
	int m = pat.size();
	int n = txt.size();
	for (int i = 1; i < m; i++)
	{
		h = (h * d) % q;
	}
	int txth = 0;
	int path = 0;
	for (int i = 0; i < m; i++)
	{
		txth = (txt[i] - 'a' + txth * d) % q;
		path = (path * d + pat[i] - 'a') % q;
	}
// 	cout<<txth<<" "<<path;
	for (int i = 0; i <= n - m; i++)
	{
		if (path == txth)
		{
			bool flag = true;
			for (int j = i; j < m + i; j++)
			{
				if (txt[j] != pat[j - i]) {flag = false; break;}
			}
			if (flag == true) cout << i + 1 << endl;;

		}
		if (i < n - m)
		{
			txth = (d * (txth - (txt[i] - 'a') * h) + txt[i + m] - 'a') % q;
			if (txth < 0) txth += q;
		}
	}

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
		RabinKarp( pat, txt, mod);
	}
	return 0;
}
