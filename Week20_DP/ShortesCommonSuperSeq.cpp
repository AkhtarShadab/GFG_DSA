#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
int dp[101][101];

class Solution
{
public:
    //Function to find length of shortest common supersequence of two strings.

    int lcs(string X, string Y, int m , int n)
    {
        if (m == 0 || n == 0) {
            return dp[m][n] = 0;

        }
        if (dp[m][n] == -1)
        {
            if (X[m - 1] == Y[n - 1]) {
                return dp[m][n] = lcs(X, Y, m - 1, n - 1) + 1;
            }
            else return dp[m][n] = max(lcs(X, Y, m - 1, n), lcs(X, Y, m, n - 1));
        }
        return dp[m][n];
    }

    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        memset(dp, -1, sizeof(dp));
        int val = lcs(X, Y, m, n);
        return m + n - val;
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

    //taking total testcases
    cin >> t;
    while (t--) {
        getchar();
        string X, Y;
        //taking String X and Y
        cin >> X >> Y;

        //calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size()) << endl;
    }
    return 0;
}