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
string concatenatedString(string s1, string s2)
{
	// Your code here
	vector<int> arr1(26), arr2(26);
	for (int i = 0; i < s1.size(); ++i)
	{
		arr1[s1[i] - 'a'] = 1;
	}
	for (int i = 0; i < s2.size(); ++i)
	{
		arr2[s2[i] - 'a'] = 1;
	}
	string ans;
	for (int i = 0; i < 26; ++i)
	{
		arr1[i] = arr1[i] & arr2[i];
	}
	for (int i = 0; i < s1.size(); ++i)
	{
		if (arr1[s1[i] - 'a'] != 1)
		{
			ans.push_back(s1[i]);

		}
	}
	for (int i = 0; i < s2.size(); ++i)
	{
		if (arr1[s2[i] - 'a'] != 1)
		{
			ans.push_back(s2[i]);

		}
	}
	if (ans.size() == 0) return "-1";
	return ans;
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
		string s1, s2;
		cin >> s1;
		getchar();
		cin >> s2;
		s1 = concatenatedString(s1, s2);
		cout << s1;

	}
	return 0;
}
