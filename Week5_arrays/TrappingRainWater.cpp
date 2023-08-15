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
ll trappingRainWater(int arr[], int n)
{
	int Revmaxi[n], maxi[n];
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			Revmaxi[n - 1 - i] = arr[n - 1];
			maxi[i] = arr[0];
		}
		else {
			Revmaxi[n - 1 - i] = max(arr[n - 1 - i], Revmaxi[n - 1 - i + 1]);
			maxi[i] = max(arr[i], maxi[i - 1]);
			// cout << Revmaxi[i] << " " << maxi[i] << endl ;
		}
	}
	long long sum = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		int val = min(Revmaxi[i], maxi[i]) - arr[i];
		// cout << val << " ";
		if (val >= 0) {
			sum += val ;
		}
	}
	return sum;
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
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		cout << trappingRainWater(arr, n);
	}
	return 0;
}
