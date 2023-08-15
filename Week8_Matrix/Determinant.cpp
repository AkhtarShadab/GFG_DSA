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
int determinantOfMatrix(vector<vector<int> > matrix, int n)
{
	// code here
	if (n == 1) return matrix[0][0];
	if (n == 2) return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
	int ans = 0;

	for (int i = 0; i < n; ++i)
	{

		vector<vector<int>> arr(n - 1, vector<int>(n - 1));
		for (int j = 1; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if (k < i) arr[j - 1][k] = matrix[j][k];
				else if (k > i) arr[j - 1][k - 1] = matrix[j][k];
				else continue;
			}
		}
		if (i % 2 == 0)ans += matrix[0][i] * determinantOfMatrix(arr, n - 1);
		else ans -= matrix[0][i] * determinantOfMatrix(arr, n - 1);
	}

	return ans;
}
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
		int n;
		cin >> n;
		vector<vector<int>> arr(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> arr[i][j];
			}
		}
		cout << determinantOfMatrix(arr, n);

	}
	return 0;
}
