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
int majority(int arr[], int n) {
	int res = 0, count = 1;
	for (int i = 1; i < n; ++i)
	{
		if (arr[res] == arr[i]) count ++;
		else count--;
		if (count == 0) {
			res = i;
			count = 1;
		}
	}
	count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[res] == arr[i]) count++;
	}
	if (count > n / 2) return arr[res];
	return -1;
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
		cout << majority(a, n) << endl;

	}
	return 0;
}
