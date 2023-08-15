#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
public:
    int maxArea(vector<vector<int>> &M, int n, int m) {
        // Your code here
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (M[i][j]) M[i][j] += M[i - 1][j];
                // cout << M[i][j] << " ";
            }
            // cout << endl;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            stack<int> prevG, nextG;
            vector<int> PG, NG;
            PG.push_back(-1);
            NG.push_back(m);
            prevG.push(0);
            nextG.push(m - 1);
            for (int j = 1; j < m; j++)
            {
                while (!prevG.empty() and M[i][j] <= M[i][prevG.top()]) {
                    prevG.pop();
                }
                int curr = prevG.empty() ? -1 : prevG.top();
                prevG.push(j);

                PG.push_back(curr);
            }
            for (int j = m - 2; j > -1; --j)
            {
                while (!nextG.empty() and M[i][j] <= M[i][nextG.top()])
                {
                    nextG.pop();
                }
                int curr = nextG.empty() ? m : nextG.top();
                nextG.push(j);
                NG.push_back(curr);
            }
            for (int j = 0; j < m / 2; ++j)
            {
                swap(NG[j], NG[m - j - 1]);
            }
            // for (int j = 0; j < m; ++j)
            // {
            //     cout << PG[j] << " ";
            // }
            for (int j = 0; j < m; ++j)
            {
                ans = max(ans, (NG[j] - PG[j] - 1) * M[i][j]);
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
    int T;
    cin >> T;



    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];

            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}