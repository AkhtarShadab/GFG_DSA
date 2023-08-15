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
bool areIsomorphic(string str1, string str2)
{

	// Your code here
	if (str1.size() != str2.size()) return false;
	unordered_map<char, int> mp;
	unordered_set<int> st;
	for (int i = 0; i < str1.size(); ++i)
	{
		if (mp[str1[i]] == 0) {
			if (st.find(str2[i] - 'a' + 1) != st.end()) return false;
			st.insert(str2[i] - 'a' + 1);
			mp[str1[i]] = str2[i] - 'a' + 1;

		}
		else if (mp[str1[i]] != str2[i] - 'a' + 1) return false;
	}
	return true;

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
		cout << areIsomorphic(s1, s2);


	}
	return 0;
}
