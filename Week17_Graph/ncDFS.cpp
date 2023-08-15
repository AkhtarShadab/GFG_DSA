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
	// Function to return a list containing the DFS traversal of the graph.
	void DFS(vector<int> adj[], int s, vector<int> &ans, bool visited[])
	{
		visited[s] = true;
		ans.push_back(s);
		for (auto &x : adj[s])
		{
			if (visited[x] == false)
			{
				DFS(adj[], x, ans, visited);
			}
		}

	}
	vector<int> dfsOfGraph(int V, vector<int> adj[]) {
		// Code here
		bool visited[V];
		vector<int> ans;
		int i  = 0;
		while (i < V)
		{
			visited[i] = false;
			i++;

		}
		i = 0;
		while (i < V)
		{
			if (visited[i] == false)
				DFS(adj, i, ans, visited);
			i++;
		}
		return ans;
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
		// string s1;
		// cin>>s1;
		Solution obj;
		vector<int> ans = obj.dfsOfGraph(V, adj);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
