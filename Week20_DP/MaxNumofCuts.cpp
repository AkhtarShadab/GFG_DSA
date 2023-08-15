#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
int dp[10001];
class Solution
{
public:
    //Function to find the maximum number of cuts.

    int solve(int n, int x, int y, int z)
    {
        if (n == 0 ) return 0;
        if (n < 0) return INT_MIN;
        if (dp[n] == -1)
        {
            return dp[n] = max(solve(n - x, x, y, z) + 1, max(solve(n - y, x, y, z) + 1, solve(n - z, x, y, z) + 1));
        }
        return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp, -1, sizeof(dp));
        int ans = solve(n, x, y, z);
        if (ans < 0) return 0;
        return ans;



    }
};

//{ Driver Code Starts.
int main() {

    //taking testcases
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;

    }

    return 0;
}