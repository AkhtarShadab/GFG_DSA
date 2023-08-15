#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s) {

        // your code here
        long long n = s.size();
        long long res = s[0] - '0';
        long long ans[n];
        ans[0] = res;
        for (int i = 1; i < n; ++i)
        {
            ans[i] = ((i + 1) * (s[i] - '0') + 10 * ans[i - 1]) % 1000000007;
            res = (res + ans[i]) % 1000000007;
        }
        return res;

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
    int t;
    cin >> t;
    while (t--)
    {
        //taking string
        string s;
        cin >> s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;

    }
    return 0;
}