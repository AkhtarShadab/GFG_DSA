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
	//Function to find whether a path exists from the source to destination.
	bool is_Possible(vector<vector<int>>& grid)
	{
		//code here

		int n  = grid.size();
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == 1)
				{
					q.push({i, j});
					visited[i][j] = true;
				}
			}
		}
		while (q.empty() == 0)
		{
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			if (grid[r][c] == 2) return 1;
			int drow[4] = { -1, 0, 1, 0};
			int dcol[4] = {0, 1, 0, -1};
			for (int i = 0; i < 4; ++i)
			{
				int nrow = r + drow[i];
				int ncol = c + dcol[i];
				if (nrow<n and nrow >= 0 and ncol<n and ncol >= 0 and grid[nrow][ncol] != 0 and visited[nrow][ncol] == false)
				{
					visited[nrow][ncol] = true;
					q.push({nrow, ncol});
				}
			}
		}
		return 0;

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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
