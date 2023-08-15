#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

// Main Sol
static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;
}
long long maxTip(int A[], int B[], int n, int x, int y) {
    // code here

    pair<int, int> arr[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i].first = abs(A[i] - B[i]);
        arr[i].second = i;
    }
    sort(arr, arr + n, cmp);
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (A[arr[i].second] > B[arr[i].second])
        {
            if (x > 0)
            {
                ans += A[arr[i].second];
                x--;
            }
            else
            {
                ans += B[arr[i].second];
                y--;
            }
        }
        else {
            if (y > 0)
            {
                ans += B[arr[i].second];
                y--;
            }
            else {
                ans += A[arr[i].second];
                x--;
            }
        }
    }

    return ans;

}

// See for DP

class Solution {
public:

    long long f(int A[], int B[], int i, int x, int y, vector<vector<long long>> &dp)
    {

        if (i <= 0) return 0;

        if (x == 0 and y == 0) return 0;

        if (dp[x][y] != -1) return dp[x][y];

        if (x > 0 and y > 0)
        {
            return dp[x][y] = max(A[i - 1] + f(A, B, i - 1, x - 1, y, dp), B[i - 1] + f(A, B, i - 1, x, y - 1, dp));
        }
        else if (x > 0) return dp[x][y] = A[i - 1] + f(A, B, i - 1, x - 1, y, dp);
        else if (y > 0) return dp[x][y] = B[i - 1] + f(A, B, i - 1, x, y - 1, dp);
    }
    long long maxTip(int A[], int B[], int n, int x, int y) {
        vector<vector<long long>> dp(x + 1, vector<long long>(y + 1, -1));
        // memset(dp, -1, sizeof(dp));
        return f(A, B, n , x, y, dp);
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
        int n, x, y;
        cin >> n >> x >> y;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        Solution obj;
        auto ans = obj.maxTip(a, b, n, x, y);
        cout << ans << "\n";
    }
    return 0;
}
