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
    // Function to return Breadth First Traversal of given graph.
    void BFS(vector<int> adj[], int s, bool visited[], vector<int> &ans)
    {
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (q.empty() == 0)
        {
            int val = q.front();
            q.pop();
            ans.push_back(val);
            for (auto &x : adj[val])
            {
                if (visited[x] == false)
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }

    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool visited[V];
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;

        }
        BFS(adj, 0, visited, ans);
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
        cin >> V >>

            E;

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
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;

    }
    return 0;
}
