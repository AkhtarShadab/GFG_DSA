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
string smallestWindow (string s, string p)
{
	// Your code here
	int val = 0;
	int count[26] = {0};
	for (int i = 0; i < p.size(); ++i)
	{
		if (count[p[i] - 'a'] == 0) val++;
		count[p[i] - 'a']++;
	}
	int anssize = INT_MAX;
	int i = 0, j = 0, start = -1;
	while (j < s.size())
	{


		count[s[j] - 'a']--;
		if (count[s[j] - 'a'] == 0) {
			val--;
		}

		if (val == 0) {
			while (val == 0)
			{
				if (anssize > j - i + 1) {
					start = i;
					anssize = j - i + 1;
				}
				count[s[i] - 'a']++;
				if (count[s[i] - 'a'] == 1)
				{
					val++;
				}
				i++;
			}

		}
		j++;


	}
	if (anssize == INT_MAX) return "-1";
	return s.substr(start, anssize);

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
		string s, p;
		cin >> s;
		getchar();
		cin >> p;
		cout << smallestWindow(s, p);

	}
	return 0;
}
