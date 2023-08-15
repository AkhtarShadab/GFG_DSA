#include <bits/stdc++.h>

using namespace std;
#define ll long long


#define mod 1000000007
// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // #define ll long long
    ll countStrings(int n) {
        // code here
        vector<pair<ll, ll>> arr(n, {0, 0});
        arr[0] = {1, 1};
        for (int i = 1; i < n; ++i)
        {
            arr[i].first = (arr[i - 1].first + arr[i - 1].second) % mod;
            arr[i].second = arr[i - 1].first;
        }
        return (arr[n - 1].first + arr[n - 1].second) % mod;
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
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0
}
