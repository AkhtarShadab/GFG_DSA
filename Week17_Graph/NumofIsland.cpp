#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;

class Solution {
public:
	void BFS(int i, int j, vector<vector<char>> grid, vector<vector<bool>> &vis)
	{
		int n = grid.size();
		int m = grid[0].size();
		queue<pair<int, int>> q;
		q.push({i, j});
		int rown[4] = { -1, 0, 1, 0};
		int coln[4] = {0, 1, 0, -1};
		int rowd[4] = { -1, 1, 1, -1};
		int cold[4] = {1, 1, -1, -1};
		vis[i][j] = true;
		while (q.empty() == 0)
		{
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nrow = r + rown[i];
				int ncol = c + coln[i];
				int drow = r + rowd[i];
				int dcol = c + cold[i];
				if (nrow >= 0 and nrow<n and ncol >= 0 and ncol < m and vis[nrow][ncol] == false and grid[nrow][ncol] == '1')
				{
					vis[nrow][ncol] = true;
					q.push({nrow, ncol});
				}
				if (drow >= 0 and drow<n and dcol >= 0 and dcol < m and vis[drow][dcol] == false and grid[drow][dcol] == '1')
				{
					vis[drow][dcol] = true;
					q.push({drow, dcol});
				}
			}
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		// Code here
		int n = grid.size();
		int m = grid[0].size();

		vector<vector<bool>> vis(n, vector<bool>(m, false));

		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (vis[i][j] == false and grid[i][j] == '1')
				{
					count ++;
					BFS(i, j, grid, vis);

				}
			}
		}
		return count;
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
		vector<vector<char>> grid(n, vector<char>(m, '#'));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans << '\n';

	}
	return 0;
}
