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
	//Function to find the shortest distance of all the vertices
	//from the source vertex S.
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
	{
		// Code here
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> ans(V, 1e9);
		ans[S] = 0;
		pq.push({0, S});
		// see visited implementation
		while (pq.empty() == 0)
		{
			auto p = pq.top();
			int node = p.second;
			int wt = p.first;
			pq.pop();
			for (auto &x : adj[node])
			{
				if (ans[x[0]] > wt + x[1])
				{
					ans[x[0]] = ans[node] + x[1];
					pq.push({ans[x[0]], x[0]});
				}
			}
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
		vector<vector<int>> adj[V];
		int i = 0;
		while (i++ < E) {
			int u, v, w;
			cin >> u >> v >> w;
			vector<int> t1, t2;
			t1.push_back(v);
			t1.push_back(w);
			adj[u].push_back(t1);
			t2.push_back(u);
			t2.push_back(w);
			adj[v].push_back(t2);
		}
		int S;
		cin >> S;

		Solution obj;
		vector<int> res = obj.dijkstra(V, adj, S);

		for (int i = 0; i < V; i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
