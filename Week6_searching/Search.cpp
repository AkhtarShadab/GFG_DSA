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
bool search(int a[], int n, int x)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == x) return true;
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
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		cout << search(a, n, x) << endl;
	}
	return 0;
}
