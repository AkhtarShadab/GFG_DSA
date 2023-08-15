#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
int dp[201][201];
class Solution
{
public:
    //Function to find minimum number of attempts needed in
    //order to find the critical floor.
    int solve(int n, int k)
    {
        if (n == 1) return dp[n][k] = k;
        if (k == 1) return dp[n][k] = 1;
        if (k == 0) return dp[n][k] = 0;
        if (dp[n][k] == -1)
        {
            for (int i = 1; i <= k; ++i)
            {
                if (i == 1) dp[n][k] = max(solve(n - 1, i - 1), solve(n, k - i)) + 1;
                else dp[n][k] = min( max(solve(n - 1, i - 1), solve(n, k - i)) + 1, dp[n][k]);
            }
        }
        return dp[n][k];
    }
    int eggDrop(int n, int k)
    {
        // your code here
        memset(dp, -1, sizeof(dp));
        return solve(n, k);

    }
};

//{ Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        //calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}