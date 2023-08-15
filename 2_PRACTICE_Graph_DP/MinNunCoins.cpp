#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> minPartition(int N)
    {
        // code here
        int arr[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> ans;
        while (N)
        {
            auto it = upper_bound(arr, arr + 10, N);
            it--;
            ans.push_back(*it);
            N -= *it;
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
        int N;
        cin >> N;

        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for (auto u : numbers)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}