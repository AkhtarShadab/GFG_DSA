#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++


/**
 *  ith value in adj vector contains information between the node connected to it and weight between them.
 *  Example. for a value 2 3 1, Node 2 and Node 3 has weight 1. adj[2] = {3,1} and adj[3] = {2,1}.
 *  n -> number of nodes
 *  m -> total number of edges
 *  return the mst value
*/

struct hashFunction
{
    size_t operator()(const pair<int ,
                      int> &x) const
    {
        return x.first ^ x.second;
    }
};
struct Edge {
    int v1, v2;
    long long int wt;

    Edge(int V1, int V2, int Wt)
    {
        v1 = V1;
        v2 = V2;
        wt = Wt;
    }
};
//Function to find the minimum spanning tree value using Kruskal.
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
bool cmp(Edge &a, Edge &b)
{
    return a.wt < b.wt;
}
long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m)
{
    vector<Edge> v;
    unordered_set<pair<int, int>, hashFunction > st;
    for (int i = 1; i <= n; ++i)
    {
        for (auto &x : adj[i])
        {
            int v1 = i;
            int v2 = x.first;
            if (st.find({v1, v2}) == st.end())
            {
                Edge l(i, x.first, x.second);
                st.insert({v2, v1});
                v.push_back(l);
            }
        }
    }


    sort(v.begin(), v.end(), cmp);
    // for (auto &x : v)
    // {
    //     cout << x.v1 << " " << x.v2 << " " << x.wt << endl;
    // }
    int par[n + 1], rank[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        par[i] = i;
        rank[i] = 0;
    }
    long long int res = 0;
    for (int i = 0, s = 0;  s < n - 1; ++i)
    {
        Edge e = v[i];
        int x = find(e.v1, par, rank);
        int y = find(e.v2, par, rank);
        if (x != y)
        {
            res += e.wt;
            s++;
            union_(e.v1, e.v2, par, rank);
        }
    }
    return res;

}

//{ Driver Code Starts.

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    vector<pair<int, long long int>> adj[100009];

    while (t--) {

        int n, m;
        cin >> n >> m;

        int u, v;
        long long w;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        cout << kruskalDSU(adj, n, m) << endl;

        for (int i = 0; i <= n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}