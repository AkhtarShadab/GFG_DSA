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
vector<string> winner(string arr[], int n)
{
	// Your code here
	// Return the string containing the name and an integer
	// representing the number of votes the winning candidate got
	unordered_map<string, int> mp;
	for (int i = 0; i < n; ++i)
	{
		mp[arr[i]]++;
	}

	int max = 0;
	string s = "";
	for (auto& X : mp) {
		if (max == X.second)
		{
			string s1 = X.first;
			char *a = &(s1[0]);
			char *b = &(s[0]);
			if (strcmp(a, b ) < 0) {
				s = X.first;
			}
		}
		else if (max < X.second)
		{
			s = X.first;
			max = X.second;
		}
	}
	return {s, to_string(max)};


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
		string arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		vector<string> ans = winner(arr, n);
		cout << ans[0] << " " << ans[1];

	}
	return 0;
}
