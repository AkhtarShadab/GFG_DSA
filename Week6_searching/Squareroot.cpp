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
ll squareroot(ll x) {
	long long lo = 1, hi = x;
	long long mid = 0;
	while (lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (mid * mid == x) return mid;
		else if (mid * mid > x) hi = mid - 1;
		else lo = mid + 1;
	}
	return lo - 1;
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
		ll n;
		cin >> n;
		cout << squareroot(n) << endl;
	}
	return 0;
}
