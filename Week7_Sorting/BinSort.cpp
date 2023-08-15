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
void BinSort(bool arr[], int n)
{
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[index] == 0)
		{
			index++;
		}
		else {
			if (arr[i] == 0) {
				swap(arr[i], arr[index]);
				index++;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
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
		bool arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		BinSort(arr, n);

	}
	return 0;
}
