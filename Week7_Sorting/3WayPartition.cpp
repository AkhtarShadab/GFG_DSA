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
void threeWayPartition(vector<int>& arr, int a, int b)
{
	int pivot = a;
	int index = -1;
	int temp = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] < pivot)
		{
			++index;
			temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
		}
	}
	pivot = b;
	index = -1;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] <= pivot)
		{
			++index;

			temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
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
		int n, a, b;
		cin >> n >> a >> b;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		threeWayPartition(arr, a, b);
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}
	}
	return 0;
}
