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
vector <int> findPairs(int arr[], int n)
{
	// code here
	unordered_set<int> st;
	vector<int> ans;
	for (int i = 0; i < n; ++i)
	{

		if (arr[i] != 0)st.insert(arr[i]);


		if (st.count(-arr[i])) {
			if (arr[i] > 0)
			{
				ans.push_back(-arr[i]);
				ans.push_back(arr[i]);
			}
			else
			{
				ans.push_back(arr[i]);
				ans.push_back(-arr[i]);
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
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		vector<int> ans = findPairs(arr, n);
		for (auto& X : ans)
		{
			cout << X << " ";
		}

	}
	return 0;
}
