#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dp[101][101];
class Solution {
public:
    int f(int arr[], int i, int j)
    {
        if (i + 1 == j) return dp[i][j] 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; ++k)
        {
            int temp1, temp2;
            if (dp[i][k] != -1) temp1 = dp[i][k];
            else temp1 = f(arr, i, k);
            if (dp[k][j] != -1) temp2  = dp[k][j];
            else temp2 = f(arr, k, j);
            ans = min(ans, temp1 + temp2 + arr[i] * arr[j] * arr[k]);
        }
        return dp[i][j] =  ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return f(arr, 0, N - 1);

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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}