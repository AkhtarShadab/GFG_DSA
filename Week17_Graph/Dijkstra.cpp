#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;

class Make {
public:
	bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
	{
		return p1.second.second > p2.second.second;
	}
};
class Solution
{
public:
	//Function to return the minimum cost to react at bottom
	//right cell from top left cell.


	bool valid(int i, int j , int n)
	{
		if (i<n and j< n and i >= 0 and j >= 0) return 1;
		return 0;
	}
	int minimumCostPath(vector<vector<int>>& grid)
	{
		// Code here
		int n = grid.size();
		int vis[501][501], dis[501][501];
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 501; ++i)
		{
			for (int j = 0; j < 501; ++j)
			{
				dis[i][j] = 1e8;
			}
		}
		dis[0][0] = grid[0][0];
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Make> pq;

		pq.push({0, {0, dis[0][0]}});
		int dx[4] = { -1, 0, 1, 0};
		int dy[4] = {0, 1, 0, -1};
		while (pq.empty() == 0)
		{
			pair<int, pair<int, int>> p = pq.top();
			pq.pop();
			int x = p.first, y = p.second.first;
			if (vis[x][y] == 1) continue;
			vis[x][y] = 1;
			for (int i = 0; i < 4; ++i)
			{
				int nrow = x + dx[i];
				int ncol = y + dy[i];
				if (valid(nrow, ncol, n))
				{
					if (dis[nrow][ncol] > dis[x][y] + grid[nrow][ncol])
					{
						dis[nrow][ncol] = dis[x][y] + grid[nrow][ncol];
						pq.push({nrow, {ncol, dis[nrow][ncol]}});
					}
				}
			}

		}
		return dis[n - 1][n - 1];
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
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
