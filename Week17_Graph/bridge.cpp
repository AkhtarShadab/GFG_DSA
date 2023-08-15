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
	//Function to find if the given edge is a bridge in graph.

	int count = 0;
	bool check(int a, int b, int c, int d)
	{
		if ((a == c and b == d) or (a == d and b == c) )
			return true;
		return false;
	}
	vector<pair<int, int>> ans;
	void DFS(vector<int> adj[], vector<int> &visited, vector<int> &dis, int S, vector<int> &low, int parent)
	{
		visited[S] = 1;
		dis[S] = low[S] = ++count;
		for (auto &x : adj[S])
		{
			if (visited[x] == 0)
			{
				DFS(adj, visited, dis, x, low, S);
			}
			if (x != parent) low[S] = min(low[x], low[S]);
			if (low[x] > dis[S])
			{
				ans.push_back({x, S});

			}
		}
	}

	int isBridge(int V, vector<int> adj[], int c, int d) {
		// Code here
		vector<int> visited(V, 0), dis(V), low(V, 1e8);
		for (int i = 0; i < V; ++i)
		{
			if (visited[i] == 0)DFS(adj, visited, dis, i, low, -1);
		}
		for (auto &x : ans)
		{
			if (check(x.first, x.second, c, d)) return 1;
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
	{	int V, E;
		cin >> V >> E;
		vector<int> adj[V];
		int i = 0;
		while (i++ < E) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back (v);
			adj[v].push_back (u);
		}

		int c, d;
		cin >> c >> d;

		Solution obj;
		cout << obj.isBridge(V, adj, c, d) << "\n";

	}
	return 0;
}
