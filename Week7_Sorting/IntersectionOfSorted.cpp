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
vector<int> prinIntersection(int arr1[], int arr2[], int N, int M)
{
	vector<int> ans;
	int i = 0;
	int j = 0;
	while (i < N && j < M)
	{
		if (i != 0 && arr1[i] == arr1[i - 1]) {i++; continue;}

		if (arr1[i] > arr2[j]) j++;
		else if (arr1[i] < arr2[j]) i++;
		else {
			ans.push_back(arr1[i]);
			i++;
			j++;
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
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> b[i];
		}
		vector<int> ans = prinIntersection(a, b, n, m);
		for (auto x : ans)
		{
			cout << x << " ";
		}

	}
	return 0;
}
