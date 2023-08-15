#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
        // your code here
        vector<int> tail;
        int len = 1;
        tail.push_back(arr[0]);
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] > *tail.rbegin())
            {
                tail.push_back(arr[i]);
                len++;
            }
            else {
                auto it = upper_bound(tail.begin(), tail.end(), arr[i]);
                *it = arr[i];
            }
        }
        return len;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}