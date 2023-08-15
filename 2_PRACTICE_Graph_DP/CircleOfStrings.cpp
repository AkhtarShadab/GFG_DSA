#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isCircle(int N, vector<string> A)
    {
        // code here
        vector<int> degree(26, 0);
        vector<int> adj[26];
        for (int i = 0; i < N; ++i)
        {
            string S = A[i];
            adj[S[0] - 'a'].push_back(S[S.length() - 1] - 'a');
            degree[S[0] - 'a']++;
            degree[S[S.length() - 1] - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (degree[i] % 2) return 0;
        }
        vector<bool> visited(26, false);
        int start ;
        for (int i = 0; i < 26; ++i)
        {
            if (degree[i] != 0)
            {
                start = i;
                break;
            }
        }
        queue<int> Q;
        Q.push(start);
        visited[start] = true;
        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            for (auto &x : adj[node])
            {
                if (visited[x] == false)
                {
                    visited[x] = true;
                    Q.push(x);
                }
            }
        }
        for (int i = 0; i < 26; ++i)
        {
            if (visited[i] == false)
            {
                if (degree[i] != 0) return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++)
        {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(N, A) << endl;
    }
    return 0;
}