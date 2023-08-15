#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dp[200][200][2];
class Solution {
public:
    int f(string S, int i, int j, bool isTrue)
    {
        if (i > j) return 0;
        if (i == j)
        {
            if (isTrue) return S[i] == 'T' ? 1 : 0 ;
            return S[i] == 'F' ? 1 : 0;
        }

        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        int ans = 0;
        for (int k = i + 1; k < j; k += 2)
        {
            int lT, lF, rT, rF;
            if (dp[i][k - 1][true] != -1) lT = dp[i][k - 1][true];
            else lT = f(S, i, k - 1, true);
            if (dp[i][k - 1][false] != -1) lF = dp[i][k - 1][false];
            else lF = f(S, i, k - 1, false);
            if (dp[k + 1][j][true] != -1) rT = dp[k + 1][j][true];
            else rT = f(S, k + 1, j, true);
            if (dp[k + 1][j][false] != -1) rF = dp[k + 1][j][false];
            else rF = f(S, k + 1, j, false);

            if (S[k] == '&')
            {
                if (isTrue)
                {
                    ans += lT * rT;
                }
                else ans += lF * rT + rF * lT + rF * lF;
            }
            else if (S[k] == '|')
            {
                if (isTrue)
                {
                    ans += lT * rT + lT * rF + lF * rT;
                }
                else ans += lF * rF;
            }
            else {
                if (isTrue)
                {
                    ans += lF * rT + rF * lT;
                }
                else ans += lF * rF + lT * rT;
            }

        }
        return dp[i][j][isTrue] = ans % 1003;
    }
    int countWays(int N, string S) {
        // code here
        int n  = S.size();
        memset(dp, -1, sizeof(dp));
        return f(S, 0, n - 1, true);
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
        string S;
        cin >> S;

        Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    return 0;
}