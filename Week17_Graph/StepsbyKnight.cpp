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
	//Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n)
	{
		// Code here5
		vector<vector<int>> visited(n, vector<int>(n, 0));
		visited[KnightPos[0] - 1][KnightPos[1] - 1] = 1;
		queue<pair<pair<int, int>, int>> q;
		q.push({{KnightPos[0] - 1, KnightPos[1] - 1}, 0});

		int rowc[4] = { -2, 1, 2, -1};
		int colc[4] = {1, 2, -1, -2};
		int rowa[4] = { -2, -1, 2, 1};
		int cola[4] = { -1, 2, 1, -2};

		while (q.empty() == 0)
		{
			int r = q.front().first.first;
			int c = q.front().first.second;
			int t = q.front().second;
			q.pop();
			if (r == TargetPos[0] - 1 and c == TargetPos[1] - 1)
			{
				return t;
			}
			for (int i = 0; i < 4; ++i)
			{
				int nrow = r + rowc[i];
				int ncol = c + colc[i];
				if (ncol >= 0 and ncol<n and nrow >= 0 and nrow < n and visited[nrow][ncol] == 0)
				{
					q.push({{nrow, ncol}, t + 1});
					visited[nrow][ncol] = 1;
				}
			}
			for (int i = 0; i < 4; ++i)
			{
				int nrow = r + rowa[i];
				int ncol = c + cola[i];
				if (ncol >= 0 and ncol<n and nrow >= 0 and nrow < n and visited[nrow][ncol] == 0)
				{
					q.push({{nrow, ncol}, t + 1});
					visited[nrow][ncol] = 1;
				}
			}
		}
		return -1;

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
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans << "\n";
	}
	return 0;
}
