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
vector<int> leaders(int arr[], int n)
{
	vector<int> ans;
	int Rmax = INT_MIN;
	for (int i = n - 1; i > -1; i--)
	{
		if (arr[i] >= Rmax)
		{
			ans.push_back(arr[i]);
			Rmax = arr[i];
		}
	}
	int size = ans.size();
	for (int i = 0; i < size / 2; ++i)
	{
		int temp;
		temp = ans[i];
		ans[i] = ans[size - 1 - i];
		ans[size - 1 - i] = temp;
	}
	return ans;
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
		vector<int> ans = leaders(arr, n);
		for (int i = 0; i < ans.size(); ++i)
		{
			cout << ans[i] << " ";
		}
	}
	return 0;
}
