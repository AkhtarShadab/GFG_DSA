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

vector<int> LargestFraction(int n, int d) {
	// Code herei
	int a, b;
	a = b = -1;
	for (int i = 1; i <= 1e4; i++) {
		int x = (n * i) / d;
		while (x && (x * d >= (n * i) or __gcd(x, i) != 1)) x--;
		if (x)
		{
			if (a == -1)
			{
				a = x;
				b = i;
			}
			else
			{
				if (x * b > i * a)
				{
					a = x;
					b = i;
				}
			}
		}
	}
	// cout << a << " " << b;
	vector<int> ans;
	ans.push_back(a);
	ans.push_back(b);
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
		int n, d;
		cin >> n >> d;
		// cout << n << " " << d;
		vector<int> ans = LargestFraction(n, d);
		for (auto x : ans) {
			cout << x << " ";
		}

	}
	return 0;
}
