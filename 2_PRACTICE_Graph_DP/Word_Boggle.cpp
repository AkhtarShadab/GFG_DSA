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

vector<string> ans;
class Solution {
public:
	bool valid(int x, int y, int n, int m)
	{
		if (x<n and x >= 0 and y<m and y >= 0) return true;
		return false;

	}
	bool DFS(vector<vector<char>> &board, string S, int x, int y,
	         vector<vector<bool>> &recst, int index)
	{
		if (index == S.length()) return true;
		cout << x << " " << y << endl;
		recst[x][y] = true;
		int n = board.size();
		int m = board[0].size();
		bool flag = false;
		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
				if (i == 0 and j == 0) continue;
				else {
					int newX = x + i;
					int newY = y + j;
					if (valid(newX, newY, n, m)) {
						if (!recst[newX][newY])
						{
							if (S[index] == board[newX][newY])
							{
								flag = DFS(board, S, newX, newY, recst, index + 1);
								if (flag == true) return true;
							}
						}
					}
				}
			}
		}
		recst[x][y] = false;
		return false;

	}
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
		// Code here
		int n = board.size();
		int m = board[0].size();
		int len = dictionary.size();
		for (int i = 0; i < len; ++i)
		{
			string S = dictionary[i];
			char x = dictionary[i][0];
			cout << S << endl;
			vector<vector<bool>> recst(n, vector<bool>(m, false));
			vector<pair<int, int>> check;
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < m; ++k)
				{
					if (board[j][k] == x)
					{
						check.push_back({j, k});
					}
				}
			}
			bool flag = false;
			for (int j = 0; j < check.size(); ++j)
			{
				if (DFS(board, S, check[j].first, check[j].second, recst, 1)) {
					flag = true;
				}
				if (flag)
				{
					break;
				}
			}
			if (flag) ans.push_back(S);
		}
		return ans;

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
		int N;
		cin >> N;
		vector<string> dictionary;
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			dictionary.push_back(s);
		}

		int R, C;
		cin >> R >> C;
		vector<vector<char> > board(R);
		for (int i = 0; i < R; i++) {
			board[i].resize(C);
			for (int j = 0; j < C; j++) cin >> board[i][j];
		}
		Solution obj;
		vector<string> output = obj.wordBoggle(board, dictionary);
		if (output.size() == 0)
			cout << "-1";
		else {
			sort(output.begin(), output.end());
			for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
		}
		cout << endl;

	}
	return 0;
}
