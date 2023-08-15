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
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
	vector<int> ans;
	int p1 = 0, p2 = 0;
	while (p1 < n || p2 < m)
	{
		if (p1 == n)
		{
			if (p2 != 0 && arr2[p2] == arr2[p2 - 1])
			{
				p2++;
			}
			else {
				ans.push_back(arr2[p2]);
				p2++;
			}
		}
		else if (p2 == m)
		{
			if (p1 != 0 && arr1[p1] == arr1[p1 - 1])
			{
				p1++;
			}
			else {
				ans.push_back(arr1[p1]);
				p1++;
			}
		}
		else {
			if (p1 != 0 && arr1[p1] == arr1[p1 - 1])
			{
				p1++; continue;
			}
			if (p2 != 0 && arr2[p2] == arr2[p2 - 1])
			{
				p2++; continue;
			}
			if (arr1[p1] < arr2[p2])
			{
				ans.push_back(arr1[p1]);
				p1++;
			}
			else if (arr1[p1] > arr2[p2])
			{
				ans.push_back(arr2[p2]);
				p2++;
			}
			else {
				ans.push_back(arr1[p1]);
				p1++;
				p2++;
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
		vector<int> ans = findUnion(a, b, n, m);
		for (auto x : ans)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
