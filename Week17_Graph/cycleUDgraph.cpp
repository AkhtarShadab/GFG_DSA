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
	// Function to detect cycle in an undirected graph.
	bool DFS(int source, vector<bool> &rescst, vector<bool> &visited, vector<int> adj[])
	{
		rescst[source] = true;
		visited[source] = true;
		for (auto &x : adj[source])
		{
			if (visited[x] == false  and DFS(x, rescst, visited, adj))
				return true;
			else if (rescst[x] == true) return true;
		}
		rescst[source] = false;
		return false;
	}
	bool isCycle(int V, vector<int> adj[]) {
		// Code here
		vector<bool> visited(V, false), rescst(V, false);
		for (int i = 0; i < V; ++i)
		{	if (visited[i] == false)
			{

				if (	DFS(i, rescst, visited, adj) == true) return true;
			}

		}
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
		int V, E;
		cin >> V >> E;
		vector<int> adj[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if (ans)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}
