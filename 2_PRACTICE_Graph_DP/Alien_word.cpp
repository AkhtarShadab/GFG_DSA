#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int n = min(s1.length(), s2.length());
            int j = 0;
            while (j < n)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
                j++;
            }
        }
        vector<int> indegree(K, 0);
        for (int i = 0; i < K; ++i)
        {
            for (auto &x : adj[i])
            {
                indegree[x]++;
            }
        }
        string ans;
        for (int i = 0; i < K; ++i)
        {
            if (indegree[i] == 0) ans.push_back('a' + i);
        }

        string check;
        for (int i = 0; i < ans.size(); ++i)
        {
            queue<int> q;
            q.push(ans[i] - 'a');
            while (!q.empty())
            {
                int node =  q.front();
                q.pop();
                for (auto &x : adj[node])
                {
                    indegree[x]--;
                    if (indegree[x] == 0) {
                        q.push(x);
                        check.push_back(x + 'a');
                    }
                }
            }
        }
        return ans + check;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //  cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if (f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}