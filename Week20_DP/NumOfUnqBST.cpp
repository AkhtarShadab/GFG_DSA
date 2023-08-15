#include<bits/stdc++.h>
using namespace std;
#define mod (int)(1e9+7)

// } Driver Code Ends
class Solution
{
public:
    //Function to return the total number of possible unique BST.
    int numTrees(int N)
    {
        // Your code here

        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {


                int val = (dp[j] * dp[i - j - 1]) % mod;
                dp[i] = (dp[i] + val) % mod;
            }
        }
        return dp[N];
    }
};

//{ Driver Code Starts.

int main() {

    //taking total testcases
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {

        //taking total number of elements
        int n;
        cin >> n;
        Solution ob;
        //calling function numTrees()
        cout << ob.numTrees(n) << "\n";
    }
}