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

vector<vector<int>> separateChaining(int hashSize, int arr[], int sizeOfArray)
{
	//Your code here
	vector<vector<int>> ans(hashSize);
	for (int i = 0; i < sizeOfArray; ++i)
	{
		int key = (arr[i]) % hashSize;
		ans[key].push_back(arr[i]);

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
		int n, m;
		cin >> m >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		vector<vector<int>> ans = separateChaining(m, a, n);
		for (auto& x : ans)
		{
			for (auto& y : x)
			{
				cout << y << " ";
			}
			cout << endl;
		}

	}
	return 0;
}
