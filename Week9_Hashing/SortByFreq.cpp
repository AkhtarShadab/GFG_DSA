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
static bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.first > b.first) return true;
	else if (a.first == b.first) {
		if (a.second < b.second) return true;
	}
	return false;
}
vector<int> sortByFreq(int arr[], int n)
{
	//Your code here
	unordered_map<int, int> mp;
	for (int i = 0; i < n; ++i)
	{
		mp[arr[i]]++;
	}
	vector<pair<int, int>> temp ;
	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		temp.push_back(make_pair(i->second, i->first));
	}
	sort(temp.begin(), temp.end(), comp);
	vector<int> ans;
	for (int i = 0; i < temp.size(); ++i)
	{
		for (int j = 0; j < temp[i].first; ++j)
		{
			ans.push_back(temp[i].second);
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
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		vector<int> ans = sortByFreq(a, n);
		for (auto& x : ans)
		{
			cout << x << " ";
		}


	}
	return 0;
}
