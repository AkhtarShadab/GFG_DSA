#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
long long numOfWays(int n, int m);
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{	int n, m;
		cin >> n >> m;
		cout << numOfWays(n, m) << endl;

	}
	return 0;
}


void solve(int N, int M, int i, int j, long long &ans)
{
	int dux[4] = { -1, -2, -2, -1};
	int dy[4] = { -2, -1, 1, 2};
	int ddx[4] = {1, 2, 2, 1};
	long long count = 0;
	for (int k = 0; k < 4; ++k)
	{
		if (i + dux[k] < N and i + dux[k] >= 0 and j + dy[k] < M and j + dy[k] >= 0) count++;
		if (i + ddx[k] < N and i + ddx[k] >= 0 and j + dy[k] < M and j + dy[k] >= 0) count++;
	}
	count++;
	ans += N * M - count;
}

long long numOfWays(int N, int M)
{
	// write code here
	long long ans =  0;
	long long util = (long long)N * M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			solve(N, M, i, j, ans);
		}
	}
	return ans % mod;
}