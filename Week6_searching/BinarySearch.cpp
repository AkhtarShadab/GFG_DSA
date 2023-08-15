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
int bs(int a[], int n, int k) {
	int low = 0, hi = n - 1;
	int mid = 0;
	while (low <= hi) {
		mid = low + (hi - low) / 2;
		if (a[mid] == k) return 1;
		else if (a[mid] > k) {
			hi = mid - 1;
		}
		else low = mid + 1;

	}
	if (mid == 0) return -1;
	return low - 1;
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
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		cout << bs(a, n, k) << endl;
	}
	return 0;
}
