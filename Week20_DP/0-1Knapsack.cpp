#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
int dp[1001][1001];
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, int wt[], int val[], int n)
    {
        if (W == 0 || n == 0) return dp[n][W] = 0;
        if (dp[n][W] == -1)
        {
            if (wt[n - 1] > W) return dp[n][W] = solve(W, wt, val, n - 1);

            else
                return dp[n][W] = max(solve(W - wt[n - 1], wt, val, n - 1), solve(W, wt, val, n - 1));
        }
        return dp[n][W];
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        memset(dp, -1, sizeof(dp));
        int ans = solve(W, wt, val, n);
        return ans;

    }
};

//{ Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;

    }
    return 0;
}