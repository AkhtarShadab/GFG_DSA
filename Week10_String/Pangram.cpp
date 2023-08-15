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
bool checkPangram (string &str) {
	// your code here
	vector<int> small(26), lg(26);
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] - 'a' < 26 && str[i] - 'a' > -1)
		{
			small[str[i] - 'a'] = 1;
		}
		else if (str[i] - 'A' < 26 && str[i] - 'A' > -1)
		{
			lg[str[i] - 'A'] = 1;
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		lg[i] = small[i] || lg[i];
		if (lg[i] != 1)
		{
			return false;
		}
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
		string str;
		cin >> str;
		cout << checkPangram(str);

	}
	return 0;
}
