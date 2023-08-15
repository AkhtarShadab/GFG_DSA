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
//  If Ration Check then concatenate strings
int strstr(string s, string X)
{
	//Your code here
	if (s.size() < X.size()) return -1;
	for (int i = 0; i <= s.size() - X.size(); ++i)
	{
		string check = "";
		for (int j = i; j < X.size() + i; j++)
		{
			check.push_back(s[j]);
		}
		// cout << check << endl;
		char *s1 = &(X[0]);
		char *s2 = &(check[0]);
		if (strcmp(s1, s2)  == 0) return i;

	}
	return -1;

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
		string s, x;
		cin >> s;
		getchar();
		cin >> x;
		cout << strstr(s, x);
	}
	return 0;
}
