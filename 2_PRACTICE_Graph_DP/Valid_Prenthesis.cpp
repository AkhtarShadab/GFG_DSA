#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int maxLength(string S) {
        // code here
        stack<char> st1;
        stack<int> st2;
        st2.push(-1);

        int ans = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '(')
            {
                st1.push(S[i]);
                st2.push(i);
            }
            else {
                if (!st1.empty() and st1.top() == '(' )
                {
                    st1.pop();
                    st2.pop();
                    ans = max(ans, i - st2.top());
                }
                else
                {
                    st2.push(i);
                }
            }
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
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}