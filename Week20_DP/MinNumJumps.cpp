#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n) {

        // your code here
        if (n == 1) return 0;
        if (arr[0] == 0 ) return -1;
        int steps = arr[0];
        int maxReac = arr[0];
        int jumps = 1;

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1) return jumps;
            maxReac = max(maxReac, i + arr[i]);
            steps--;
            if (steps == 0)
            {
                jumps++;
                if (i >= maxReac) return -1;
                steps = maxReac - i;
            }
        }



    }
};

//{ Driver Code Starts.
int main()
{
    //taking count of testcases
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {

        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.minimumJumps(arr, n) << endl; // Function to calculate minimum number of jumps
    }
    return 0;
}