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
void reverseCol(vector<vector<int> > &matrix)
{
	// code here
	int n = matrix.size(), m = matrix[0].size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m / 2; ++j)
		{
			swap(matrix[i][j], matrix[i][m - 1 - j]);
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>> arr(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> arr[i][j];
			}
		}
		reverseCol(arr);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

	}
	return 0;
}
