#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
typedef struct my {
	int row, col, val;
} my;
class Solution
{
public:
	//Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
		// Code here
		int n = grid.size();
		int m = grid[0].size();

		vector<vector<int>> visited(n, vector<int>(m, 0));
		vector<vector<int>> res(n, vector<int>(m, 0));
		queue<my> q;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++i)
			{
				if (grid[i][j] == 1)
				{
					visited[i][j] == 1;
					my p;
					p.row = i;
					p.col = j;
					p.val = 0;
					q.push(p);

				}
				else visited[i][j] = 0;
			}
		}

		int drow[] = { -1, 0, 1, 0};
		int dcol[] = {0, 1, 0, -1};

		while (q.empty() == 0)
		{
			my curr = q.front();
			q.pop();
			int row = curr.row;
			int col = curr.col;
			int val = curr.val;
			res[row][col] = val;
			for (int i = 0; i < 4; ++i)
			{
				int nrow = drow[i] + row;
				int ncol = dcol[i] + col;
				if (nrow >= 0 and nrow<n and ncol >= 0 and ncol < m and visited[nrow][ncol] == 0)
				{
					visited[nrow][ncol] = 1;
					my c;
					c.row = nrow;
					c.col = ncol;
					c.val = val + 1;
					q.push(c);
				}
			}
		}
		return res;

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
		vector<vector<int>> ans = obj.nearest(grid);
		for (auto i : ans) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << "\n";
		}

	}
	return 0;
}
