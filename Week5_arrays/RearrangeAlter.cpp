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
void rearrange(long long *arr, int n)
{
	long long maxval = -1;
	for (int i = 0; i < n; ++i)
	{
		maxval = max(maxval, arr[i]);
	}
	maxval++;
	int st = n / 2;
	if (n % 2)
	{
		for (int i = n - 1; i > -1; i -= 2)
		{
			arr[i] += (arr[st] % maxval) * maxval;
			st++;
		}

	}
	else
	{
		for (int i = n - 2; i > -1; i -= 2)
		{
			arr[i] += (arr[st] % maxval) * maxval;
			st++;
		}
	}
	st = 0;
	for (int i = 1; i < n; i += 2)
	{
		arr[i] += (arr[st] % maxval) * maxval;
		st++;
	}
	for (int i = 0; i < n; ++i)
	{
		arr[i] /= maxval;
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
		int n;
		cin >> n;
		long long arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		rearrange(arr, n);
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}
	}
	return 0;
}
