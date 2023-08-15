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
vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
{
	//Your code here
	unordered_map<int, int> mp;
	for (int i = 0; i < N; ++i)
	{
		mp[A1[i]]++;
	}
	vector<int> ans, temp;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < mp[A2[i]]; ++j)
		{
			ans.push_back(A2[i]);
		}
		mp.erase(A2[i]);
	}
	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		for (int j = 0; j < i->second; ++j)
		{
			temp.push_back(i->first);
		}
	}
	sort(temp.begin(), temp.end());
	for (auto& x : temp) {
		ans.push_back(x);
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
		vector<int> a(n), b(m);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> b[i];
		}
		vector<int> ans = sortA1ByA2(a, n, b, m);
		for (auto& x : ans)
		{
			cout << x << " ";
		}


	}
	return 0;
}
