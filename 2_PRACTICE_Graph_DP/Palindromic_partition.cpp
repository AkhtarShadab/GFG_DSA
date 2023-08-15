#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dp[501][501];
class Solution {
public:
    bool isPalindrome(string s, int i, int j)
    {
        int n = j - i + 1;
        for (int k = 0; k < n / 2; ++k)
        {
            if (s[k + i] != s[j - k]) return false;
        }
        return true;
    }
    int f(string s, int i, int j)
    {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (isPalindrome(s, i, j))
        {
            return dp[i][j] =  0;
        }
        int ans = INT_MAX;
        for (int k = i; k < j; ++k)
        {
            int temp1, temp2, temp;
            if (dp[i][k] != -1 ) temp1 = dp[i][k];
            else temp1 = f(s, i, k);
            if (dp[k + 1][j] != -1)temp2 = dp[k + 1][j];
            else temp2 = f(s, k + 1, j);
            temp = temp1 + temp2 + 1;
            ans = min(ans, temp);

        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        memset(dp, -1, sizeof(dp));
        int n = str.size();
        return f(str, 0, n - 1);

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
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}