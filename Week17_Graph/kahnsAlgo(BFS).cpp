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
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		// code here
		vector<int> indegree(V), ans;
		vector<bool> visited(V, false);
		for (int i = 0; i < V; ++i)
		{
			for (auto &x : adj[i])
			{
				indegree[x]++;
			}
		}
		// for (auto & x : indegree)
		// {
		// 	cout << x << " ";
		// }
		queue<int> q;
		for (int i = 0; i < V; ++i)
		{
			if (visited[i] == false and indegree[i] == 0)
			{
				q.push(i);
				visited[i] = true;
			}
		}
		while (q.empty() == 0)
		{
			int vertex = q.front();
			ans.push_back(vertex);
			q.pop();
			for (auto &x : adj[vertex])
			{
				indegree[x]--;
				if (indegree[x] == 0) {
					q.push(x);
					visited[x] = true;
				}
			}

		}

		return ans;
	}
};

int check(int V, vector <int> &res, vector<int> adj[]) {

	if (V != res.size())
		return 0;

	vector<int> map(V, -1);
	for (int i = 0; i < V; i++) {
		map[res[i]] = i;
	}
	for (int i = 0; i < V; i++) {
		for (int v : adj[i]) {
			if (map[i] > map[v]) return 0;
		}
	}
	return 1;
}
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
		int N, E;
		cin >> E >> N;
		int u, v;

		vector<int> adj[N];

		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		vector <int> res = obj.topoSort(N, adj);
		for (auto &x : res)
		{
			cout << x << " ";
		}
		// cout << check(N, res, adj) << endl;
	}
	return 0;
}
