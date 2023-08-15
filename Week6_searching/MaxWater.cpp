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
int MaxWater(int arr[], int  n)
{
	int left = 0, right = n - 1;
	int water = 0;
	while (left < right) {
		if (arr[left] < arr[right]) {
			water = max(water, arr[left] * (right - left - 1));
			left++;
		}
		else {
			water = max(water, arr[right] * (right - left - 1));
			right--;
		}
	}
	return water;
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
		cout << MaxWater(arr, n) << endl;
	}
	return 0;
}
