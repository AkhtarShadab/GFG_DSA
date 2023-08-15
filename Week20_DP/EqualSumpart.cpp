#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

int dp[101][100001];
class Solution
{
public:

    int solve(int arr[], int n, int sum)
    {
        if (n == 0) return dp[n][sum] = (sum == 0 ? 1 : 0);
        if (sum == 0) return dp[n][sum] = 1;
        if (dp[n][sum] == -1)
        {
            if (arr[n - 1] <= sum)
            {
                return dp[n][sum] = solve(arr, n - 1, sum - arr[n - 1]) + solve(arr, n - 1, sum);
            }
            else return dp[n][sum] = solve(arr, n - 1, sum);
        }
        return dp[n][sum];
    }


    bool findPartition(int arr[], int n)
    {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
        }
        if (sum % 2) return false;
        sum /= 2;
        if (solve(arr, n, sum) != 0) return true;
        return false;

    }
};

//{ Driver Code Starts.
int main() {

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    //taking total testcases
    int tc;
    cin >> tc;
    while (tc--) {

        //taking size of array
        int n, i;
        cin >> n;
        int a[n];

        //inserting elements in the array
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (ob.findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}