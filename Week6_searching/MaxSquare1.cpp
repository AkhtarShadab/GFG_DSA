#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = -1;
        for (int i = 0; i < n; ++i)
        {
            dp[i][0] = mat[i][0];
            ans = max(ans, dp[i][0]);
        }
        for (int i = 0; i < m; ++i)
        {
            dp[0][i] = mat[0][i];
            ans = max(ans, dp[0][i]);
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if (mat[i][j] != 0) dp[i][j] = mat[i][j] + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                ans = max(ans, dp[i][j]);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
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
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}