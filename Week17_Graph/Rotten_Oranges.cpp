#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;

class Solution
{
public:
	//Function to find minimum time required to rot all oranges.
	int orangesRotting(vector<vector<int>>& grid) {
		// Code here
		int n = grid.size();
		int m = grid[0].size();

		queue < pair<pair<int, int>, int>> q;
		vector<vector<int>> visited(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] == 2)
				{
					q.push({{i, j}, 0});
					visited[i][j] = 2;
				}
			}
		}
		int tm = 0;
		int drow[4] = { -1, 0, 1, 0};
		int dcol[4] = {0, 1, 0, -1};
		while (q.empty() == 0)
		{
			int row = q.front().first.first;
			int col = q.front().first.second;
			int t = q.front().second;
			tm = max(tm, t);
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nrow = row + drow[i];
				int ncol = col + dcol[i];

				if (nrow<n and nrow >= 0 and ncol<m and ncol >= 0 and visited[nrow][ncol] != 2
				        and grid[nrow][ncol] == 1)
				{
					q.push({{nrow, ncol}, t + 1});
					visited[nrow][ncol] = 2;
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (grid[i][j] == 1 and visited[i][j] != 2)
				{
					return -1;
				}
			}
		}
		return tm;
	}
};

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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";

	}
	return 0;
}
