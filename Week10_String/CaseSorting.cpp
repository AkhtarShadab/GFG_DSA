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
string caseSort(string str, int n)
{
	// your code here
	int countsm = 0;
	vector<int> check(n);
	for (int i = 0; i < n; ++i)
	{
		if (-1 < str[i] - 'a' && str[i] - 'a' < 26) check[i] = 0;
		else {
			check[i] = 1; countsm++;
		}
	}

	int countlg = 0;
	sort(str.begin(), str.end());

	string ans;
	for (int i = 0; i < n; ++i)
	{
		if (check[i] == 0)
		{
			ans.push_back(  str[countsm]);
			countsm++;
		}
		else {
			ans.push_back(  str[countlg]);
			countlg++;
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
		getchar();
		string s;
		cin >> s;
		cout << caseSort(s, n);

	}
	return 0;
}
