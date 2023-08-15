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
vector<int> largestAndSecondLargest(int sizeOfArray, int arr[])
{
	int max1 = -1, max2 = -1;
	for (int i = 0; i < sizeOfArray; ++i)
	{
		max1 = max(max1, arr[i]);
	}
	for (int i = 0; i < sizeOfArray; ++i)
	{
		if (arr[i] != max1)
		{
			max2 = max(max2, arr[i]);
		}
	}

	vector<int> ans;
	ans.push_back(max1);
	ans.push_back(max2);
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
		vector<int> v;
		v = largestAndSecondLargest(n, arr);
		for (auto x : v)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
