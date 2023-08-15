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

int findMinOpeartion(vector<vector<int> > matrix, int n)
{
	// code here
	vector<int> rowsum(n), colsum(n);
	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = 0; j < n; ++j)
		{
			sum += matrix[i][j];
		}
		rowsum[i] = sum;
	}
	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += matrix[j][i];
		}
		colsum[i] = sum;
	}
	sort(colsum.begin(), colsum.end());
	sort(rowsum.begin(), rowsum.end());

	int maxval = max(rowsum[n - 1], colsum[n - 1]), sum = 0;
	for (int i = 0; i < n; ++i)
	{
		colsum[i] = maxval - colsum[i];
		sum += colsum[i];
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
	{	int n;
		cin >> n;
		vector<vector<int>> arr(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> arr[i][j];
			}
		}
		cout << findMinOpeartion(arr, n);

	}
	return 0;
}
