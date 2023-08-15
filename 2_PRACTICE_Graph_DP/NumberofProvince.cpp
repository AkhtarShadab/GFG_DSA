#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public: void DFS(int x, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[x] = true;

        for (int i = 0; i < adj.size(); ++i)
        {

            if (visited[i] == false and adj[x][i] == 1) DFS(i, adj, visited);

        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V, false);
        int provinces = 0;
        for (int i = 0; i < V; ++i)
        {
            if (visited[i] == false)
            {
                provinces++;
                DFS(i, adj, visited);
            }
        }
        return provinces;

    }
};

//{ Driver Code Starts.

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }


        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}