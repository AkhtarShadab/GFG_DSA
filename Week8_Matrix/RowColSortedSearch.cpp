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
bool search(vector<vector<int> > matrix, int n, int m, int x)
{
	// code here
	int i = 0, j = m - 1;
	while (i < n && j > -1)
	{
		if (matrix[i][j] == x) return 1;
		else if (matrix[i][j] < x) i++;
		else j--;
	}
	return 0;
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
	{	int n, m, x;
		cin >> n >> m >> x;
		vector<vector<int>> arr(n);
		for (int i = 0; i < n; ++i)
		{
			vector<int> rows(m);
			for (int j = 0; j < m; ++j)
			{
				cin >> rows[j];
			}
			arr[i] = rows;
		}
		cout << search(arr, n, m, x);

	}
	return 0;
}
