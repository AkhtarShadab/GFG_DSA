#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr + n);
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int ans = arr[n - 1] - arr[0];
        int largest = arr[n - 1] - k;
        int smallest = arr[0] + k;

        for (int i = 0; i < n - 1; ++i)
        {
            mini = min(smallest, arr[i + 1] - k);
            maxi = max(largest, arr[i] + k);
            if (mini < 0) continue;
            ans  = min(ans, maxi - mini);

        }
        return ans;
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
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}