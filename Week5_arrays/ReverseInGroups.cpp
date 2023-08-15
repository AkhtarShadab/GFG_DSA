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
void reverseInGroups(vector<long long>& arr, int n, int k) {
	// code here
	if (k == 1) return;
	long long rev[n];
	for (int i = 0; i < n; ++i)
	{
		rev[i] = arr[n - 1 - i];
	}
	int j = 0;
	int x = n / k;
	x *= k;
	int m = 0;
	int l = 1;
	if (x == n) {
		while (j < x)
		{
			j += k;
			for (int i = j - 1; i > m - 1; i--)
			{
				arr[n - (2 * l - 1)*k + i] = rev[i];
			}
			m = j;
			l++;
		}


	}
	else {
		int extra = n - x;
		for (int i = 0; i < extra; ++i)
		{
			arr[n - extra + i]   =  rev[i];
		}
		while (j < n - extra)
		{
			j += k;
			for (int i = j - 1; i > m - 1; i--)
			{
				arr[n - (2 * l - 1)*k + i - extra] = rev[i + extra];
			}
			m = j;
			l++;
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
		int n, k;
		cin >> n >> k;
		vector<long long> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		reverseInGroups(arr, n, k);
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}

	}
	return 0;
}
