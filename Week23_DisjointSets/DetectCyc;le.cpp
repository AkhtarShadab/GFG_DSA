#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
struct hashFunction
{
	size_t operator()(const pair<int ,
	                  int> &x) const
	{
		return x.first ^ x.second;
	}
};
class Solution
{
public:
	//Function to detect cycle using DSU in an undirected graph.
	int find(int a, int par[], int rank[])
	{
		if (par[a] == a) return a;

		par[a] = find(par[a], par, rank);
		return par[a];
	}
	void union_( int a, int b, int par[], int rank1[])
	{
		//code here
		if (find(a, par, rank1) == find(b, par, rank1)) return;
		int par_a = find(a, par, rank1), par_b = find(b, par, rank1);
		if (rank1[a] < rank1[b]) par[par_a] = par_b ;
		else if (rank1[b] < rank1[a]) par[par_b] = par_a;
		else {
			par[par_b] = par_a;
			rank1[a]++;
		}
	}

	//Function to check whether 2 nodes are connected or not.

	int detectCycle(int V, vector<int>adj[])
	{
		// Code here
		int par[V], rank1[V];
		for (int i = 0; i < V; ++i)
		{
			par[i] = i;
			rank1[i] = 0;
		}
		unordered_set<pair<int, int>,
		              hashFunction> st;
		for (int i = 0; i < V; ++i)
		{
			for (auto &x : adj[i])
			{
				if (st.find({i, x}) == st.end()) st.insert({x, i});
			}
		}
		for (auto &x : st)
		{
			if (find(x.first, par, rank1) == find(x.second, par, rank1)) return 1;
			union_(x.first, x.second, par, rank1);
		}

		return 0;

	}
};

//{ Driver Code Starts.
int main() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--) {
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
		int ans = obj.detectCycle(V, adj);
		cout << ans << "\n";
	}
	return 0;
}
//