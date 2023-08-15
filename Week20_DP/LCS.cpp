#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence
int dp[1001][1001];
class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.

    int solve(int x, int y, string s1, string s2)
    {
        if (x == 0 || y == 0)
            return dp[x][y] = 0;
        if (dp[x][y] == -1)
        {
            // cout << "x" << endl;
            if (s1[x - 1] == s2[y - 1])
            {
                return dp[x][y] = 1 + solve(x - 1, y - 1, s1, s2);
            }
            else return dp[x][y] = max(solve(x - 1, y, s1, s2), solve(x, y - 1, s1, s2));
        }
        return dp[x][y];


    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        memset(dp, -1, sizeof(dp));
        // cout << dp[0][0] << endl;
        return solve(x, y , s1, s2);

    }
};


//{ Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        getchar();
        cin >> s1 >> s2;
        // cout << s1 << s2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}