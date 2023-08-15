#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dp[1001][1001];

class Solution {
public:
    int f(i, W, int val[], int wt[])
    {
        if (W == 0 || i == 0) return dp[i][W] = 0;
        if (dp[i][W] != -1) return dp[i][W];

        int notTake = f(i - 1, W, val, wt);
        int take = 0;
        if (wt[i - 1] <= W)
            take = f(i, W - wt[i - 1], val, wt) + val[i - 1];

        return dp[i][W] = max(take, notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return f(n, W, val, wt);

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
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}