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
	int count = 0;
	void DFS(vector<int> adj[], vector<int> &visited, vector<int> &dis, int S, vector<bool> &ans, vector<int> &low, int parent)
	{
		visited[S] = 1;
		count++;
		dis[S] = count;
		low[S] = dis[S];
		int child = 0;
		for (auto &x : adj[S])
		{
			if (x == S) continue;
			if (visited[x] == 0)
			{
				DFS(adj, visited, dis, x, ans, low, S);
				low[S] = min(low[S], low[x]);
				if (low[x] >= dis[S] and parent != -1)
				{
					ans[S] = true;
				}
				child++;
			}
			else {
				low[S] = min(low[S], dis[x]);

			}
			if (child > 1 and parent == -1) ans[0] = true;
		}
	}

	vector<int> articulationPoints(int V, vector<int>adj[]) {
		// Code here
		vector<int> visited(V, 0), dis(V), low(V, 1e8);
		vector<bool> ans(V, false);
		DFS(adj, visited, dis, 0, ans , low, -1);
		for (auto &x : dis)
		{
			cout << x << " ";
		}
		cout << endl;
		for (auto &x : low)
		{
			cout << x << " ";
		}

		vector<int> res;
		for (int i = 0; i < V; ++i)
		{
			if (ans[i]) res.push_back(i);
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
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for (auto i : ans)cout << i << " ";
		cout << "\n";

	}
	return 0;
}
