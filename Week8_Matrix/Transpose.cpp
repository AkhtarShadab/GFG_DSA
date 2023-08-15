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
void transpose(vector<vector<int> >& matrix, int n)
{
	// code here
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}

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
		vector<vector<int>> arr(n);
		for (int i = 0; i < n; ++i)
		{
			vector<int> rows(n);
			for (int j = 0; j < n; ++j)
			{
				cin >> rows[j];
			}
			arr[i] = rows;
		}
		transpose(arr, n);
		for (int i = 0; i < n; ++i)
		{


			for (int j = 0; j < n; ++j)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;

		}
	}
	return 0;
}
