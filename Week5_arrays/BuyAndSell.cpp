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
vector<vector<int>> stockBuySell(vector<int> arr, int n) {
	// code here
	vector<vector<int>> ans ;
	vector<int> pairsin;
	int check = 0;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > arr[i - 1])
		{
			if (check == 0) {

				pairsin.push_back(i - 1);
				// cout << i - 1 << " ";
			}
			check = 1;
		}
		else {
			if (pairsin.size() == 0) continue;
			else {
				check = 0;
				pairsin.push_back(i - 1);
				// cout << i - 1 << endl;
				ans.push_back(pairsin);
				pairsin.clear();
			}
		}
		if (i == n - 1)
		{
			if (pairsin.size() != 0) {
				pairsin.push_back(n - 1);
				ans.push_back(pairsin);
			}
		}
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
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		// cout << "Hw";
		vector<vector<int>> ans = stockBuySell(arr, n);
		for (auto& row : ans)
		{
			for (auto& col : row)
			{
				cout << col << " " ;
			}
			cout << endl;
		}

	}
	return 0;
}
