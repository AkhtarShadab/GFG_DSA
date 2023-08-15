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
bool findTriplets(int a[], int n)
{
	sort(a, a + n);
	for (int i = 0; i < n - 1; ++i)
	{
		int start = i + 1;
		int end = n - 1;
		int val = a[i];
		while (start < end) {
			if (a[start] + a[end] == -val) {
				return true;
			}
			else if (a[start] + a[end] > -val) {
				end--;
			}
			else start++;
		}

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
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		cout << findTriplets(a, n);
	}
	return 0;
}
