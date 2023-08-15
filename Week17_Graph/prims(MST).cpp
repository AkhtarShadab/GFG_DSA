#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;

class Make {
public:
	bool operator()(pair<int, int> &p1, pair<int, int> &p2)
	{
		return p1.second > p2.second;
	}
}
class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		// code here
		vector<bool> visited(V, false);
		priority_queue<pair<int, int>, vector<pair<int, int>>, Make> pq;
		pq.push({0, 0});
		int sum = 0;
		while (pq.empty() == 0)
		{
			auto  it = pq.top();
			int node = it.first;
			int wt = it.second;
			pq.pop();
			if (visited[node] == true)
			{
				continue
			}
			visited[node] = true;
			sum += wt;
			for (auto it : adj[node])
			{
				int adjnode = it[0];
				int edW = it[1];
				if (visited[adjnode] == false)
				{
					pq.push({adjnode, edW});
				}
			}
		}
		return sum;

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

		Solution obj;
		cout << obj.spanningTree(V, adj) << "\n";

	}
	return 0;
}
