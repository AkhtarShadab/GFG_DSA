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
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X)
	{
		// code here
		vector<bool> visited(V, false);
		queue<pair<int, int>> q;
		q.push({0, 0});
		visited[0] = true;
		while (q.empty() == 0)
		{
			int vertex = q.front().first;
			int level = q.front().second;
			q.pop();
			for (auto &x : adj[vertex])
			{
				if (x == X) return level + 1;
				if (visited[x] == false)q.push({x, level + 1});
				visited[x] = true;
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
		int V, E, X;
		cin >> V >> E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cin >> X;

		Solution obj;
		cout << obj.nodeLevel(V, adj, X) << "\n";
	}
	return 0;
}
