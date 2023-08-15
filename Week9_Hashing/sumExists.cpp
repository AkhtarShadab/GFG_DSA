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
bool sumExists(int arr[], int N, int sum) {
	// Your code here
	unordered_map<int, int> mp;
	for (int i = 0; i < N; ++i)
	{
		mp[arr[i]]++;
	}
	for (int i = 0; i < N; ++i)
	{
		int key = sum - arr[i];
		if (key == arr[i])
		{
			if (mp[key] > 1) return true;
		}
		else {
			if (mp[key] != 0) return true;
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
		int n, sum;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cin >> sum;
		cout << sumExists(arr, n, sum);
	}
	return 0;
}
