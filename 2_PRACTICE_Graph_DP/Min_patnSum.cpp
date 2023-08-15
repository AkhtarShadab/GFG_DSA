#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int dp[N][N];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < N; i++)
        {
            dp[0][i] = Matrix[0][i];
        }
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = max(Matrix[i][j] + dp[i - 1][j], Matrix[i][j] + dp[i - 1][j + 1]);
                }
                else if (j == N - 1)
                {
                    dp[i][j] = max(Matrix[i][j] + dp[i - 1][j], Matrix[i][j] + dp[i - 1][j - 1]);
                }
                else
                {
                    dp[i][j] = max(Matrix[i][j] + dp[i - 1][j], max(Matrix[i][j] + dp[i - 1][j + 1], Matrix[i][j] + dp[i - 1][j - 1]));
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < N; ++i)
        {
            ans = max(ans, dp[N - 1][i]);
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
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
}