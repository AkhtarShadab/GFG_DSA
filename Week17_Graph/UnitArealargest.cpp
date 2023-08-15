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
	//Function to find unit area of the largest region of 1s.
	void DFS(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visited, int &count)
	{
		int n = grid.size();
		int m = grid[0].size();
		visited[x][y] = true;
		count++;
		for (int i = -1; i < 2; ++i)
		{
			for (int j = -1; j < 2; ++j)
			{
				int nx = x + i;
				int ny = y + j;
				if (nx<n and nx >= 0 and ny<m and ny >= 0 and grid[nx][ny] == 1 and visited[nx][ny] == 0)
				{
					DFS(nx, ny, grid, visited, count);
				}

			}
		}
	}
	int findMaxArea(vector<vector<int>>& grid) {
		// Code here
		int n = grid.size();
		int m = grid[0].size();
		int count = 0, maxCount = 0;
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (visited[i][j] == false and grid[i][j] == 1)
				{
					DFS(i, j, grid, visited, count);
					if (count > maxCount) maxCount = count;
					count = 0;
				}
			}
		}
		return maxCount;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
