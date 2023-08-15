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
void frequencyCount(vector<int>& arr, int N, int P)
{
	for (int i = 0; i < N; ++i)
	{
		arr[(arr[i] - 1) % (P + 1)] += P + 1;
	}
	for (int i = 0; i < N; ++i)
	{
		arr[i] /= (P + 1);
	}
	return;

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
		vector<int> arr(n);
		int maxval = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			maxval = max(maxval, arr[i]);
		}
		frequencyCount(arr, n, maxval);
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}


	}
	return 0;
}
