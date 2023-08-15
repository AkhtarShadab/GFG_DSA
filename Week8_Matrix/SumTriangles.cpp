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
vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
{
	// code here
	int sumup = 0, sumlow = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			sumlow += matrix[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			sumup += matrix[i][j];
		}
	}
	return {sumup, sumlow};
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
		vector<vector<int>> arr(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{

			for (int j = 0; j < n; ++j)
			{
				cin >> arr[i][j];
			}

		}
		vector<int> ans = sumTriangles(arr, n);
		for (auto& x : ans)
		{
			cout << x << " ";
		}
	}
	return 0;
}
