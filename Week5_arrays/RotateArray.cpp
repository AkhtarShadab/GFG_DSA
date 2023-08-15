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
void rotateArray(int arr[], int k, int n)
{
	if (k > n) k = k % n;
	int a[k];
	for (int i = 0; i < k; ++i)
	{
		a[i] = arr[i];
	}
	for (int i = 0; i < n - k; ++i)
	{
		arr[i] = arr[i + k];
	}
	for (int i = n  - k; i < n; ++i)
	{
		arr[i] = a[i - n + k];
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
		int n, d;
		cin >> n >> d;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		rotateArray(arr, d, n);
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}
	}
	return 0;
}
