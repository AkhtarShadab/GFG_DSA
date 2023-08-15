#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool valid(int x, int y, int n , int m)
    {
        if (x<n and x >= 0 and y<m and y >= 0) return true;
        return false;
    }
    int shortestDistance(int n, int m, vector<vector<int>> A, int X, int Y) {
        // code here
        if (A[0][0] == 0 || A[X][Y] == 0) return -1;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        int dx[4] = { -1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        visited[0][0] = true;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second.first;
            int depth = q.front().second.second;
            q.pop();
            if (x == X and y == Y) return depth;



            for (int i = 0; i < 4; ++i)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (valid(newX, newY, n, m))
                {
                    if (visited[newX][newY] == false and A[newX][newY] == 1)
                    {
                        q.push({newX, {newY, depth + 1}});
                        visited[newX][newY] = true;
                    }
                }
            }
        }
        return -1;

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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}