#include <bits/stdc++.h>
#include <climits>
#define endl '\n'
typedef long long ll;
typedef long double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
using namespace std;
long long solve(int index, int arr[], vector<long long>&dp)
{
	if (index == 0) return arr[index];
	if (index < 0) return 0;
	if (dp[index] != -1) return dp[index];

	long long pick = arr[index] + solve(index - 2, arr, dp);
	long long notpick = 0 + solve(index - 1, arr, dp);
	long long only = arr[index];
	return dp[index] = max(pick, max(notpick, only));
}
long long maximumSum(int arr[], int N)
{
	//Your code here
	vector<long long> dp(N, -1);
	dp[0] = arr[0];
	long long ans = solve(N - 1, arr, dp);

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
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cout << maximumSum(arr, n);

	}
	return 0;
}
