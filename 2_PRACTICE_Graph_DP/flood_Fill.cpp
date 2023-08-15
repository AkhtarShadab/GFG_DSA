#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
ll binary_exponentiation(ll a, ll b, ll m)
{
	ll ans = 1;
	while (b)
	{
		if (b % 2 == 1)
		{
			ans = (ans * a) % m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return ans;
}
class Solution {
public:
	bool valid( int x, int y, int n, int m)
	{
		if (x >= 0 and x<n and y >= 0 and y < m)
			return true;
		return false;


	}
	void DFS(vector<vector<int>> &image, vector<vector<bool>> &visited, int x, int y, int color, vector<vector<int>> &sol, int newColor)
	{
		sol[x][y] = newColor;
		visited[x][y] = true;
		int n = image.size();
		int m = image[0].size();
		// cout << x << " " << y << endl;
		int dx[4] = { -1, 0, 1, 0};
		int dy[4] = {0, -1, 0, 1};
		for (int i = 0; i < 4; ++i)
		{
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (valid( newX, newY, n, m))
			{
				if (visited[newX][newY] == false and image[newX][newY] == color)
					DFS(image, visited, newX, newY, color, sol, newColor);
			}
		}
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		// Code here
		int n = image.size();
		int m = image[0].size();
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		vector<vector<int>> sol(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				sol[i][j] = image[i][j];
			}
		}
		DFS(image, visited, sr, sc, image[sr][sc], sol, newColor);

		return sol;
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for (auto i : ans) {
			for (auto j : i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}


