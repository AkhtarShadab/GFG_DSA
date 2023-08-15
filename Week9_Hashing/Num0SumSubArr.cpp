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
long long int findSubarray(vector<long long int> &arr, int n ) {
	//code here
	for (int i = 0; i < n; ++i)
	{
		if (i) arr[i] += arr[i - 1];
	}
	unordered_map<long long int, long long int> mp;
	for (int i = 0; i < n; ++i)
	{
		mp[arr[i]]++;
	}
	long long int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == 0) {
			count += mp[0];
			mp[0]--;
		}
		else if (mp[arr[i]] > 1)
		{
			count += --mp[arr[i]];

		}

	}
	return count;
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
		vector<long long int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cout << findSubarray(arr, n);

	}
	return 0;
}
