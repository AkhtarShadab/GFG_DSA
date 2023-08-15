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
	// Function to determine if graph can be coloured with at most M colours such
	// that no two adjacent vertices of graph are coloured with same colour.
	bool isSafe(int n, int col[], bool graph[101][101], int node, int color)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i != node and graph[node][i] == 1 and col[i] == color) return false;
		}
		return true;
	}
	bool solve(int node, int n, int m, bool graph[101][101], int col[])
	{
		if (node == n) return true;

		for (int i = 1; i <= m ; i++)
		{
			if (isSafe(n, col, graph, node, i))
			{
				col[node] = i;
				if (solve(node + 1, n, m, graph, col)) return true;
				col[node] = 0;
			}
		}

		return false;
	}
	bool graphColoring(bool graph[101][101], int m, int n) {
		// your code here
		int col[n] = {0};
		if (solve(0, n, m, graph, col)) return true;
		return false;
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
		int n, m, e;
		cin >> n >> m >> e;
		int i;
		bool graph[101][101];
		for (i = 0; i < n; i++) {
			memset(graph[i], 0, sizeof(graph[i]));
		}
		for (i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			graph[a - 1][b - 1] = 1;
			graph[b - 1][a - 1] = 1;
		}
		Solution ob;
		cout << ob.graphColoring(graph, m, n) << endl;
	}
	return 0;
}
