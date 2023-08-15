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
typedef struct coordinates {
	int x;
	int y;
} coordinates;
void booleanMatrix(vector<vector<int>> &matrix)
{
	// code here
	vector<coordinates> coord;
	int n = matrix.size(), m = matrix[0].size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrix[i][j] == 1)
			{
				coordinates m;
				m.x = i;
				m.y = j;
				coord.push_back(m);
			}
		}
	}
	for (int i = 0; i < coord.size(); ++i)
	{
		int r = coord[i].x;
		int c = coord[i].y;
		for (int j = r; j < n; ++j)
		{
			matrix[j][c] = 1;
		}
		for (int k = c; k < m; ++k)
		{
			matrix[r][k] = 1;
		}
		for (int l = r; l > -1; --l)
		{
			matrix[l][c] = 1;
		}
		for (int o = c; o > -1; --o)
		{
			matrix[r][o] = 1;
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
		booleanMatrix(arr);
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
