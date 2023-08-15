
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
vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m)
{
	// code here
	vector<int> ans;
	if (m == 0)
		return ans;
	if (m == 1 || n == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				ans.push_back(matrix[i][j]);
			}
		}
		return ans;
	}

	vector<vector<bool> > seen(n, vector<bool>(m, false));
	int horizon[] = { 0, 1, 0, -1 };
	int Vertic[] = { 1, 0, -1, 0 };

	int x = 0, y = 0, di = 0;
	for (int i = 0; i < 2 * m + 2 * n - 4; i++) {
		ans.push_back(matrix[x][y]);
		seen[x][y] = true;
		int newX = x + horizon[di];
		int newY = y + Vertic[di];

		if (0 <= newX && newX < n && 0 <= newY && newY < m
		        && !seen[newX][newY]) {
			x = newX;
			y = newY;
		}
		else {
			di = (di + 1) % 4;
			x += horizon[di];
			y += Vertic[di];
		}
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
		int n, m;
		cin >> n >> m;
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
		vector<int> ans = boundaryTraversal(arr, n, m);
		for (auto& x : ans)
		{
			cout << x << " ";
		}

	}
	return 0;
}
