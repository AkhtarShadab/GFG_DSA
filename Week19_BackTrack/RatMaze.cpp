#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
void print(int n, vector<int> sol[]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
void solve(int n, vector<int> maze[]);
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
		vector<int> maze[n];
		for (int i = 0; i < n; i++) {
			maze[i].assign(n, 0);
			for (int j = 0; j < n; j++) cin >> maze[i][j];
		}

		solve(n, maze);

	}
	return 0;
}

bool isSafe(int i, int j, int N, vector<int> maze[])
{
	return (i < N and j < N and maze[i][j] != 0);
}
bool recur(int i , int j , vector<int> maze[], int N, vector<vector<int>> &ans )
{

	if (i == N - 1 and j == N - 1)
	{
		ans[i][j] = 1;
		return true;
	}
	if (isSafe(i, j, N, maze))
	{
		ans[i][j] = 1;
		for (int k = 1; k <= maze[i][j]; ++k)
		{
			if (recur(i, j + k, maze, N, ans)) return true;
			if (recur(i + k, j, maze, N, ans)) return true;
		}
		ans[i][j] = 0;
	}
	return false;


}

void solve(int N, vector<int> maze[])
{
	// write code here
	vector<vector<int>> ans(N, vector<int> (N, 0));

	if (recur(0, 0, maze, N, ans)) {
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}

	}
	else cout << -1;


}