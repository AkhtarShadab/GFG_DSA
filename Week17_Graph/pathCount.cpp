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
	// Function to count paths between two vertices in a directed graph.
	void DFS(int &count, vector<int> adj[], int destination, vector<bool> &recst, int source)
	{
		if (source == destination)
		{
			count++;
			recst[destination]  = false;
			return;
		}

		for (auto &x : adj[source])
		{
			if (recst[x] == false) {
				recst[x] = true;
				DFS(count, adj, destination, recst, x);
			}
		}
		recst[source] = false;

	}
	int countPaths(int V, vector<int> adj[], int source, int destination) {
		// Code here
		int count = 0;
		vector<bool> recst(V, false);

		recst[source] = true;
		DFS(count, adj, destination, recst, source);

		return count;
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
			// adj[v].push_back(u);
		}
		int source, destination;
		cin >> source >> destination;
		Solution obj;
		cout << obj.countPaths(V, adj, source, destination) << endl;
	}
	return 0;
}
