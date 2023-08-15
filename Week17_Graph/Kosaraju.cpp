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
	//Function to find number of strongly connected components in the graph.
	void DFS(vector<bool> &visited, vector<vector<int>> &adj, stack<int> &st, int i)
	{
		visited[i] = true;
		for (auto &x : adj[i])
		{
			if (visited[x] == false)
			{
				DFS(visited, adj, st, x);
			}
		}
		st.push(i);
	}
	void normDFS(vector<bool> &visited, vector<vector<int>> &adj, int i)
	{
		visited[i] = true;
		for (auto &x : adj[i])
		{
			if (visited[x] == false)
			{
				DFS(visited, adj, x);
			}
		}
	}
	int kosaraju(int V, vector<vector<int>>& adj)
	{
		//code here
		stack<int> st;
		vector<bool> visited(V, false);
		vector<vector<int>> adjt(V);
		for (int i = 0; i < V; ++i)
		{
			if (visited[i] == false)
			{
				DFS(visited, adj, st, x);
			}
		}
		for (int i = 0; i < V; ++i)
		{
			for (auto &x : adj[i])
			{
				adjt[x].push_back(i);
			}
		}
		int count = 0;
		for (int i = 0; i < V; ++i)
		{
			visited[i] = false;
		}
		while (st.empty() == 0)
		{
			int s = st.top();
			st.pop();
			if (visited[s] == false) {
				count++;
				normDFS(visited, adjt, s);
			}
		}
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

		vector<vector<int>> adj(V);

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		cout << obj.kosaraju(V, adj) << "\n";

	}
	return 0;
}
