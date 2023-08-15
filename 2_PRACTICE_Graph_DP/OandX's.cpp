
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// X= false, O = True;

int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, -1,  0, 1};
class Solution {
public:
    bool valid(int x , int y, int n , int m)
    {
        if (x<n and x >= 0 and y<m and y >= 0) return true;
        return false;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            if (mat[i][0] == 'O') {
                q.push({i, 0});
                visited[i][0] = true;
            }
            if (mat[i][m - 1] == 'O') {
                q.push({i, m - 1});
                visited[i][m - 1] = true;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            if (mat[0][i] == 'O')
            {
                q.push({0, i}); visited[0][i] = true;
            }
            if (mat[n - 1][i] == 'O')
            {
                q.push({n - 1, i});
                visited[n - 1][i] = true;
            }
        }
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (valid(newX, newY, n, m))
                {
                    if (visited[newX][newY] == false and mat[newX][newY] == 'O')
                    {
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
        }
        vector<vector<char>> ans(n, vector<char>(m, 'X'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; ++j)
            {
                if (visited[i][j] == true)
                {
                    ans[i][j] = 'O';
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return