#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += M[0][j];
        }
        if (n == 1) return sum;
        for (int j = 1; j < m; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                if (i == 0) {
                    M[i][j] = M[i][j] + max(M[i][j - 1], M[i + 1][j - 1]);
                }
                else if (i != n - 1)
                {
                    M[i][j] = M[i][j] + max(M[i][j - 1], max(M[i + 1][j - 1], M[i - 1][j - 1]));
                }
                else
                {
                    M[i][j] = M[i][j] + max(M[i][j - 1], M[i - 1][j - 1]);
                }
            }
        }
        int ans = M[0][m - 1];
        for (int i = 1; i < n; ++i)
        {
            ans = max(M[i][m - 1], ans);
        }
        return ans;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
}