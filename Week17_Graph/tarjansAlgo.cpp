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
	//Function to return a list of lists of integers denoting the members
	//of strongly connected components in the given graph.

	vector<vector<int>> ans;
	void DFS(int S, vector<int> adj[], vector<int> &visited, vector<int> &low, stack<int> &st, bool recst[])
	{
		static int time = 1;
		visited[S] = low[S] = time;
		time++;
		recst[S] = true;
		st.push(S);
		// cout << time << endl;
		for (auto &x : adj[S])
		{
			if (visited[x] == -1)
			{
				DFS(x, adj, visited, low, st, recst);
				low[S] = min(low[S], low[x]);
			}
			else if (recst[x] == true)
			{
				low[S] = min(low[S], visited[x]);
			}
		}

		if (visited[S] == low[S])
		{
			vector<int> check;
			while (st.top() != S)
			{
				check.push_back(st.top());
				recst[st.top()] = false;
				st.pop();

			}
			check.push_back(st.top());
			recst[st.top()] = false;
			st.pop();
			ans.push_back(check);
		}

	}
	vector<vector<int>> tarjans(int V, vector<int> adj[])
	{
		//code here
		vector<int> visited(V, -1), low(V, 1e8);
		stack<int> st;
		bool recst[V] = {false};
		for (int i = 0; i < V; ++i)
		{
			if (visited[i] == -1)DFS(i, adj, visited, low, st, recst);
		}
		for (auto &x : visited)
		{
			cout << x << " ";
		}
		cout << endl;
		for (auto &x : low)
		{
			cout << x << " ";
		}
		cout << endl;
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

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		vector<vector<int>> ptr = obj.tarjans(V, adj);

		for (int i = 0; i < ptr.size(); i++)
		{
			for (int j = 0; j < ptr[i].size(); j++)
			{
				if (j == ptr[i].size() - 1)
					cout << ptr[i][j];
				else
					cout << ptr[i][j] << " ";
			}
			cout << ',';
		}
		cout << endl;
	}

	return 0;
}
